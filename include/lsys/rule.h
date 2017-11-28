#pragma once

#include <lsys/common.h>

enum LSysTokens {
		TOKEN_VARIABLE = 0x1,
		TOKEN_FORWARD_VARIABLE = 0x2,
		TOKEN_CLOCKWISE_ROTATE = 0x4,
		TOKEN_COUNTERCLOCKWISE_ROTATE = 0x8,
		TOKEN_PUSH = 0x10,
		TOKEN_POP = 0x20,
		TOKENS_END = 0x0
};

class Rule {
public:
    Rule();
    ~Rule();

		void parseSemantics();
		int countTokens();

		string getSemantics();
		char getVariable();

		void setSemantics(string param);
		void setVariable(char param);
private:
		string semantics;
		LSysTokens* tokens;
		char variable;
};
