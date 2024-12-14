#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QFontDialog>
#include <QTextCharFormat>
#include <QRegularExpression>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNuevo_triggered();

    void on_actionAbrir_triggered();

    void on_actionGuardar_como_triggered();

    void on_actionImprimir_triggered();

    void on_actionExit_triggered();

    void on_actionCopiar_triggered();

    void on_actionPegar_triggered();

    void on_actionCortar_triggered();

    void on_actionDeshacer_triggered();

    void on_actionRehacer_triggered();

    void on_actionVersi_n_triggered();

    void on_actionAcerca_triggered();

    void on_actionFuente_triggered();

    void updateCharacterCount();

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
};
#endif // MAINWINDOW_H
