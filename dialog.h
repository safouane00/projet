#ifndef DIALOG_H
#define DIALOG_H
#include "produitch.h"
#include "produitph.h"

#include <QDialog>
class QPrinter;
class QSqlTableModel;


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
bool verifform1();
private slots:


    void on_validerC_clicked();

    void on_valider_4_clicked();

 void uglyPrint(QPrinter *printer);
  void uglyPrint1(QPrinter *printer);

    void on_valider_6_clicked();

    void on_ModifierC_clicked();

    void on_tabC_activated(const QModelIndex &index);

    void on_SupprimerC_clicked();

    //void on_SupprimerC_2_clicked();

    void on_valider_3_clicked();

    void on_valider_5_clicked();

    void on_ModifierF_clicked();

    void on_tabF_activated(const QModelIndex &index);

    void on_SupprimerF_clicked();

    //void on_valider_2_clicked();

    void on_valider_clicked();

    void on_SupprimerC_2_clicked();

    void on_valider_2_clicked();

private:
    Ui::Dialog *ui;
    physique tmpphysique;
    chimie tmpchimie;
};

#endif // DIALOG_H
