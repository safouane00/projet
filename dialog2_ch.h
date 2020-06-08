#ifndef DIALOG2_H
#define DIALOG2_H
#include <QDebug>
#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class chimie;
}

class chimie : public Qchimie
{
    Q_OBJECT

public:
    explicit chimie(QWidget *parent = 0);
   void setnom(QString );
   void setmarque(QString );
   void setid_ch(QString);
   void setprix(QString);
   void setquantit(QString);
    ~chimie();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);

private:
    Ui::chimie *ui;
    QString name,marque;
    QString id_ch;
    QString prix;
    QString quantit;
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);
};

#endif // DIALOG2_H
