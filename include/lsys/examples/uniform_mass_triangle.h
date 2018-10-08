#pragma once

#include <lsys/examples/exampleUI.h>

class Uniform_Mass_Triangle : public ExampleUI
{
public:
    Uniform_Mass_Triangle(int width,
                          int height,
                          string title);

    ~Uniform_Mass_Triangle();

    virtual bool keyboardEvent(int key,
                               int scancode,
                               int action,
                               int modifiers);

    virtual void draw(NVGcontext *ctx);
    virtual void drawContents();
};
