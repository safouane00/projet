#ifndef ANIMAUX_H
#define ANIMAUX_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class animaux
{
public:
    animaux();
    animaux(int,QString,int,int);
    QString get_nom();
    int get_prix();
    int get_id();
    int get_masse();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);
    animaux recherche(int);
    bool modifier(int,QString,int,int);
    QSqlQueryModel * trier_prix();
    QSqlQueryModel * trier_masse();
    QSqlQueryModel * rechercher(int);

private:
    QString nom;
    int id,prix,masse;
};

#endif // ANIMAUX_H
