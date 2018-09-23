#pragma once

#include <lsys/common.h>
#include <lsys/rule.h>

// lsystem stored as a tree TODO later
// struct LSystemNode {
//     LSystemNode* children;
//     int numChildren;
//     float xpos;
//     float ypos;
// };

class LSystem {
public:
    LSystem();
    ~LSystem();

    void addRule(Rule* rule);
    void removeRule(int index);

    string process(string str) const;

    string getAlphabet() const;
    string getAxiom() const;

    void setAlphabet(string param);
    void setAxiom(string param);
private:
    string alphabet;
    string axiom;
    vector<Rule*> rules;
};
