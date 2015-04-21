//
// Created by Krzysztof Kaczor on 4/19/15.
//

#ifndef CSP_SUBSCRIPTOPERATOR_H
#define CSP_SUBSCRIPTOPERATOR_H

#include <string>
#include "../Expression.h"

class SubscriptOperator : public Expression {
    virtual boost::optional<domain_element> eval(StackIt stack, Environment& environment) override;

    virtual std::string describe() override {
        return "[]";
    };
};


#endif //CSP_SUBSCRIPTOPERATOR_H
