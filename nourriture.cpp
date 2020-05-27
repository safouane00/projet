#include "nourriture.h"

nourriture::nourriture()
{
    nom="";

    id=0;
    quantite=0;

}

nourriture::nourriture(int id,QString nom,int quantite)
{
    this->nom=nom;

    this->id=id;
    this->quantite=quantite;
}
int nourriture::get_id(){return id;}
QString nourriture::get_nom(){return nom;}


int nourriture::get_quantite(){return quantite;}

bool nourriture::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO nourriture (nom, id,  quantite) "
                          " VALUES (:nom, :id,  :quantite)" );
query.bindValue(":id", res);
    query.bindValue(":nom", nom);


    query.bindValue(":quantite", quantite);
    return  query.exec();

}

QSqlQueryModel * nourriture::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from nourriture");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));


    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
    return model;
}

bool nourriture::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from nourriture where id = :id");
    query.bindValue(":id", res);
    return  query.exec();
}

nourriture nourriture::recherche(int x)
{
    QSqlQuery query;
    QString res= QString::number(x);
    query.prepare("select * from nourriture where id = : res ");
    query.bindValue(":id",res);
    QString nom=query.value(0).toString();

    int id=query.value(2).toInt();

    int quantite=query.value(4).toInt();
    nourriture f(id,nom,quantite);
    return  f;

}

bool nourriture::modifier(int id,QString nom,int quantite)
{ QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE nourriture SET nom=:nom,quantite=:quantite where ID=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);

    query.bindValue(":quantite",quantite);

    return query.exec();

}

QSqlQueryModel * nourriture::trier_quantite()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from nourriture ORDER BY quantite");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom "));

        return model;
}
QSqlQueryModel *  nourriture::rechercher(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select * from nourriture where (id LIKE '"+res+"%' ) ");


            return  model;


}

