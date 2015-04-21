//
// Created by Krzysztof Kaczor on 4/3/15.
//

#ifndef CSP_CSPPROBLEMDEFINITION_H
#define CSP_CSPPROBLEMDEFINITION_H

#include <string>
#include <vector>
#include <boost/fusion/adapted/struct/adapt_struct.hpp>
#include <boost/variant/variant.hpp>
#include "OperatorToken.h"
#include "IdentificationToken.h"
#include "../defs.h"

typedef boost::variant<int, std::string, IdentificationToken, OperatorToken> constraint;

struct CspProblemDefinition {
    std::vector<IdentificationToken> variables;
    std::vector<std::vector<domain_element>> domains;
    std::vector<std::vector<constraint>> constraints;
};

BOOST_FUSION_ADAPT_STRUCT(CspProblemDefinition,
    (std::vector<IdentificationToken>, variables)
    (std::vector<std::vector<domain_element>>, domains)
    (std::vector<std::vector<constraint>>, constraints)
)


#endif //CSP_CSPPROBLEMDEFINITION_H
