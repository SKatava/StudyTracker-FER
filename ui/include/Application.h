#ifndef APPLICATION_CLASS_H
#define APPLICATION_CLASS_H

#include <QApplication>

#include <layout/MainWindow.h>

class Application : public QApplication {
    public:
        explicit Application(int& argc, char** argv);
        int Execute();
    private:
        void loadStyles();
        void loadFonts();
        void loadWindowIcon();

        MainWindow window;
};

#endif
