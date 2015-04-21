//
// Created by Krzysztof Kaczor on 4/18/15.
//

#include "GroupInequalityOperator.h"
#include "../../utils/utils.h"
#include <set>
#include <unordered_set>

using namespace std;

boost::optional<domain_element> GroupInequalityOperator::eval(StackIt stack, Environment &environment) {
    auto  t_numberOfElements = topAndPop(stack)->eval(stack, environment);
    if (!t_numberOfElements)
        return boost::none;
    int numberOfElements = boost::get<int>(t_numberOfElements.get());
    unordered_set<int> differentInts;

    while(numberOfElements-- > 0) {
        auto t_result = topAndPop(stack)->eval(stack, environment);
        if (!t_result)
            return boost::none;

        int result = boost::get<int>(t_result.get());
        if (contains(differentInts, result)) {
            return boost::optional<domain_element>(false);
        } else {
            differentInts.insert(result);
        }
    }

    return boost::optional<domain_element>(true);
}
