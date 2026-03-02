#ifndef APPLICATION_CLASS_H
#define APPLICATION_CLASS_H

#include <QApplication>

#include <layout/MainWindow.h>

#include <core/services/AppContext.h>


class Application : public QApplication {
    public:
        explicit Application(int& argc, char** argv);
        int Execute();
    private:
        void loadStyles();
        void loadFonts();
        void loadWindowIcon();

        MainWindow window;

        AppContext appContext;
};

#endif
