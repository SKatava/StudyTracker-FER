#ifndef PREFERENCESPAGE_CLASS_H
#define PREFERENCESPAGE_CLASS_H

#include <QWidget>
#include <QLayout>

class PreferencesPage : public QWidget {
    Q_OBJECT
    
public:
    explicit PreferencesPage(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    
};

#endif
