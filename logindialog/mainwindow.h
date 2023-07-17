#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPaintEvent>

class buttongroup;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent*);

    void setSiganlButton();

    void setUser(QString name);

public slots:
    void hideWidget();
    void closeWidget();

signals:
    void userName(QString name);

    void switchUser();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
