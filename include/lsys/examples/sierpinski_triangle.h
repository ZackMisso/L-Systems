#pragma once

#include <lsys/examples/exampleUI.h>

class Sierpinski_Triangle : public ExampleUI
{
public:
    Sierpinski_Triangle(int width,
                        int height,
                        string title);

    ~Sierpinski_Triangle();

    virtual bool keyboardEvent(int key,
                               int scancode,
                               int action,
                               int modifiers);

    virtual void draw(NVGcontext *ctx);
    virtual void drawContents();
};
