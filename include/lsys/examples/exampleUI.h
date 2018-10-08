#pragma once

#include <lsys/common.h>
#include <nanogui/screen.h>
#include <nanogui/window.h>
#include <nanogui/slider.h>
#include <nanogui/textbox.h>
#include <nanogui/label.h>
#include <nanogui/button.h>
#include <nanogui/combobox.h>
#include <nanogui/glutil.h>

class ExampleUI : public nanogui::Screen
{
public:
    ExampleUI(int width,
              int height,
              string title);

    virtual ~ExampleUI();

    // virtual bool keyboardEvent(int key, int )

    void clearScreen(NVGcontext* ctx);

    nanogui::Label* createLabel(string label);

    nanogui::IntBox<int>* createIntBox(nanogui::Window* window,
                                       int val,
                                       int min = 0,
                                       int max = 100);

    nanogui::FloatBox<float>* createFloatBox(nanogui::Window* window,
                                             float val,
                                             float min = 0.f,
                                             float max = 0.f);

    nanogui::TextBox* createTextBox(nanogui::Window* window,
                                    string text);
};
