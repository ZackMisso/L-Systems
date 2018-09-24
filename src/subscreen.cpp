// #include <lsys/subscreen.h>
// #include <nanogui/layout.h>
//
// SubScreen::SubScreen(nanogui::Screen* screen) : screen(screen) {
//     // does nothing for now
// }
//
// SubScreen::~SubScreen() {
//     // does nothing for now
// }
//
// void SubScreen::clearScreen(NVGcontext* ctx) {
//     // clear the screen
//     nvgBeginPath(ctx);
//     nvgRect(ctx, 0, 0, 1024, 1024);
//     nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
//     nvgFill(ctx);
// }
//
// ScreenType SubScreen::getType() { return type; }
//
// nanogui::Window* SubScreen::addWindow(nanogui::Screen* screen,
//                                       std::string str,
//                                       nanogui::Vector2i pos,
//                                       bool isVisible)
// {
//     nanogui::Window* window = new nanogui::Window(screen, str);
//     window->setPosition(pos);
//     window->setLayout(new nanogui::GroupLayout());
//     window->setVisible(isVisible);
//     return window;
// }
//
// nanogui::Label* SubScreen::addLabel(nanogui::Window* window, std::string str)
// {
//     nanogui::Label* label = new nanogui::Label(window, str, "sans-bold");
//     return label;
// }
//
// nanogui::Button* SubScreen::addButton(nanogui::Window* window,
//                                       std::string str,
//                                       const std::function<void(void)> &cb)
// {
//     nanogui::Button* button = new nanogui::Button(window, str);
//     button->setCallback(cb);
//     return button;
// }
//
// nanogui::Button* SubScreen::addToggleButton(nanogui::Window* window,
//                                             std::string str,
//                                             bool pushed,
//                                             const std::function<void(bool)> &cb)
// {
//     nanogui::Button* button = new nanogui::Button(window, str);
//     button->setFlags(nanogui::Button::ToggleButton);
//     button->setChangeCallback(cb);
//     button->setPushed(pushed);
//     return button;
// }
//
// nanogui::ComboBox* SubScreen::addComboBox(nanogui::Window* window,
//                                           const std::vector<std::string> &items,
//                                           const std::function<void(int)> &cb)
// {
//     nanogui::ComboBox* combo = new nanogui::ComboBox(window, items);
//     combo->setCallback(cb);
//     return combo;
// }
//
// nanogui::Slider* SubScreen::addSlider(nanogui::Window* window,
//                            float value,
//                            const std::function<void(float)> &cb)
// {
//     nanogui::Slider* slider = new nanogui::Slider(window);
//     slider->setValue(value);
//     slider->setCallback(cb);
//     return slider;
// }
//
// nanogui::FloatBox<float>* SubScreen::addFloatBox(nanogui::Window* window,
//                                                  float value,
//                                                  bool editable,
//                                                  const std::function<void(float)> &cb)
// {
//     nanogui::FloatBox<float>* box = new nanogui::FloatBox<float>(window);
//     box->setValue(value);
//     box->setEditable(editable);
//     box->setCallback(cb);
//     return box;
// }
//
// nanogui::FloatBox<float>* SubScreen::addFloatBox(nanogui::Window* window,
//                                                  float value,
//                                                  float minValue,
//                                                  float maxValue,
//                                                  bool editable,
//                                                  const std::function<void(float)> &cb)
// {
//     nanogui::FloatBox<float>* box = new nanogui::FloatBox<float>(window);
//     box->setValue(value);
//     box->setMinValue(minValue);
//     box->setMaxValue(maxValue);
//     box->setEditable(editable);
//     box->setCallback(cb);
//     return box;
// }
//
// nanogui::IntBox<int>* SubScreen::addIntBox(nanogui::Window* window,
//                                            int value,
//                                            bool editable,
//                                            const std::function<void(int)> &cb)
// {
//     nanogui::IntBox<int>* box = new nanogui::IntBox<int>(window);
//     box->setValue(value);
//     box->setEditable(editable);
//     box->setCallback(cb);
//     return box;
// }
//
// nanogui::IntBox<int>* SubScreen::addIntBox(nanogui::Window* window,
//                                            int value,
//                                            int minValue,
//                                            int maxValue,
//                                            bool editable,
//                                            const std::function<void(int)> &cb)
// {
//     nanogui::IntBox<int>* box = new nanogui::IntBox<int>(window);
//     box->setValue(value);
//     box->setMinValue(minValue);
//     box->setMaxValue(maxValue);
//     box->setEditable(editable);
//     box->setCallback(cb);
//     return box;
// }
