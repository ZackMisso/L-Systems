#pragma once

#include <lsys/common.h>
#include <lsys/subscreen.h>
#include <lsys/subscreen_main.h>

class UI : public nanogui::Screen {
public:
    UI();
    ~UI();

    void initializeSubscreens();

    virtual bool keyboardEvent(int key, int scancode, int action, int modifiers);
    virtual void draw(NVGcontext *ctx);
    virtual void drawContents();

    void switchToScreen(ScreenType type);
public:
    SubScreen* currentScreen;
    MainSubScreen* mainScreen;

    ScreenType switchType;
};
