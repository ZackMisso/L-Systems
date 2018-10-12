#pragma once

#include <lsys/examples/exampleUI.h>
#include <lsys/datastructures/vector.h>
#include <lsys/datastructures/lsystem.h>

class DemoOne : public ExampleUI {
public:
    DemoOne();
    ~DemoOne();

    void createLSys();
    void initializeGUI();

    virtual bool keyboardEvent(int key, int scancode, int action, int modifiers);
    virtual void draw(NVGcontext *ctx);
    virtual void drawContents();
public:
    LSystem* lsys;
    Vec2<float> startPos;
    Vec2<float> startDir;
    float pathLength;
    float angle;
    int iterations;
};
