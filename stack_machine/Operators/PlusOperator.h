//
// Created by Krzysztof Kaczor on 4/11/15.
//

#ifndef CSP_PLUSOPERATOR_H
#define CSP_PLUSOPERATOR_H


#include "../Expression.h"

class PlusOperator : public Expression {
    virtual boost::optional<domain_element> eval(StackIt stack, Environment& environment) override;

    virtual std::string describe() override {
        return "+";
    };
};


#endif //CSP_PLUSOPERATOR_H
