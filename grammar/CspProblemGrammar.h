//
// Created by Krzysztof Kaczor on 4/2/15.
//

#ifndef CSP_CSPPROBLEMGRAMMAR_H
#define CSP_CSPPROBLEMGRAMMAR_H

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <string>
#include <vector>
#include "CspProblemDefinition.h"
#include "OperatorToken.h"
#include "IdentificationToken.h"

namespace csp {
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;
    namespace fusion = boost::fusion;
    namespace phoenix = boost::phoenix;

    struct CspProblemGrammar : qi::grammar<std::string::const_iterator, CspProblemDefinition(), qi::locals<int>, ascii::blank_type> {
        CspProblemGrammar() : base_type(start) {
            using qi::eol;
            using qi::int_;
            using qi::eps;
            using qi::lit;
            using qi::_val;
            using qi::_1;
            using qi::repeat;
            using qi::space;
            using qi::lexeme;
            using ascii::char_;
            using ascii::string;
            namespace phx = boost::phoenix;
            using phoenix::push_back;
            using namespace qi::labels;


            string_ %= +(char_ - space  - "'" - eol);
            oper %= string_ [phx::at_c<0>(_val) = _1];
            ident_str %= char_("a-zA-Z") >> *string_;
            ident %= ident_str [phx::at_c<0>(_val) = _1];
            string_literal %= "'" >> string_  >> "'";

            start %= eps[_a = 0] >>
                     +(ident)[_a++] >> eol >>
                     repeat(_a)[+(int_ | string_literal) >> eol] >>
                     +(+(int_ | string_literal | ident | oper) >> eol)
                    ;
        }
        qi::rule<std::string::const_iterator, std::string()> string_;
        qi::rule<std::string::const_iterator, std::string()> string_literal;
        qi::rule<std::string::const_iterator, OperatorToken()> oper;
        qi::rule<std::string::const_iterator, IdentificationToken()> ident;
        qi::rule<std::string::const_iterator, std::string()> ident_str;
        qi::rule<std::string::const_iterator, CspProblemDefinition(), qi::locals<int>, ascii::blank_type> start;
    };

}

#endif //CSP_CSPPROBLEMGRAMMAR_H
