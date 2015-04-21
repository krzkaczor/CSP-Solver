//
// Created by Krzysztof Kaczor on 4/11/15.
//

#ifndef CSP_BACKTRACKINGSOLVER_H
#define CSP_BACKTRACKINGSOLVER_H


#include "../csp_problem/CspProblem.h"
#include "Solver.h"
#include <boost/optional.hpp>

typedef Environment::iterator EnvIt;

class BacktrackingSolver : public Solver {
public:
    BacktrackingSolver(bool findAll);
    virtual std::vector<Environment> solve(CspProblem& problem) override;

private:
    std::vector<StackMachine>* constraintMachines;
    bool backtracking(Environment&,const EnvIt&);
    long int counter;
};


#endif //CSP_BACKTRACKINGSOLVER_H
