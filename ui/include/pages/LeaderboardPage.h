#ifndef LEADERBOARDPAGE_CLASS_H
#define LEADERBOARDPAGE_CLASS_H

#include <QWidget>
#include <QLayout>

class LeaderboardPage : public QWidget {
    Q_OBJECT
    
public:
    explicit LeaderboardPage(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    
};

#endif
