#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "person.h"
#include <QVector>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QItemSelectionModel>
#include <QTableWidget>
#include "sobre.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    vector<PF> pessoa;
    vector<PJ> pessoaJ;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddPFButto_clicked();

    void on_AddPJButton_clicked();

    void on_VectorButton_2_clicked();

    void on_SalvarButton_clicked();

    void on_pushButton_clicked();

    void on_actionSobre_triggered();

    void on_actionSalvar_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
