//
// Created by Krzysztof Kaczor on 4/11/15.
//

#ifndef CSP_VARIABLEREFERENCE_H
#define CSP_VARIABLEREFERENCE_H

#include <string>
#include "Expression.h"

class VariableReference : public Expression {
public:
    VariableReference(std::string name);
    virtual boost::optional<domain_element> eval(StackIt stack, Environment& environment) override;

    virtual std::string describe() override {
        return name;
    };
    std::string name;
};


#endif //CSP_VARIABLEREFERENCE_H
