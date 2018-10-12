#pragma once

#include <lsys/common.h>
#include <lsys/datastructures/rule.h>

class LSystem {
public:
    LSystem();
    ~LSystem();

    void addRule(Rule* rule);
    void removeRule(int index);

    void parseFromFile(const string& filename);

    string process(const string& str) const;

    string getAlphabet() const;
    string getAxiom() const;

    void setAlphabet(string param);
    void setAxiom(string param);
private:
    string alphabet;
    string axiom;
    vector<Rule*> rules;
};
