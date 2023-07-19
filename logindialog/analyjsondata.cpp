#include "analyjsondata.h"
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonDocument>
#include<QDebug>
AnalyJsonData::AnalyJsonData(QObject *parent) : QObject(parent)
{

}

/*
 * "files":[{
        "user": "milo",
        "md5": "0afa719eb8a079553d14a2ae68111b82",
        "create_time": "2020-06-30 01:22:46",
        "file_name": "0voice.png",
        "share_status": 0,
        "pv": 0,
        "url": "http://192.168.52.139:80/group1/M00/00/00/wKg0i1769laAUapKAAA7AwV_nec649.png",
        "size": 15107,
        "type": "png"
        }]
  }
 * */

void  AnalyJsonData::getFileList(QByteArray data,QList<FileInfo*>& filelist)
{
   QJsonParseError err;
   QJsonDocument document=QJsonDocument::fromJson(data,&err);

   if(err.error!=QJsonParseError::NoError){
       qDebug()<<"QJson格式错误";
       return;
   }
   //将QJson字符串转换为QJson对象
   QJsonObject rootObject;
   rootObject=document.object();

  if(rootObject.contains("files")==false)
  {
      qDebug()<<"文件列表出错";
      return;
  }

  QJsonValue arryValue=rootObject["files"];
  if(arryValue.type()!=QJsonValue::Array)
  {
      qDebug()<<"文件列表出错";
      return ;
  }
  QJsonArray arry=arryValue.toArray();

  for(int i=0;i<arry.size();i++)
  {
      FileInfo* fileInfo=new FileInfo();
      QJsonValue value=arry[i];

      QJsonObject fileObj=value.toObject();
      QJsonValue userValue = fileObj.value("user");
      QJsonValue md5Value = fileObj.value("md5");
      QJsonValue createTimeValue = fileObj.value("create_time");
      QJsonValue fileNameValue = fileObj.value("file_name");
      QJsonValue shareStatus = fileObj.value("share_status");
      QJsonValue pvValue = fileObj.value("pv");
      QJsonValue urlValue = fileObj.value("url");
      QJsonValue sizeValue = fileObj.value("size");
      QJsonValue typeValue = fileObj.value("type");

      fileInfo->user = userValue.toString();
      fileInfo->md5 = md5Value.toString();
      fileInfo->createTime = createTimeValue.toString();
      fileInfo->fileName = fileNameValue.toString();
      fileInfo->shareStatus = shareStatus.toInt();
      fileInfo->pv = pvValue.toInt();
      fileInfo->url = urlValue.toString();
      fileInfo->size = sizeValue.toInt();
      fileInfo->type = typeValue.toString();

      filelist.append(fileInfo);
  }
}
