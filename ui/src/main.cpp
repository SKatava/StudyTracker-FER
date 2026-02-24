#include <QApplication>
#include <QFile>
#include <MainWindow.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile file("../ui/style.qss");
    if(file.open(QFile::ReadOnly))
    {
        QString style = QLatin1String(file.readAll());
        app.setStyleSheet(style);
    }

    MainWindow window;
    window.show();

    return app.exec();
}

