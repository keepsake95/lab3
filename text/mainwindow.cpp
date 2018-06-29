#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->createButton, SIGNAL(clicked(bool)), this, SLOT(createFileButton()));
    connect(ui->saveButton, SIGNAL(clicked(bool)), this, SLOT(saveToFileButton()));
    connect(ui->openButton, SIGNAL(clicked(bool)), this, SLOT(readFromFileButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createFileButton()
{
    fileName = QFileDialog::getSaveFileName(this, tr("Create File"), "/", tr("Text (*.txt)"));
    facade.setFileName(fileName);
    if (ui->textEdit->toPlainText().isEmpty())
    {
        facade.createFile();
    }
    else
    {
        facade.setText(ui->textEdit->toPlainText());
        facade.createAndWriteFile();
    }
}

void MainWindow::readFromFileButton()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open Text File"), "/home/tproo", tr("Text Files (*.txt)"));
    facade.setFileName(fileName);
    QString text = facade.readFromFile();
    ui->textEdit->setPlainText(text);
}

void MainWindow::saveToFileButton()
{
    facade.setFileName(fileName);
    facade.setText(ui->textEdit->toPlainText());
    facade.writeToFile();
}
