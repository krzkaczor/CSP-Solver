//
// Created by Krzysztof Kaczor on 4/11/15.
//

#ifndef CSP_STACKMACHINE_H
#define CSP_STACKMACHINE_H
class StackMachine;

#include <vector>
#include <stack>
#include "Expression.h"
#include "../csp_problem/Environment.h"

class StackMachine {
public:
    StackMachine(std::vector<OperandPtr> operands);
    boost::optional<bool> eval(Environment& environment);

    std::string describe();

private:
    std::vector<OperandPtr> stack;
};


#endif //CSP_STACKMACHINE_H
