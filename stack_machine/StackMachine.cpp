//
// Created by Krzysztof Kaczor on 4/11/15.
//

#include <iostream>
#include "StackMachine.h"
#include "../utils/utils.h"
#include "VariableReference.h"

using namespace std;

StackMachine::StackMachine(std::vector<OperandPtr> operands) : stack(move(operands)) {
}

boost::optional<bool> StackMachine::eval(Environment& environment) {
    std::vector<OperandPtr>::reverse_iterator it = stack.rbegin();
    auto result = (topAndPop(it)->eval(it, environment));
    if (!result)
        return boost::none;
    else
        return boost::get<bool>(result.get());
}

std::string StackMachine::describe() {
    if (stack.empty()) {
        return "Empty stack machine";
    }

    string operandDescription = accumulate(stack.begin()+1, stack.end(), stack[0]->describe(), [](string& a, OperandPtr& operand) {
        return a + " -> " + operand->describe();
    });

    return operandDescription + "\n";
}