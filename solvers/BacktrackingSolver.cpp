//
// Created by Krzysztof Kaczor on 4/11/15.
//

#include "BacktrackingSolver.h"
#include "../utils/utils.h"


std::vector<Environment> BacktrackingSolver::solve(CspProblem& problem) {
    counter = 0;
    this->constraintMachines = &problem.constraintMachines;
    this->backtracking(problem.environment, problem.environment.begin());
    return solutions;
}

bool BacktrackingSolver::backtracking(Environment& state, const EnvIt& envIt)  {
    counter++;

    auto result = evaluateMachines(*constraintMachines, state);

    if (result) {
        if (result.get()) {
            solutions.push_back(state);
            return true;
        } else {
            return false;
        }
    }

    auto nextIt = ++EnvIt(envIt);
    while(envIt->second.hasNextValueFromDomain()) {
        envIt->second.nextValueFromDomain();

        if (backtracking(state, nextIt) && !findAll)
            return true;

        if (nextIt != state.end()) {
            nextIt->second.reset();
        }
    }
    return false;
}

BacktrackingSolver::BacktrackingSolver(bool findAll) : Solver(findAll) { }
