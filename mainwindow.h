#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produitph.h"
#include "produitch.h"

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

    bool verifform1();

    void on_AfficherC_clicked();



    void on_SupprimerC_clicked();

    void on_valider_clicked();

    void on_validerC_clicked();




    void on_ModifierF_clicked();

    void on_tabF_activated(const QModelIndex &index);


    void on_tabC_activated(const QModelIndex &index);

    void on_ModifierC_clicked();

private:

    Ui::MainWindow *ui;
    physique tmpphysique;
    chimie tmpchimie;
};
#endif // MAINWINDOW_H
