//
// Created by Krzysztof Kaczor on 4/19/15.
//

#ifndef CSP_STRINGLITERAL_H
#define CSP_STRINGLITERAL_H


#include "Expression.h"

class StringLiteral : public Expression {
public:
    StringLiteral(std::string value);
    virtual boost::optional<domain_element> eval(StackIt& it, Environment& environment);
    std::string value;

    virtual std::string describe() override {
        return value;
    };

};


#endif //CSP_STRINGLITERAL_H
