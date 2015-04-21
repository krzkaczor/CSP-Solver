//
// Created by Krzysztof Kaczor on 4/11/15.
//

#ifndef CSP_INTVALUE_H
#define CSP_INTVALUE_H


#include "Expression.h"

class IntLiteral : public Expression {
public:
    IntLiteral(int value);
    virtual boost::optional<domain_element> eval(StackIt& it, Environment& environment);
    int value;

    virtual std::string describe() override {
        return std::to_string(value);
    };
};


#endif //CSP_INTVALUE_H
