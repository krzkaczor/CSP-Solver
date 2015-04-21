//
// Created by Krzysztof Kaczor on 4/11/15.
//

#include <iostream>
#include "EqualityOperator.h"
#include "../IntLiteral.h"
#include "../../utils/utils.h"

boost::optional<domain_element> EqualityOperator::eval(StackIt stack, Environment &environment) {
    auto a = topAndPop(stack)->eval(stack, environment);
    if (!a) {
        return boost::none;
    }
    auto b = topAndPop(stack)->eval(stack, environment);
    if (!b) {
        return boost::none;
    }

    auto lhs = a.get();
    auto rhs = b.get();

    if (lhs.type() == typeid(int)) {
        return boost::optional<domain_element>(boost::get<int>(lhs) == boost::get<int>(rhs));
    }

    if (lhs.type() == typeid(std::string)) {
        return boost::optional<domain_element>(boost::get<std::string>(lhs) == boost::get<std::string>(rhs));
    }

    if (lhs.type() == typeid(bool)) {
        return boost::optional<domain_element>(boost::get<bool>(lhs) == boost::get<bool>(rhs));
    }
}
