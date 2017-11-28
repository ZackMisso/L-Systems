#include <lsys/lsystem.h>

LSystem::LSystem() {
    rules = vector<Rule*>();
    bakedSystem = nullptr;
}

LSystem::~LSystem() {
    for (size_t i = 0; i < rules.size(); i++)
        delete rules[i];
    rules.clear();
    if (bakedSystem) delete bakedSystem;
}

void LSystem::addRule(Rule* rule) {
    rules.push_back(rule);
}

void LSystem::removeRule(int index) {
    // TODO
}

void LSystem::buildSystem() {
    // TODO
		bakedSystem = new LSystemNode();
		bakedSystem->children = nullptr;
		bakedSystem->numChildren = 0;
		bakedSystem->xpos = 0.f;
		bakedSystem->ypos = 0.f;
}
