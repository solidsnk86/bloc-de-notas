#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNuevo_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionAbrir_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Abrir Archivo");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Advertencia", "No se pudo abrir el archivo: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in (&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionGuardar_como_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Guardar como");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Advertencia", "No se pudo guardar el archivo: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}


void MainWindow::on_actionImprimir_triggered()
{
    QPrinter printer;
    printer.setPrinterName(printer.printerName());
    QPrintDialog pDialog(&printer, this);
    if (pDialog.exec() == QDialog::Rejected) {
        QMessageBox::warning(this, "Advertencia", "No se puede acceder a la impresora");
    }
    ui->textEdit->print(&printer);
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionCopiar_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPegar_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionCortar_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionDeshacer_triggered()
{
    ui->textEdit->undo();
}



void MainWindow::on_actionRehacer_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionL_eme_triggered()
{
    QMessageBox::about(this, "Acerca",
    "Este es un bloc de notas realizado con el framework QT escrito en lenguaje C++, hecho con 💙 por Gabriel Calcagni. Para más información contáctame a éste correo: calcagni.gabriel86@gmail.com"
    );
}


void MainWindow::on_actionVersi_n_triggered()
{
    QMessageBox::about(this, "Versión del programa", "Versión 1.0.0 | Creado el 14 de Diciembre del 2024");
}

