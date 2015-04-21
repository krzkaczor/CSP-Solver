//
// Created by Krzysztof Kaczor on 4/11/15.
//

#ifndef CSP_EQUALITYOPERATOR_H
#define CSP_EQUALITYOPERATOR_H


#include "../Expression.h"

class EqualityOperator : public Expression {
    virtual boost::optional<domain_element> eval(StackIt stack, Environment& environment) override;

    virtual std::string describe() override {
        return "==";
    };
};


#endif //CSP_EQUALITYOPERATOR_H
