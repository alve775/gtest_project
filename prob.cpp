#include<iostream>
#include<string>
#include<sstream>
#include<gtest/gtest.h>
using namespace std;


class window {
    public:
        virtual void render() = 0;
        virtual ~window() = default;
    };

class scrollbar {
    public:
        virtual void render() = 0;
        virtual ~scrollbar() = default;
    };

class WindowsWindow : public window {
    public:
        void render() override {
            cout << "Rendering Windows Window" << endl;
        }
    };

class WindowsScrollbar : public scrollbar {
    public:
        void render() override {
            cout << "Rendering Windows Scrollbar" << endl;
        }
    };

class linuxWindow : public window {
    public:
        void render() override {
            cout << "Rendering Linux Window" << endl;
        }
    };
class linuxScrollbar : public scrollbar {
    public:
        void render() override {
            cout << "Rendering Linux Scrollbar" << endl;
        }
    };

// Abstract Factory
class GUIFactory {
    public:
        virtual window* createWindow() = 0;
        virtual scrollbar* createScrollbar() = 0;
        virtual ~GUIFactory() = default;
    };

//concrete windows factory
class WindowsFactory : public GUIFactory {
    public:
        window* createWindow() override {
            return new WindowsWindow();
        }
        scrollbar* createScrollbar() override {
            return new WindowsScrollbar();
        }
    };

//concrete linux factory    
class LinuxFactory : public GUIFactory {
    public:
        window* createWindow() override {
            return new linuxWindow();
        }
        scrollbar* createScrollbar() override {
            return new linuxScrollbar();
        }
    };




// Google Test cases
//Windows
TEST(GUIFactoryTest, WindowsFactoryTest) {
    GUIFactory* factory = new WindowsFactory();
    window* win = factory->createWindow();
    scrollbar* bar = factory->createScrollbar();

    EXPECT_NE(win, nullptr);
    EXPECT_NE(bar, nullptr);

    win->render();
    bar->render();

    delete win;
    delete bar;
    delete factory;
}

// //Linux
TEST(GUIFactoryTest, LinuxFactoryTest) {
    GUIFactory* factory = new LinuxFactory();
    window* win = factory->createWindow();
    scrollbar* bar = factory->createScrollbar();

    EXPECT_NE(win, nullptr);
    EXPECT_NE(bar, nullptr);

    win->render();
    bar->render();

    delete win;
    delete bar;
    delete factory;
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

