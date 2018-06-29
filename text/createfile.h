#ifndef CREATEFILE_H
#define CREATEFILE_H

#include <QObject>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

class CreateFile
{
private:
    QString fileName_;
    QString text_;
    bool isWriteText;

public:
    CreateFile(QString &fileName)
    {
        fileName_ = fileName;
        isWriteText = false;
    }

    CreateFile(QString &fileName, QString &text)
    {
        fileName_ = fileName;
        text_ = text;
        isWriteText = true;
    }

    bool createFile()
    {
        QFile file(fileName_);
        if (file.exists())
        {
            QMessageBox message;
            message.setText("Файл с таким именем уже существует.");
            message.show();
            return false;
        }
        else
        {
            if (!file.open(QIODevice::WriteOnly))
            {
                QMessageBox message;
                message.setText("Не удалось создать файл.");
                message.show();
                return false;
            }
            if (isWriteText)
            {
                QTextStream writeStream(&file);
                writeStream << text_;
            }
            file.close();
            return true;
        }
    }
};

#endif // CREATEFILE_H
