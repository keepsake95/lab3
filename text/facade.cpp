#include "facade.h"

Facade::Facade()
{

}

void Facade::setText(QString text)
{
    text_ = text;
}

void Facade::setFileName(QString fileName)
{
    fileName_ = fileName;
}

bool Facade::createFile()
{
    cFile = new CreateFile(fileName_);
    return cFile->createFile();
    delete cFile;
}

bool Facade::createAndWriteFile()
{
    cFile = new CreateFile(fileName_, text_);
    return cFile->createFile();
    delete cFile;
}

bool Facade::writeToFile()
{
    wToFile = new WriteToFile(fileName_, text_);
    return wToFile->writeToFile();
    delete wToFile;
}

QString Facade::readFromFile()
{
    text_.clear();
    rFromFile = new ReadFromFile(fileName_);
    if (rFromFile->readFromFile())
    {
        return rFromFile->getText();
    }
    else
    {
        return "Ошибка при чтении файла.";
    }
}
