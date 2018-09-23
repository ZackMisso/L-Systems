#pragma once

#include <iostream>
#include <nanogui/glutil.h>
#include <stdexcept>
#include <string>

using namespace std;

enum ScreenType {
    SCR_MAIN = 0x1,
    SCR_NONE = 0x2
};

class LSysException : public runtime_error
{
public:
    LSysException(string str) : runtime_error("There was an Exception")
    {
        cout << str << endl;
    }
};
