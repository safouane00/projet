#include "animaux.h"

animaux::animaux()
{
   nom="";
    masse=0;
    id=0;
    prix=0;

}

animaux::animaux(int id,QString nom,int masse,int prix)
{
    this->nom=nom;
    this->masse=masse;
    this->id=id;
    this->prix=prix;
}

QString animaux::get_nom(){return nom;}
int animaux::get_masse(){return masse;}
int animaux::get_id(){return id;}
int animaux::get_prix(){return prix;}

bool animaux::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO animaux (nom, masse, id,  prix) "
                          " VALUES (:nom, :masse, :id,  :prix)" );

    query.bindValue(":nom", nom);
    query.bindValue(":masse", masse);
    query.bindValue(":id", res);
    query.bindValue(":prix", prix);
    return  query.exec();

}

QSqlQueryModel * animaux::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from animaux");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("masse"));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    return model;
}

bool animaux::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from animaux where id = :id");
    query.bindValue(":id", res);
    return  query.exec();
}



animaux animaux::recherche(int x)
{
    QSqlQuery query;
    QString res= QString::number(x);
    query.prepare("select * from animaux where id = : res ");
    query.bindValue(":id",res);
    QString nom=query.value(0).toString();
    int masse=query.value(1).toInt();
    int id=query.value(2).toInt();

    int prix=query.value(4).toInt();
    animaux f(id,nom,masse,prix);
    return  f;

}
bool animaux::modifier(int id,QString nom,int prix,int masse)
{ QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE animaux SET NOM=:nom,PRIX:=prix,MASSE:=masse where ID=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prix",prix);
    query.bindValue(":masse",masse);

    return query.exec();

}


QSqlQueryModel * animaux::trier_prix()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from animaux ORDER BY prix");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("masse"));
        return model;
}

QSqlQueryModel * animaux::trier_masse()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from animaux ORDER BY masse");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("masse"));
        return model;
}
QSqlQueryModel *  animaux::rechercher(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select * from animaux where (id LIKE '"+res+"%' ) ");


            return  model;


}


