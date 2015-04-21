//
// Created by Krzysztof Kaczor on 4/13/15.
//

#ifndef CSP_MINUSOPERATOR_H
#define CSP_MINUSOPERATOR_H


#include "../Expression.h"

class MinusOperator : public Expression {
    virtual boost::optional<domain_element> eval(StackIt stack, Environment& environment) override;

    virtual std::string describe() override {
        return "-";
    };
};


#endif //CSP_MINUSOPERATOR_H
