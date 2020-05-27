#ifndef NOURRITURE_H
#define NOURRITURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class nourriture
{
public:
    nourriture();
    nourriture(int,QString,int);
    QString get_nom();
    int get_id();
    int get_quantite();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);
    nourriture recherche(int);

    bool modifier(int,QString,int);
    QSqlQueryModel * trier_quantite();
    QSqlQueryModel * rechercher(int);


private:
    QString nom;
    int id,quantite;
};

#endif // NOURRITURE_H
