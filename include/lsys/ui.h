#pragma once

#include <nanogui/screen.h>
#include <nanogui/window.h>
#include <nanogui/slider.h>
#include <nanogui/textbox.h>
#include <nanogui/label.h>
#include <nanogui/button.h>
#include <nanogui/combobox.h>
#include <nanogui/glutil.h>
#include <lsys/common.h>
#include <lsys/subscreen.h>
#include <lsys/subscreen_main.h>
#include <lsys/vector.h>
#include <lsys/lsystem.h>

struct PathData
{
    PathData(Vec2<float> p, Vec2<float> d);

    Vec2<float> pos;
    Vec2<float> dir;
};

class UI : public nanogui::Screen {
public:
    UI();
    ~UI();

    void createLSys();
    void initializeGUI();

    virtual bool keyboardEvent(int key, int scancode, int action, int modifiers);
    virtual void draw(NVGcontext *ctx);
    virtual void drawContents();

    void clearScreen(NVGcontext *ctx);
public:
    LSystem* lsys;
    Vec2<float> startPos;
    Vec2<float> startDir;
    float pathLength;
    float angle;
    int iterations;
};
