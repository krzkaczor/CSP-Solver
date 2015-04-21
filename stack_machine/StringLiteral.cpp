//
// Created by Krzysztof Kaczor on 4/19/15.
//

#include "StringLiteral.h"

StringLiteral::StringLiteral(std::string value) {
    this->value = value;
}

boost::optional<domain_element> StringLiteral::eval(StackIt &it, Environment &environment) {
    return boost::optional<domain_element>(domain_element(value));
}
