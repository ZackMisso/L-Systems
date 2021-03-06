#include <lsys/common.h>
#include <lsys/datastructures/lsystem.h>
#include <lsys/datastructures/rule.h>

#include <lsys/examples/sierpinski_carpet.h>
#include <lsys/examples/sierpinski_triangle.h>
#include <lsys/examples/koch_snowflake.h>
#include <lsys/examples/demo_one.h>
// #include <imedit/image.h>

bool testsuite();

int main(int argc, char* argv[]) {
    std::cout << "L-Systems engaged" << std::endl;

    // Image<double> imTest = Image<double>(100, 100, 3);

    // debug logic
    if (!testsuite())
    {
        cout << "LSystem Implementation Faulty" << endl;
        return -1;
    }

    LSystem* lsys = new LSystem();
    lsys->setAlphabet("AB");
    lsys->setAxiom("A");
    lsys->addRule(new Rule('A', "AB"));
    lsys->addRule(new Rule('B', "A"));
    cout << lsys->getAxiom() << endl;
    cout << lsys->process(lsys->getAxiom()) << endl;
    cout << lsys->process(lsys->process(lsys->getAxiom())) << endl;
    cout << lsys->process(lsys->process(lsys->process(lsys->getAxiom()))) << endl;
    cout << lsys->process(lsys->process(lsys->process(lsys->process(lsys->getAxiom())))) << endl;

    // try {
    //    nanogui::init();
    //    {
    //        nanogui::ref<UI> app = new UI();
    //        app->drawAll();
    //        app->setVisible(true);
    //        nanogui::mainloop();
    //    }
    //    nanogui::shutdown();
    // } catch (const std::runtime_error &e) {
    //    std::string error_msg = std::string("Caught a fatal error: ") + std::string(e.what());
    //    std::cerr << error_msg << std::endl;
    //    return -1;
    // }

    try {
       nanogui::init();
       {
           nanogui::ref<DemoOne> app = new DemoOne();
           app->drawAll();
           app->setVisible(true);
           nanogui::mainloop();
       }
       nanogui::shutdown();
    } catch (const std::runtime_error &e) {
       std::string error_msg = std::string("Caught a fatal error: ") + std::string(e.what());
       std::cerr << error_msg << std::endl;
       return -1;
    }

    return 0;
}

bool testsuite()
{
    // TODO
    return true;
}

// fractals to implement:
