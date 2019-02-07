#include "readfile.h"
#include <QString>
#include <QFile>
#include <QDebug>

ReadFile::ReadFile(){

}

ReadFile::~ReadFile(){

}

QString ReadFile::message(QString filename){
    QFile file(QString(":/txt/")+filename);
    QString line1;
    if(!file.exists()){
        qDebug() << "no such file";
    }

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line1 += QString("\n")+stream.readLine();
        }
    }
    return line1;
file.close();
}
