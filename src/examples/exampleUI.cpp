#include <lsys/examples/exampleUI.h>

// TODO : implement these base creation methods in nanogui

ExampleUI::ExampleUI(int width,
                     int height,
                     string title) :
    nanogui::Screen(nanogui::Vector2i(width, height), title)
{
    // TODO
}

ExampleUI::~ExampleUI()
{
    // does nothing for now
    // TODO
}

void ExampleUI::clearScreen(NVGcontext* ctx)
{
    // clear the screen
    nvgBeginPath(ctx);
    nvgRect(ctx, 0, 0, 1024, 1024);
    nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgFill(ctx);
}

nanogui::Label* ExampleUI::createLabel(nanogui::Widget* widget,
                                       string label)
{
    return new nanogui::Label(widget, label);
}

nanogui::IntBox<int>* ExampleUI::createIntBox(nanogui::Widget* widget,
                                              int val,
                                              int min,
                                              int max,
                                              const std::function<void(int)> &cb)
{
    nanogui::IntBox<int>* box = new nanogui::IntBox<int>(widget);
    box->setValue(val);
    box->setMinValue(min);
    box->setMaxValue(max);
    box->setEditable(true);
    box->setCallback(cb);

    return box;
}

nanogui::FloatBox<float>* ExampleUI::createFloatBox(nanogui::Widget* widget,
                                                    float val,
                                                    float min,
                                                    float max,
                                                    const std::function<void(float)> &cb)
{
    nanogui::FloatBox<float>* box = new nanogui::FloatBox<float>(widget);
    box->setValue(val);
    box->setMinValue(min);
    box->setMaxValue(max);
    box->setEditable(true);
    box->setCallback(cb);

    return box;
}

nanogui::TextBox* ExampleUI::createTextBox(nanogui::Widget* widget,
                                           string text,
                                           const std::function<bool(const string&)> &cb)
{
    nanogui::TextBox* box = new nanogui::TextBox(widget);
    box->setValue(text);
    box->setEditable(true);
    box->setCallback(cb);
    return box;
}
