#ifndef PRODUITPH_H
#define PRODUITPH_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class physique
{
public:
    physique();
    physique(int,QString,QString,QString,QString);
    QString get_nom();
    QString get_marque();
    int get_id_phy();
    QString get_prix();
      QString get_dispo();

    bool modifier(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);
    //physique recherche(int);

private:
    QString nom,marque;
    int id_phy;
      QString dispo;
    QString prix;
};

#endif // PRODUITPH_H
