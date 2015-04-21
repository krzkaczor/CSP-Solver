//
// Created by Krzysztof Kaczor on 4/13/15.
//

#ifndef CSP_INEQUALITYOPERATOR_H
#define CSP_INEQUALITYOPERATOR_H


#include "../Expression.h"
#include "../../csp_problem/Environment.h"

class InequalityOperator : public Expression {
    virtual boost::optional<domain_element> eval(StackIt stack, Environment& environment) override;

    virtual std::string describe() override {
        return "!=";
    };
};


#endif //CSP_INEQUALITYOPERATOR_H
