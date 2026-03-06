#ifndef APPLICATION_CLASS_H
#define APPLICATION_CLASS_H

#include <memory>

#include <QApplication>

#include <layout/MainWindow.h>

#include <core/services/AppContext.h>
#include <backend/sqlite/Database.h>
#include <backend/sqlite/SQLiteSubjectRepository.h>

class Application : public QApplication {
    public:
        explicit Application(int& argc, char** argv);
        int Execute();
    private:
        void loadStyles();
        void loadFonts();
        void loadWindowIcon();
        void loadAppContext();
            
        std::unique_ptr<MainWindow> window;

        Database database;
};

#endif
