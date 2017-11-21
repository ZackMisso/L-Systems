#pragma once

#include <lsys/subscreen.h>

class MainSubScreen : public SubScreen {
public:
    MainSubScreen(nanogui::Screen* screen);
    ~MainSubScreen();

    // subscreen methods
    virtual void initialize();
    virtual void deinitialize();
    virtual void makeVisible();
    virtual void makeInvisible();
    virtual bool keyboardEvent(int key, int scancode, int action, int modifiers);
    virtual void draw(NVGcontext *ctx);
    virtual void drawContents();

    void initializeGUI();
public:
    // main window
    nanogui::Window* mainWindow;
};
