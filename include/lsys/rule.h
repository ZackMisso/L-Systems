#pragma once

#include <lsys/common.h>

// a rule is of the form:
// A -> B
// where A is a single character and B is a string

class Rule {
public:
    Rule(char c, string s);

    string getSemantics() const;
    char getVariable() const;

    void setSemantics(string param);
    void setVariable(char param);
private:
    char variable;
    string semantics;
};
