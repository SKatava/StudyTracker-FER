// ui/main.cpp
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>
#include <QStatusBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr)
        : QMainWindow(parent)
    {
        setWindowTitle("Study Tracker");
        resize(700, 500);

        // Status bar (bottom)
        statusBar()->showMessage("Ready");

        // Central widget + main vertical layout
        QWidget *central = new QWidget(this);
        setCentralWidget(central);

        QVBoxLayout *mainLayout = new QVBoxLayout(central);
        mainLayout->setContentsMargins(20, 20, 20, 20);
        mainLayout->setSpacing(15);

        // ── Header ───────────────────────────────────────────────
        QLabel *header = new QLabel("Study Tracker", this);
        header->setAlignment(Qt::AlignCenter);
        QFont headerFont = header->font();
        headerFont.setPointSize(18);
        headerFont.setBold(true);
        header->setFont(headerFont);
        mainLayout->addWidget(header);

        QLabel *subtitle = new QLabel("Track your subjects and study sessions", this);
        subtitle->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(subtitle);

        mainLayout->addSpacing(20);

        // ── Add subject section ──────────────────────────────────
        QHBoxLayout *addLayout = new QHBoxLayout();
        
        QLineEdit *subjectInput = new QLineEdit(this);
        subjectInput->setPlaceholderText("Enter new subject name...");
        subjectInput->setMinimumHeight(40);
        addLayout->addWidget(subjectInput);

        QPushButton *addBtn = new QPushButton("Add Subject", this);
        addBtn->setMinimumHeight(40);
        addBtn->setMinimumWidth(140);
        addLayout->addWidget(addBtn);

        mainLayout->addLayout(addLayout);

        // ── Subject list ─────────────────────────────────────────
        QListWidget *subjectList = new QListWidget(this);
        subjectList->setMinimumHeight(200);
        subjectList->setAlternatingRowColors(true);
        subjectList->setStyleSheet("QListWidget { font-size: 14px; }");
        mainLayout->addWidget(subjectList, 1);  // stretch factor 1

        // ── Action buttons ───────────────────────────────────────
        QHBoxLayout *actions = new QHBoxLayout();
        actions->addStretch();

        QPushButton *startSessionBtn = new QPushButton("Start Study Session", this);
        startSessionBtn->setMinimumHeight(45);
        startSessionBtn->setStyleSheet("font-weight: bold;");
        actions->addWidget(startSessionBtn);

        QPushButton *statsBtn = new QPushButton("View Statistics", this);
        statsBtn->setMinimumHeight(45);
        actions->addWidget(statsBtn);

        mainLayout->addLayout(actions);

        mainLayout->addStretch();

        // ── Connections ──────────────────────────────────────────
        connect(addBtn, &QPushButton::clicked, this, [this, subjectInput, subjectList]() {
            QString name = subjectInput->text().trimmed();
            if (name.isEmpty()) {
                QMessageBox::warning(this, "Input required", "Please enter a subject name.");
                return;
            }

            // Simulate adding to list (later you'll replace with core)
            QListWidgetItem *item = new QListWidgetItem(name);
            item->setIcon(QIcon::fromTheme("document-new"));  // optional icon
            subjectList->addItem(item);

            subjectInput->clear();
            statusBar()->showMessage("Added subject: " + name, 3000);
        });

        connect(startSessionBtn, &QPushButton::clicked, this, [this, subjectList]() {
            if (subjectList->currentItem() == nullptr) {
                QMessageBox::information(this, "No selection", "Select a subject first.");
                return;
            }
            QString subject = subjectList->currentItem()->text();
            QMessageBox::information(this, "Study Session",
                                     "Starting session for: " + subject + "\n\n"
                                     "(This is a placeholder — timer/logic will come later)");
            statusBar()->showMessage("Study session started for " + subject);
        });

        connect(statsBtn, &QPushButton::clicked, this, [this, subjectList]() {
            QMessageBox::information(this, "Statistics",
                                     "Total study time: —\n"
                                     "Subjects tracked: " + QString::number(subjectList->count()) + "\n\n"
                                     "(Real stats coming from core later)");
        });
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Optional: modern-ish look
    app.setStyle("Fusion");

    MainWindow window;
    window.show();

    return app.exec();
}

#include "main.moc"
