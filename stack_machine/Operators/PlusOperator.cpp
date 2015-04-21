//
// Created by Krzysztof Kaczor on 4/11/15.
//

#include "PlusOperator.h"
#include "../../utils/utils.h"

boost::optional<domain_element> PlusOperator::eval(StackIt stack, Environment &environment) {
    auto a = topAndPop(stack)->eval(stack, environment);
    if (!a) return boost::none;
    auto b = topAndPop(stack)->eval(stack, environment);
    if (!b) return boost::none;
    return boost::optional<domain_element>(boost::get<int>(a.get()) + boost::get<int>(b.get()));
}
