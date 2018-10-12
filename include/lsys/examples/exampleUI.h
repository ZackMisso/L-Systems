#pragma once

#include <lsys/common.h>
#include <nanogui/screen.h>
#include <nanogui/window.h>
#include <nanogui/slider.h>
#include <nanogui/textbox.h>
#include <nanogui/label.h>
#include <nanogui/layout.h>
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

    nanogui::Label* createLabel(nanogui::Widget* widget,
                                string label);

    nanogui::IntBox<int>* createIntBox(nanogui::Widget* widget,
                                              int val,
                                              int min,
                                              int max,
                                              const std::function<void(int)>& cb);

    nanogui::FloatBox<float>* createFloatBox(nanogui::Widget* widget,
                                                    float val,
                                                    float min,
                                                    float max,
                                                    const std::function<void(float)>& cb);

    nanogui::TextBox* createTextBox(nanogui::Widget* widget,
                                           string text,
                                           const std::function<bool(const string&)>& cb);
};
