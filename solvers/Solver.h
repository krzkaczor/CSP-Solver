//
// Created by Krzysztof Kaczor on 4/13/15.
//

#ifndef CSP_SOLVER_H
#define CSP_SOLVER_H

#include "../csp_problem/CspProblem.h"

class Solver {
public:
    Solver(bool findAll) : findAll(findAll) {}// solutions = std::list<Environment>(); }
    virtual std::vector<Environment> solve(CspProblem& problem) = 0;

protected:
    bool findAll = 0;

    std::vector<Environment> solutions;

    int counter = 0;

    boost::optional<bool> evaluateMachines(vector<StackMachine>& constraintMachines, Environment& state) {
        bool accept = true;
        for (auto& machine : constraintMachines) {
            auto evalResult = machine.eval(state);
            if (evalResult) {
                if(!evalResult.get()) {
                    return boost::optional<bool>(false);
                }
            } else {
                accept = false;
            }
        }
        return accept? boost::optional<bool>(true) : boost::none;
    }
};


#endif //CSP_SOLVER_H

