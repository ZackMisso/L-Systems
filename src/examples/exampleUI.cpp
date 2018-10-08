#include <lsys/examples/exampleUI.h>

ExampleUI::ExampleUI(int width,
                     int height,
                     string title) :
    nanogui::Screen(nanogui::Vector2i(width, height), title)
{
    // TODO
}

ExampleUI::~ExampleUI()
{
    // TODO
}

void ExampleUI::clearScreen(NVGcontext* ctx)
{
    // TODO
}

nanogui::Label* ExampleUI::createLabel(string label)
{
    // TODO
    return nullptr;
}

nanogui::IntBox<int>* ExampleUI::createIntBox(nanogui::Window* window,
                                     int val,
                                     int min,
                                     int max)
{
    // TODO
    return nullptr;
}

nanogui::FloatBox<float>* ExampleUI::createFloatBox(nanogui::Window* window,
                                           float val,
                                           float min,
                                           float max)
{
    // TODO
    return nullptr;
}

nanogui::TextBox* ExampleUI::createTextBox(nanogui::Window* window,
                                  string text)
{
    // TODO
    return nullptr;
}
