#include "dialog2.h"
#include "ui_dialog2.h"
#include "mainwindow.h"
#include <QDebug>

chimie::chimie(QWidget *parent) :
        chimie(parent),
        ui(new Ui::chimie)
{

    ui->setupUi(this);

}

chimie::~chimie()
{
    delete ui;
}

void chimie::setnom(QString n)
{
    ui->lineEdit_nom->setText(n);
}

void chimie::setmarque(QString n)
{
    ui->lineEdit_prenom->setText(n);
}
void chimie::setid_ch(QString n)
{
ui->lineEdit_cin->setText(n);
}

void chimie::setprix(QString n)
{
ui->lineEdit_prix->setText(n);
}

void chimie::setquantit(QString n)
{
ui->lineEdit_quantit->setText(n);
}


chimie::chimie()
{
    nom="";
    marque="";
    id_ch=0;
    prix="";
    quantit=0;

}

chimie::chimie(QString nom,QString marque,int id_ch,QString mail,int quantit)
{
    this->nom=nom;
    this->prenom=prenom;
    this->=id_ch;
    this->prix=prix;
    this->quantit=quantit;
}

QString chimie::get_nom(){return nom;}
QString chimie::get_marque(){return marque;}
int chimie::get_id_ch(){return id_ch;}
QString chimie::get_prix(){return prix;}
int chimie::get_quantit(){return quantit;}

bool chimie::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id_ch);
    query.prepare("INSERT INTO fournisseur (nom, marque, id_ch, prix, quantit) "
                          " VALUES (:nom, :marque, :id_ch, :prix, :quantit)" );

    query.bindValue(":nom", nom);
    query.bindValue(":marque", marque);
    query.bindValue(":id_ch", res);
    query.bindValue(":prix", prix);
    query.bindValue(":quantit", quantit);
    return  query.exec();
}

QSqlQueryModel * chimie::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from chimie");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_ch"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantit"));
    return model;
}


