#include <lsys/datastructures/rule.h>

Rule::Rule(char c, string s) : variable(c), semantics(s) { }

string Rule::getSemantics() const {
    return semantics;
}

char Rule::getVariable() const {
    return variable;
}

void Rule::setSemantics(string param) {
    semantics = param;
}

void Rule::setVariable(char param) {
    variable = param;
}
