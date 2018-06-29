#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <facade.h>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QString fileName;
    Facade facade;

private slots:
    void createFileButton();
    void readFromFileButton();
    void saveToFileButton();
};

#endif // MAINWINDOW_H
