#ifndef UPLOADWIDGET_H
#define UPLOADWIDGET_H

#include <QWidget>

namespace Ui {
class upLoadWidget;
}

class upLoadWidget : public QWidget
{
    Q_OBJECT

public:
    explicit upLoadWidget(QWidget *parent = nullptr);
    ~upLoadWidget();

private:
    Ui::upLoadWidget *ui;
};

#endif // UPLOADWIDGET_H
