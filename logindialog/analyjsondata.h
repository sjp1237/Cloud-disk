#ifndef ANALYJSONDATA_H
#define ANALYJSONDATA_H
#include<QObject>
#include<QList>
#include"fileinfo.h"



class AnalyJsonData : public QObject
{
    Q_OBJECT


public:
    explicit AnalyJsonData(QObject *parent = nullptr);
    static void  getFileList(QByteArray data,QList<FileInfo*> & filelist);
signals:
public slots:
};

#endif // ANALYJSONDATA_H
