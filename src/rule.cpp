#include <lsys/rule.h>

Rule::Rule() {
    tokens = nullptr;
}

Rule::~Rule() {
    if (tokens) delete[] tokens;
}

void Rule::parseSemantics() {
		vector<LSysTokens> tmpToks;
		int index = 0;
		// this will be buggy for multiple rule systems
		while (index < semantics.length()) {
				char character = semantics[index];
				if (character == '+') tmpToks.push_back(TOKEN_CLOCKWISE_ROTATE);
				else if (character == '-') tmpToks.push_back(TOKEN_COUNTERCLOCKWISE_ROTATE);
				else if (character == '[') tmpToks.push_back(TOKEN_PUSH);
				else if (character == ']') tmpToks.push_back(TOKEN_POP);
				else if (character == 'F') tmpToks.push_back(TOKEN_FORWARD_VARIABLE);
				else if ((int)character <= int('Z') && (int)character >= int('A')) tmpToks.push_back(TOKEN_VARIABLE);
				index++;
		}
		tmpToks.push_back(TOKENS_END);
		tokens = new LSysTokens[tmpToks.size()];
		for (int i = 0; i < tmpToks.size(); i++)
				tokens[i] = tmpToks[i];
}

int Rule::countTokens() {
		// TODO
		return 0;
}

string Rule::getSemantics() {
		return semantics;
}

char Rule::getVariable() {
		return variable;
}

void Rule::setSemantics(string param) {
		semantics = param;
}

void Rule::setVariable(char param) {
		variable = param;
}
