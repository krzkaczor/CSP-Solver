#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <iostream>
#include <string>
#include <fstream>

#include "grammar/CspProblemGrammar.h"
#include "utils/utils.h"
#include "csp_problem/CspProblem.h"
#include "solvers/BacktrackingSolver.h"
#include "solvers/ForwardCheckingSolver.h"

using namespace std;
using namespace csp;

void print_solutions(std::vector<Environment> solutions) {
    cout << "Solutions: " << solutions.size() << endl;
    for(auto solution : solutions) {
        cout << to_string(solution) << endl;
    }
}

int main(int argc, char** args) {
    if (argc != 2) {
        cout << "Input file must be specified" << endl;
        exit(1);
    }
    string inputFilePath(args[1]);
    ifstream file(inputFilePath);
    string cspProblemString((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    CspProblemGrammar cspProblemGrammar;
    CspProblemDefinition cspProblemDefinition;

    std::string::const_iterator iter = cspProblemString.cbegin();
    std::string::const_iterator inputEnd = cspProblemString.cend();

    bool success = phrase_parse(iter, inputEnd, cspProblemGrammar, boost::spirit::ascii::blank, cspProblemDefinition);

    if (!success) {
        std::string rest(iter, inputEnd);
        cout << "Parsing error: "<< endl;
        cout << "stopped at: \"" << rest << "\"\n";
        exit(1);
    }

    cout << "Parsing successful." << endl;
    CspProblem cspProblem(cspProblemDefinition, ExpressionFactory());
    cout << cspProblem.describe();

    cout << "Forward checking: " << endl;
    ForwardCheckingSolver fcsolver(false);
    auto start = std::chrono::system_clock::now();
    print_solutions(fcsolver.solve(cspProblem));
    auto end = std::chrono::system_clock::now();
    cout << "Time elapsed " << chrono::duration_cast<chrono::seconds>(end - start).count() << " seconds" << endl;

    cout << "Backtracking: " << endl;
    BacktrackingSolver btsolver(false);
    start = std::chrono::system_clock::now();
    print_solutions(btsolver.solve(cspProblem));
    end = std::chrono::system_clock::now();

    cout << "Time elapsed " << chrono::duration_cast<chrono::seconds>(end - start).count() << " seconds" << endl;

    return 0;
}
