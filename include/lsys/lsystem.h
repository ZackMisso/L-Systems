#pragma once

#include <lsys/common.h>
#include <lsys/rule.h>

// lsystem stored as a tree
struct LSystemNode {
		LSystemNode* children;
    int numChildren;
		float xpos;
    float ypos;
};

class LSystem {
public:
    LSystem();
    ~LSystem();

    void addRule(Rule* rule);
    void removeRule(int index);
    void buildSystem();
private:
    LSystemNode* bakedSystem;
    vector<Rule*> rules;
};
