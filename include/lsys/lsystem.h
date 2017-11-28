#pragma once

#include <lsys/common.h>
#include <lsys/rule.h>

class LSystem {
public:
    LSystem();
    ~LSystem();

    void addRule(Rule* rule);
    void removeRule(int index);
private:
    vector<Rule*> rules;
};
