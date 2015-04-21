//
// Created by Krzysztof Kaczor on 4/10/15.
//

#include <assert.h>
#include <iostream>
#include "Variable.h"

using namespace std;

Variable::Variable(std::string variableName, std::list<domain_element> domain) : variableName(variableName), domain(domain) { reset(); }


Variable::Variable(Variable&& other) : variableName(move(other.variableName)), domain(std::move(other.domain)) {
    reset();
}

domain_element Variable::getValue() {
    if (!_hasValue) {
        throw exception();
    }
    return value;
}

void Variable::setValue(domain_element newValue) {
    _hasValue = true;
    value = newValue;
}

void Variable::nextValueFromDomain() {
    if (hasNextValueFromDomain()) {
        setValue(*nextValueFromDomainIterator);
        nextValueFromDomainIterator++;
    }
}

bool Variable::hasNextValueFromDomain() {
    return nextValueFromDomainIterator != domain.end();
}

bool Variable::hasValue() const {
    return _hasValue;
}

void Variable::reset() {
    _hasValue = false;
    nextValueFromDomainIterator = domain.begin();
}

Variable::Variable(Variable const &other) {
    this->value = other.value;
    this->_hasValue = other._hasValue;
}
