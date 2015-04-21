//
// Created by Krzysztof Kaczor on 4/3/15.
//

#ifndef CSP_UTILS_H
#define CSP_UTILS_H

#import <vector>
#import <string>
#import <unordered_set>
#include <numeric>
#include <boost/lexical_cast.hpp>
#include <boost/variant.hpp>
#include "../defs.h"
#include "../csp_problem/Environment.h"

inline std::string to_string(domain_element dom) {
    if (dom.which() == 0)
        return std::to_string(boost::get<int>(dom));

    if (dom.which() == 1)
        return std::to_string(boost::get<bool>(dom));

    if (dom.which() == 2)
        return boost::get<std::string>(dom);

    assert(false);
}

inline std::string to_string(Environment& env) {
    return std::accumulate(env.begin(), env.end(), std::string(""), [](std::string a, Environment::value_type& pair) {
        return a + pair.first + " -> " + (pair.second.hasValue()? to_string(pair.second.getValue()) : "NaN") + "\n";
    });
}

template<typename T1, typename T2>
std::string vec_to_string(std::vector<boost::variant<T1, T2>>& v) {
    if (!v.size())
        return "";
    using namespace std;
    return accumulate(v.begin()+1, v.end(), boost::lexical_cast<std::string>(v[0]), [](const string& a, boost::variant<T1, T2> t) {
        return a + ", " + boost::lexical_cast<std::string>(t);
    });
}

template<typename T>
std::string vec_to_string(std::vector<T>& v) {
    if (!v.size())
        return "";
    using namespace std;
    return accumulate(v.begin()+1, v.end(), to_string(v[0]), [](const string& a, T t) {
        return a + ", " + to_string(t);
    });
}

template<>
inline std::string vec_to_string(std::vector<std::string>& v) {
    if (!v.size())
        return "";
    using namespace std;
    return accumulate(v.begin()+1, v.end(), v[0], [](const string& a, string t) {
        return a + ", " + t;
    });
}

template<typename T>
std::string vec_to_string(std::vector<std::vector<T>>& v) {
    if (!v.size())
        return "";
    using namespace std;
    return accumulate(v.begin()+1, v.end(), vec_to_string(v[0]), [](const string& a, vector<T> t) {
        return a + "\n" + vec_to_string(t);
    });
}

template<typename T>
std::string list_to_string(std::list<T> v) {
    std::vector<T> t(v.begin(), v.end());
    return vec_to_string(t);
}
#include "../stack_machine/Expression.h"
inline OperandPtr topAndPop(StackIt c) {
    return *(c++);
}

template<typename T>
bool contains(std::unordered_set<T> s, T v) {
    return s.find(v) != s.end();
}

#endif //CSP_UTILS_H
