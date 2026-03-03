#include <Application.h>
#include <QFile>
#include <QFontDatabase>
#include <Fonts.h>
#include <QIcon>

Application::Application(int& argc, char** argv) : QApplication(argc, argv) {
    loadStyles();
    loadFonts();
    loadWindowIcon();
    loadAppContext();

    window.show();
}

int Application::Execute() {
    return this->exec();
}

void Application::loadStyles() {
    QFile file(":/styles/theme.qss");
    if(file.open(QFile::ReadOnly)) {
        QString style = QLatin1String(file.readAll());
        this->setStyleSheet(style);
    }
}

void Application::loadFonts() {
    int fontId = QFontDatabase::addApplicationFont(":/fonts/icon_font.otf");

    if (fontId == -1) {
        qDebug() << "Failed to load icon font";
    }

    QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);
    Fonts::IconFamily = family;
}

void Application::loadWindowIcon() {
     this->setWindowIcon(QIcon(":/images/logo.png"));
}

void Application::loadAppContext() {
    auto subjectRepo = std::make_unique<SQLiteSubjectRepository>(database);
    appContext = std::make_unique<AppContext>(std::move(subjectRepo));
}
