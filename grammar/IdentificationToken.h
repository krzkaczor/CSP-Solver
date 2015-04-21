//
// Created by Krzysztof Kaczor on 4/18/15.
//

#ifndef CSP_INDENTIFICATORTOKEN_H
#define CSP_INDENTIFICATORTOKEN_H

#include <string>
#include <boost/fusion/adapted/struct/adapt_struct.hpp>

struct IdentificationToken {
    std::string token;
};

BOOST_FUSION_ADAPT_STRUCT(IdentificationToken,(std::string, token))



#endif //CSP_INDENTIFICATORTOKEN_H
