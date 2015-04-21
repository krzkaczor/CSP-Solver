//
// Created by Krzysztof Kaczor on 4/10/15.
//

#ifndef CSP_VARIABLE_H
#define CSP_VARIABLE_H

#include <string>
#include <list>
#include <vector>
class Variable;
#include "../grammar/CspProblemDefinition.h"

class Variable {
public:
    Variable(std::string variableName, std::list<domain_element> domain);
    Variable(Variable&& other);
    Variable(const Variable&);
    Variable& operator=(const Variable&) = delete;

    domain_element getValue();
    bool hasValue() const;
    void setValue(domain_element newValue);

    void nextValueFromDomain();
    bool hasNextValueFromDomain();
    void reset();
    std::string variableName;

    std::list<domain_element> domain;
    domain_element value;
    bool _hasValue = false;
    std::list<domain_element>::iterator nextValueFromDomainIterator;
};


#endif //CSP_VARIABLE_H
