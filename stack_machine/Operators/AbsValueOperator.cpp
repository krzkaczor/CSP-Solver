//
// Created by Krzysztof Kaczor on 4/13/15.
//

#include "AbsValueOperator.h"
#include "../IntLiteral.h"
#include "../../utils/utils.h"

boost::optional<domain_element> AbsValueOperator::eval(StackIt stack, Environment &environment) {
    auto a = topAndPop(stack)->eval(stack, environment);
    if (!a) {
        return boost::none;
    }
    return boost::optional<domain_element>(abs(boost::get<int>(a.get())));
}
