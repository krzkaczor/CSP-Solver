//
// Created by Krzysztof Kaczor on 4/19/15.
//

#include "SubscriptOperator.h"
#include "../../utils/utils.h"

boost::optional<domain_element> SubscriptOperator::eval(StackIt stack, Environment &environment) {
    auto index_o = topAndPop(stack)->eval(stack, environment);
    if (!index_o)
        return boost::none;

    auto str_o = topAndPop(stack)->eval(stack, environment);
    if (!str_o)
        return boost::none;

    auto index = boost::get<int>(index_o.get());
    auto str = boost::get<std::string>(str_o.get());

    return boost::optional<domain_element>(str.substr(index, 1));
}
