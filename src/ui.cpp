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

UI::UI() : nanogui::Screen(Eigen::Vector2i(800, 800), "Transmittance Tests") {
    initializeSubscreens();
}

UI::~UI() {
    // TODO
}

void UI::initializeSubscreens() {
    mainScreen = new MainSubScreen(this);

    currentScreen = mainScreen;
    switchType = SCR_MAIN;
}

bool UI::keyboardEvent(int key, int scancode, int action, int modifiers) {
    // TODO
    return false;
}

void UI::draw(NVGcontext *ctx) {
    if (switchType != SCR_NONE) {
        switchToScreen(switchType);
        switchType = SCR_NONE;
    }
    currentScreen->draw(ctx);
    Screen::draw(ctx);
}

void UI::drawContents() {
    currentScreen->drawContents();
}

void UI::switchToScreen(ScreenType type) {
    if (currentScreen->getType() == type) return;

    currentScreen->deinitialize();

    if (type == SCR_MAIN) currentScreen = mainScreen;

    currentScreen->initialize();
}
