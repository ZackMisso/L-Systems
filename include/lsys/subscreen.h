#pragma once

#include <lsys/common.h>
#include <nanogui/screen.h>
#include <nanogui/window.h>
#include <nanogui/slider.h>
#include <nanogui/textbox.h>
#include <nanogui/label.h>
#include <nanogui/button.h>
#include <nanogui/combobox.h>
#include <functional>
#include <string>

class SubScreen {
public:
    SubScreen(nanogui::Screen* screen);
    ~SubScreen();

    virtual void initialize() = 0;
    virtual void deinitialize() = 0;
    virtual void makeInvisible() = 0;
    virtual void makeVisible() = 0;

    virtual bool keyboardEvent(int key, int scancode, int action, int modifiers) = 0;
    virtual void draw(NVGcontext *ctx) = 0;
    virtual void drawContents() = 0;

    void clearScreen(NVGcontext *ctx);

    ScreenType getType();

    nanogui::Window* addWindow(nanogui::Screen* screen,
                                      std::string str,
                                      nanogui::Vector2i pos,
                                      bool isVisible);

    nanogui::Label* addLabel(nanogui::Window* window, std::string str);

    nanogui::Button* addButton(nanogui::Window* window,
                                      std::string str,
                                      const std::function<void(void)> &cb);

    nanogui::Button* addToggleButton(nanogui::Window* window,
                                            std::string str,
                                            bool pushed,
                                            const std::function<void(bool)> &cb);

    nanogui::ComboBox* addComboBox(nanogui::Window* window,
                                          const std::vector<std::string> &items,
                                          const std::function<void(int)> &cb);

    nanogui::Slider* addSlider(nanogui::Window* window,
                                      float value,
                                      const std::function<void(float)> &cb);

    nanogui::FloatBox<float>* addFloatBox(nanogui::Window* window,
                                                 float value,
                                                 bool editable,
                                                 const std::function<void(float)> &cb);

    nanogui::FloatBox<float>* addFloatBox(nanogui::Window* window,
                                                 float value,
                                                 float minValue,
                                                 float maxValue,
                                                 bool editable,
                                                 const std::function<void(float)> &cb);

    nanogui::IntBox<int>* addIntBox(nanogui::Window* window,
                                           int value,
                                           bool editable,
                                           const std::function<void(int)> &cb);

    nanogui::IntBox<int>* addIntBox(nanogui::Window* window,
                                           int value,
                                           int minValue,
                                           int maxValue,
                                           bool editable,
                                           const std::function<void(int)> &cb);
protected:
    nanogui::Screen* screen;
    ScreenType type;
};
