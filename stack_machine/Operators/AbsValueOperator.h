//
// Created by Krzysztof Kaczor on 4/13/15.
//

#ifndef CSP_ABSVALUEOPERATOR_H
#define CSP_ABSVALUEOPERATOR_H


#include "../Expression.h"

class AbsValueOperator : public Expression {
        virtual boost::optional<domain_element> eval(StackIt stack, Environment& environment) override;

        virtual std::string describe() override {
            return "||";
        };
    };


#endif //CSP_ABSVALUEOPERATOR_H
