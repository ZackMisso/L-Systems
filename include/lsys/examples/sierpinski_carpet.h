#pragma once

#include <lsys/examples/exampleUI.h>

class Sierpinski_Carpet : public ExampleUI
{
public:
    Sierpinski_Carpet(int width,
                      int height,
                      string title);

    ~Sierpinski_Carpet();

    virtual bool keyboardEvent(int key,
                               int scancode,
                               int action,
                               int modifiers);

    virtual void draw(NVGcontext *ctx);
    virtual void drawContents();
};
