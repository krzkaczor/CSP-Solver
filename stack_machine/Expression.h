//
// Created by Krzysztof Kaczor on 4/11/15.
//

#ifndef CSP_OPERAND_H
#define CSP_OPERAND_H

#include <memory>
#include <vector>
#include <boost/optional/optional.hpp>

class Expression;
#include "../csp_problem/Environment.h"
typedef Expression * OperandPtr;
typedef std::vector<OperandPtr>::reverse_iterator& StackIt;

class Expression {
public:
    //TODO: should be variant with blank type
    //typedef boost::variant<boost::blank, int, std::string> Empty;
    virtual boost::optional<domain_element> eval(StackIt it, Environment& environment) = 0;
    virtual std::string describe() = 0;
};


#endif //CSP_OPERAND_H
