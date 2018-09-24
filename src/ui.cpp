#include <lsys/ui.h>
#include <lsys/subscreen.h>
#include <nanogui/layout.h>
#include <nanogui/label.h>
#include <nanogui/button.h>
#include <nanogui/combobox.h>
#include <functional>
#include <string>
#include <sstream>

PathData::PathData(Vec2<float> p, Vec2<float> d) : pos(p), dir(d) { }

UI::UI() : nanogui::Screen(Eigen::Vector2i(800, 800), "Transmittance Tests") {
    startPos = Vec2<float>(400.f, 700.f);
    startDir = Vec2<float>(0.f, -1.f);
    pathLength = 5.f;
    iterations = 5;
    angle = 3.14f / 6.f;
    createLSys();

    initializeGUI();
}

UI::~UI() {
    delete lsys;
}

void UI::initializeGUI()
{
    nanogui::Window* window = new nanogui::Window(this, "editor");
    window->setPosition(Eigen::Vector2i(50, 50));
    window->setLayout(new nanogui::GroupLayout());
    window->setVisible(true);

    nanogui::Label* label = new nanogui::Label(window, "startX");

    nanogui::FloatBox<float>* fbox = new nanogui::FloatBox<float>(window);
    fbox->setValue(startPos[0]);
    fbox->setEditable(true);
    fbox->setCallback([this](float value)
    {
        startPos[0] = value;
        return true;
    });

    label = new nanogui::Label(window, "startY");

    fbox = new nanogui::FloatBox<float>(window);
    fbox->setValue(startPos[1]);
    fbox->setEditable(true);
    fbox->setCallback([this](float value)
    {
        startPos[1] = value;
        return true;
    });

    label = new nanogui::Label(window, "startDirX");

    fbox = new nanogui::FloatBox<float>(window);
    fbox->setValue(startDir[0]);
    fbox->setEditable(true);
    fbox->setCallback([this](float value)
    {
        startDir[0] = value;
        return true;
    });

    label = new nanogui::Label(window, "startDirY");

    fbox = new nanogui::FloatBox<float>(window);
    fbox->setValue(startDir[1]);
    fbox->setEditable(true);
    fbox->setCallback([this](float value)
    {
        startDir[1] = value;
        return true;
    });

    label = new nanogui::Label(window, "pathLength");

    fbox = new nanogui::FloatBox<float>(window);
    fbox->setValue(pathLength);
    fbox->setEditable(true);
    fbox->setCallback([this](float value)
    {
        pathLength = value;
        return true;
    });

    label = new nanogui::Label(window, "iterations");

    nanogui::IntBox<int>* ibox = new nanogui::IntBox<int>(window);
    ibox->setValue(iterations);
    ibox->setEditable(true);
    ibox->setCallback([this](int value)
    {
        iterations = value;
        return true;
    });

    label = new nanogui::Label(window, "angle");

    fbox = new nanogui::FloatBox<float>(window);
    fbox->setValue(angle);
    fbox->setEditable(true);
    fbox->setCallback([this](float value)
    {
        angle = value;
        return true;
    });

    performLayout();
}

void UI::createLSys()
{
    lsys = new LSystem();
    lsys->setAlphabet("F+-[]");
    lsys->setAxiom("F");
    lsys->addRule(new Rule('F', "FF+[+F-F-F]-[-F+F+F]"));
}

bool UI::keyboardEvent(int key, int scancode, int action, int modifiers) {
    if (Screen::keyboardEvent(key, scancode, action, modifiers))
    {
        return true;
    }

    return false;
}

void UI::draw(NVGcontext *ctx) {
    clearScreen(ctx);

    Screen::draw(ctx);

    string sentance = lsys->getAxiom();
    for (int i = 0; i < iterations; ++i)
    {
        sentance = lsys->process(sentance);
    }

    vector<PathData> stack = vector<PathData>();
    Vec2<float> pos = startPos;
    Vec2<float> dir = startDir;

    for (int i = 0; i < sentance.length(); i++)
    {
        if (sentance[i] == 'F')
        {
            // draw forward
            Vec2<float> newpos = pos + dir * pathLength;
            // cout << newpos[0] << " , " << newpos[1] << endl;
            nvgStrokeColor(ctx, nanogui::Color(1.f, 1.f, 1.f, 0.1f));
            nvgBeginPath(ctx);

            nvgMoveTo(ctx, pos[0], pos[1]);
            nvgLineTo(ctx, newpos[0], newpos[1]);

            nvgStroke(ctx);

            pos = newpos;
        }
        else if (sentance[i] == '+')
        {
            // rotate
            dir = dir.rotCW(angle);
        }
        else if (sentance[i] == '-')
        {
            // rotate
            dir = dir.rotCCW(angle);
        }
        else if (sentance[i] == '[')
        {
            // push
            stack.push_back(PathData(pos, dir));
        }
        else if (sentance[i] == ']')
        {
            // pop
            PathData data = stack[stack.size() - 1];
            stack.pop_back();
            pos = data.pos;
            dir = data.dir;
        }
    }
}

void UI::drawContents() {
    // currentScreen->drawContents();
}

void UI::clearScreen(NVGcontext *ctx)
{
    // clear the screen
    nvgBeginPath(ctx);
    nvgRect(ctx, 0, 0, 1024, 1024);
    nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgFill(ctx);
}
