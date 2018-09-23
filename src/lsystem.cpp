#include <lsys/lsystem.h>

LSystem::LSystem() {
    rules = vector<Rule*>();
    alphabet = "";
    axiom = "";
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
    if (index >= rules.size() || index < 0)
    {
        throw new LSysException("LSystem: rule index out of bounds");
    }

    Rule* rule = rules[rules.size() - 1];
    rules[rules.size()-1] = rules[index];
    rules[index] = rule;
    delete rules[rules.size()-1];
    rules.pop_back();
}

string LSystem::process(string str) const
{
    string sentance = "";

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        bool matchingRule = false;

        for (int j = 0; j < rules.size(); ++j)
        {
            if (c == rules[j]->getVariable())
            {
                sentance = sentance + rules[j]->getSemantics();
                matchingRule = true;
                j = rules.size();
            }
        }

        if (!matchingRule)
        {
            sentance = sentance + c;
        }
    }

    return sentance;
}

string LSystem::getAlphabet() const
{
    return alphabet;
}

string LSystem::getAxiom() const
{
    return axiom;
}

void LSystem::setAlphabet(string param)
{
    alphabet = param;
}

void LSystem::setAxiom(string param)
{
    axiom = param;
}
