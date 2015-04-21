//
// Created by Krzysztof Kaczor on 4/11/15.
//

#ifndef CSP_OPERANDFACTORY_H
#define CSP_OPERANDFACTORY_H

#include <iostream>
#include "Operators/GroupInequalityOperator.h"
#include "../grammar/OperatorToken.h"
#include "Expression.h"
#include "VariableReference.h"
#include "Operators/PlusOperator.h"
#include "Operators/EqualityOperator.h"
#include "IntLiteral.h"
#include "StringLiteral.h"
#include "Operators/InequalityOperator.h"
#include "Operators/MinusOperator.h"
#include "Operators/AbsValueOperator.h"
#include "Operators/SubscriptOperator.h"

using namespace std;

struct ExpressionFactory : public boost::static_visitor<OperandPtr>
{
    OperandPtr operator()(OperatorToken ot) const {
        string opToken = ot.token;

        Expression * oper = nullptr;
        if (opToken == "+") {
            oper = new PlusOperator();
        } else if (opToken == "-") {
            oper = new MinusOperator();
        } else if (opToken == "==") {
            oper = new EqualityOperator();
        } else if (opToken == "!=") {
            oper = new InequalityOperator();
        } else if (opToken == "||") {
            oper = new AbsValueOperator();
        } else if (opToken == "!!") {
            oper = new GroupInequalityOperator();
        } else if (opToken == "[]") {
            oper = new SubscriptOperator();
        } else {
            cout <<  "FAIL: " << ot.token << endl;
            assert(false);
        }
        return OperandPtr{oper};
    }

    OperandPtr operator()(int val) const {
        return OperandPtr{new IntLiteral(val)};
    }

    OperandPtr operator()(std::string val) const {
        return OperandPtr{new StringLiteral(val)};
    }

    OperandPtr operator()(IdentificationToken name) const {
        return OperandPtr{new VariableReference(name.token)};
    }
};


#endif //CSP_OPERANDFACTORY_H
