#include <Application.h>
#include <QFile>
#include <QFontDatabase>
#include <Fonts.h>
#include <QIcon>

#include <core/domain/Subject.h>


Application::Application(int& argc, char** argv) : QApplication(argc, argv) {
    loadStyles();
    loadFonts();
    loadWindowIcon();
    loadAppContext();

    window = std::make_unique<MainWindow>();
    window->show();
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
    database.InitializeSchema();
    auto subjectRepo = std::make_unique<SQLiteSubjectRepository>(database);
    auto sessionRepo = std::make_unique<SQLiteSessionRepository>(database);
    auto taskRepo = std::make_unique<SQLiteTaskRepository>(database);
    AppContext::Initialize(std::move(subjectRepo), std::move(sessionRepo), std::move(taskRepo));
}

