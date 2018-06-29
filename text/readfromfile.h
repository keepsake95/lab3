#ifndef READFROMFILE_H
#define READFROMFILE_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class ReadFromFile
{
private:
    QString fileName_;
    QString text_;
public:
    ReadFromFile(QString &fileName)
    {
        fileName_ = fileName;
    }

    bool readFromFile()
    {
        QFile file(fileName_);
        if (file.exists())
        {
            if (!file.open(QIODevice::ReadOnly))
            {
                QMessageBox message;
                message.setText("Не удалось открыть файл.");
                message.show();
                return false;
            }
            QTextStream readStream(&file);
            text_ += readStream.readAll();
            file.close();
            return true;
        }
        else
        {
            QMessageBox message;
            message.setText("Файла с таким именем не существует.");
            message.show();
            return false;
        }
    }

    QString getText()
    {
        return text_;
    }
};

#endif // READFROMFILE_H
