#ifndef WRITETOFILE_H
#define WRITETOFILE_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class WriteToFile
{
private:
    QString fileName_;
    QString text_;

public:
    WriteToFile(QString &fileName, QString &text)
    {
        fileName_ = fileName;
        text_ = text;
    }

    bool writeToFile()
    {
        QFile file(fileName_);
        if (file.exists())
        {
            if (!file.open(QIODevice::WriteOnly))
            {
                QMessageBox message;
                message.setText("Не удалось открыть файл.");
                message.show();
                return false;
            }

            QTextStream writeStream(&file);
            writeStream << text_;
            file.close();
            return true;
        }
        else
        {
            QMessageBox message;
            message.setText("Такого файла не существует.");
            message.show();
            return false;
        }
    }
};

#endif // WRITETOFILE_H
