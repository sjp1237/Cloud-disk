#ifndef FILEPROPERTYIINFODIALOG_H
#define FILEPROPERTYIINFODIALOG_H

#include <QDialog>
#include"analyjsondata.h"
namespace Ui {
class filePropertyiInfoDialog;
}

class filePropertyiInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit filePropertyiInfoDialog(QWidget *parent = nullptr);
    ~filePropertyiInfoDialog();

    void setFileInfo(FileInfo *fileInfo);
private:
    Ui::filePropertyiInfoDialog *ui;
};

#endif // FILEPROPERTYIINFODIALOG_H
