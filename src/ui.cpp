#include <lsys/ui.h>
// #include <lsys/render.h>
#include <lsys/subscreen.h>
// #include <transm/func.h>
#include <nanogui/layout.h>
#include <nanogui/label.h>
#include <nanogui/button.h>
#include <nanogui/combobox.h>
#include <functional>
#include <string>
#include <sstream>

UI::UI() : nanogui::Screen(Eigen::Vector2i(1024, 1024), "Transmittance Tests") {
    initializeSubscreens();
}

UI::~UI() {
    // TODO
}

void UI::initializeSubscreens() {
    // TODO
}

bool UI::keyboardEvent(int key, int scancode, int action, int modifiers) {
    // TODO
}

void UI::draw(NVGcontext *ctx) {
    // if (switchType != SCR_NONE) {
    //     switchToScreen(switchType);
    //     switchType = SCR_NONE;
    // }
    // currentScreen->draw(ctx);
    Screen::draw(ctx);
}

void UI::drawContents() {
    // currentScreen->drawContents();
}

void UI::switchToScreen(ScreenType type) {
    // if (currentScreen->getType() == type) return;
    //
    // currentScreen->deinitialize();
    //
    // // TODO
    // // if (type == SCR_MAIN) currentScreen = mainScreen;
    // // else if (type == SCR_ERROR) currentScreen = errorScreen;
    // // else if (type == SCR_EXT) currentScreen = extScreen;
    // // else if (type == SCR_HEATMP) currentScreen = varScreen;
    //
    // currentScreen->initialize();
}
