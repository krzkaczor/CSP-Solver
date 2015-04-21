//
// Created by Krzysztof Kaczor on 4/11/15.
//

#include "VariableReference.h"
#include "IntLiteral.h"

#include <iostream>

VariableReference::VariableReference(std::string name) : name(name) { }


boost::optional<domain_element> VariableReference::eval(StackIt stack, Environment &environment) {
    auto varIt = environment.find(name);
    if (!varIt->second.hasValue()) {
        return boost::none;
    }
    return boost::optional<domain_element>(varIt->second.getValue());
}
