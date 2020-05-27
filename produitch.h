#ifndef PRODUITCH_H
#define PRODUITCH_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class chimie
{
public:

    chimie();
    chimie(QString,QString,int,QString,QString);

    QString get_marque();
    QString get_nom();
    int get_id_ch();
    QString  get_prix();
    QString get_quantit();

    bool modifier(int a);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);

private:

    QString marque,nom;
    int id_ch;
    QString  prix,quantit;


};

#endif // PRODUITCH_H
