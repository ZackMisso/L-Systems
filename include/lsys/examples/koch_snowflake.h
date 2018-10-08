#pragma once

#include <lsys/examples/exampleUI.h>

class Koch_Snowflake : public ExampleUI
{
public:
    Koch_Snowflake(int width,
                   int height,
                   string title);

    ~Koch_Snowflake();

    virtual bool keyboardEvent(int key,
                               int scancode,
                               int action,
                               int modifiers);

    virtual void draw(NVGcontext *ctx);
    virtual void drawContents();
};
