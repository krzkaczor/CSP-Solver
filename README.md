# CSP-Solver
General solver for [constraint satisfaction problems](http://en.wikipedia.org/wiki/Constraint_satisfaction_problem) like queens problem, sudoku, crosswords, graph coloring. It is written in C++ using `boost::spirit`.

Implementation
---
Currently solver supports `backtracking` and `forward checking` to find solutions.

CSP-DSL
---
Problem must be specified using simple Domain Specific Language. For example 4x4 queens problem looks like this:

	H0 H1 H2 H3 
	0 1 2 3 
	0 1 2 3 
	0 1 2 3 
	0 1 2 3 
	H0 H1 H2 H3 !! 
	H0 H1 - || 0 1 - || != 
	H0 H2 - || 0 2 - || != 
	H0 H3 - || 0 3 - || != 
	H1 H2 - || 1 2 - || != 
	H1 H3 - || 1 3 - || != 
	H2 H3 - || 2 3 - || != 

First line descibes n variables. Next n lines specifies variables domains. Finally, there is an arbitrary ammount of constrains written down using RPN.

Program for queens problem can be generated using this [generator](https://github.com/krzkaczor/CspQueensProblemGenerator).

Take a look at samples directory to find more examples.

Future work
----
- DSL documentation
- support for comments in DSL
- forward checking optimaization
- stack machine JITing