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

    ~MainWindow();

    void paintEvent(QPaintEvent*);

    void setSiganlButton();

    void init();
    void setUser(QString name);
    static MainWindow* getinstant();
public slots:
    void hideWidget();
    void closeWidget();

signals:
    void userName(QString name);

    void switchUser();
private:
    Ui::MainWindow *ui;
   explicit MainWindow(QWidget *parent = nullptr);
    static MainWindow* instant;
};

#endif // MAINWINDOW_H
