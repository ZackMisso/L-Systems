#include <lsys/lsystem.h>

LSystem::LSystem() {
    rules = vector<Rule*>();
}

LSystem::~LSystem() {
    for (size_t i = 0; i < rules.size(); i++)
        delete rules[i];
    rules.clear();
}

void LSystem::addRule(Rule* rule) {
    rules.push_back(rule);
}

void LSystem::removeRule(int index) {
    // TODO
}
