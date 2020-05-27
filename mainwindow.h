#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "animaux.h"
#include "nourriture.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AfficherF_clicked();

    void on_SupprimerF_clicked();



    void on_AfficherC_clicked();



    void on_SupprimerC_clicked();

    void on_valider_clicked();

    void on_validerC_clicked();




    void on_ModifierF_clicked();

    void on_ModifierC_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    animaux tmpanimaux;
    nourriture tmpnourriture;
};
#endif // MAINWINDOW_H
