//
// Created by Krzysztof Kaczor on 4/13/15.
//

#include "MinusOperator.h"
#include "../IntLiteral.h"
#include "../../utils/utils.h"

boost::optional<domain_element> MinusOperator::eval(StackIt stack, Environment &environment) {
    auto a = topAndPop(stack)->eval(stack, environment);
    if (!a) return boost::none;
    auto b = topAndPop(stack)->eval(stack, environment);
    if (!b) return boost::none;
    return boost::optional<domain_element>(boost::get<int>(a.get()) - boost::get<int>(b.get()));
}
