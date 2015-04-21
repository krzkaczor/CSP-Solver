//
// Created by Krzysztof Kaczor on 4/13/15.
//

#ifndef CSP_FORWARDCHECKINGSOLVER_H
#define CSP_FORWARDCHECKINGSOLVER_H


#include "Solver.h"

typedef Environment::iterator EnvIt;

class ForwardCheckingSolver : public Solver {
public:
    ForwardCheckingSolver(bool findAll);
    virtual std::vector<Environment> solve(CspProblem& problem) override;

private:
    std::vector<StackMachine>* constraintMachines;
    bool forwardChecking(Environment&, const EnvIt&);
    void retrieveDomainElements(Environment& state, EnvIt fcIt, list<list<pair<int, domain_element>>>& buffer);
};


#endif //CSP_FORWARDCHECKINGSOLVER_H
