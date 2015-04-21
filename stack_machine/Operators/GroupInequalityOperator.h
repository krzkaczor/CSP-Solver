//
// Created by Krzysztof Kaczor on 4/18/15.
//

#ifndef CSP_GROUPINEQUALITYOPERATOR_H
#define CSP_GROUPINEQUALITYOPERATOR_H


#include "../Expression.h"

class GroupInequalityOperator : public Expression {
    virtual boost::optional<domain_element> eval(StackIt stack, Environment& environment) override;

    virtual std::string describe() override {
        return "!!";
    };

};


#endif //CSP_GROUPINEQUALITYOPERATOR_H
