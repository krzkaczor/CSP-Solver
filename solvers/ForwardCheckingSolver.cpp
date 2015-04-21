//
// Created by Krzysztof Kaczor on 4/13/15.
//

#include "ForwardCheckingSolver.h"
#include "../utils/utils.h"

std::vector<Environment> ForwardCheckingSolver::solve(CspProblem& problem) {
    counter = 0;
    constraintMachines = &problem.constraintMachines;
    forwardChecking(problem.environment, problem.environment.begin());
    return solutions;
}


bool ForwardCheckingSolver::forwardChecking(Environment &state, const EnvIt& envIt) {
    counter++;

    list<list<pair<int, domain_element>>> buffer;
    bool reject = false;
    bool accept = false;
    //forward checking
    //check all values of all other variables
    auto fcIt = EnvIt(envIt);
    while(fcIt != state.end() && !reject) {
        list<pair<int, domain_element>> currentVarBuf;
        Variable& var = fcIt->second;
        int index = -1;
        while (var.hasNextValueFromDomain()) {
            index++;
            var.setValue(*var.nextValueFromDomainIterator);

            auto result = evaluateMachines(*constraintMachines, state);

            if (result && !result.get()) {
                currentVarBuf.push_back(make_pair(index, *var.nextValueFromDomainIterator));
                var.domain.erase(var.nextValueFromDomainIterator++);
                if (var.nextValueFromDomainIterator != var.domain.end()) {
                    var.setValue(*var.nextValueFromDomainIterator);
                }
            } else {
                var.nextValueFromDomain();

            }
        }
        if (var.domain.empty()) {
            reject = true;
        }
        buffer.push_back(currentVarBuf);
        var.reset();
        fcIt++;
    }
    if (!reject) {
        auto result = evaluateMachines(*constraintMachines, state);

        if (!result) {
            auto nextIt = ++EnvIt(envIt);
            while (envIt->second.hasNextValueFromDomain()) {
                envIt->second.nextValueFromDomain();

                if (forwardChecking(state, nextIt) && !findAll) {
                    retrieveDomainElements(state, EnvIt(envIt), buffer);
                    return true;
                }

                if (nextIt != state.end()) {
                    nextIt->second.reset();
                }
            }
        } else {
            if (result.get()) {
                solutions.push_back(state);
                accept = true;
            } else {
                assert(false);
            }
        }
    }

    retrieveDomainElements(state, EnvIt(envIt), buffer);

    return accept;
}

ForwardCheckingSolver::ForwardCheckingSolver(bool findAll) : Solver(findAll) { }

void ForwardCheckingSolver::retrieveDomainElements(Environment& state, EnvIt fcIt, list<list<pair<int, domain_element>>>& buffer) {
    while(fcIt != state.end()) {
        if (buffer.empty())
            return;
        list<pair<int, domain_element>>& currentVarBuf = buffer.front();
        Variable& var = fcIt->second;
        int index = 0;

        if (!currentVarBuf.empty()) {
            while (var.hasNextValueFromDomain() || !currentVarBuf.empty()) {

                if (index == currentVarBuf.front().first) {
                    var.domain.insert(var.nextValueFromDomainIterator, currentVarBuf.front().second);
                    currentVarBuf.pop_front();
                } else {
                    var.nextValueFromDomain();
                }
                index++;
            }
        }

        buffer.pop_front();
        var.reset();
        fcIt++;
    }
}