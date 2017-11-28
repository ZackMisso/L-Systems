#include <lsys/test.h>
#include <lsys/rule.h>

bool Test::runAllTests() {
		if (!parseSemanticsTest()) {
				cout << "ERROR: Parse Semantics Unit Test Failed" << endl;
				return false;
		}
		return true;
}

bool Test::parseSemanticsTest() {
		// TODO

		return false;
}
