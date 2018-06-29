#ifndef FACADE_H
#define FACADE_H

#include <QObject>
#include <createfile.h>
#include <writetofile.h>
#include <readfromfile.h>

class Facade
{
private:
    QString text_;
    QString fileName_;

public:
    Facade();

    CreateFile *cFile;
    WriteToFile *wToFile;
    ReadFromFile *rFromFile;

    void setText(QString text);
    void setFileName(QString fileName);

    bool createFile();
    bool createAndWriteFile();
    bool writeToFile();
    QString readFromFile();
};

#endif // FACADE_H
