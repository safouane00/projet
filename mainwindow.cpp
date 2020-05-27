#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AfficherF_clicked()
{
    ;
    ui->tabF->setModel(tmpanimaux.afficher());
}

void MainWindow::on_SupprimerF_clicked()
{
    int idp = ui->idS->text().toInt();
    bool test=tmpanimaux.supprimer(idp);
    if(test)
    {ui->tabF->setModel(tmpanimaux.afficher());
        QMessageBox::information(nullptr,QObject::tr("Supprimer un animaux"),QObject::tr("animaux supprimer.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->idS->clear();
}

void MainWindow::on_ModifierF_clicked()
{




    int id = ui->idp->text().toInt();
     QString nom= ui->nom->text();
          int prix= ui->prix->text().toInt();
          int masse= ui->masse->text().toInt();
         animaux f;
         bool test=f.modifier(id,nom,prix,masse);
       if(test)
         {
            ui->tabF->setModel((tmpanimaux.afficher()));//refresh
            QMessageBox::information(nullptr, QObject::tr("Modifier une animaux !"),
                              QObject::tr(" animaux modifié ! \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
         }

         else {

             QMessageBox::critical(nullptr, QObject::tr("Modifier une animaux"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }
}

void MainWindow::on_valider_clicked()
{
     int id =ui->idp->text().toInt();
    QString nom=ui->nom->text();
    int prix=ui->prix->text().toInt();

    int masse =ui->masse->text().toInt();
    animaux f(id,nom,prix,masse);
    bool test=f.ajouter();
    if(test)
    {ui->tabF->setModel(tmpanimaux.afficher());
    QMessageBox::information(nullptr,QObject::tr("Ajouter un animaux"),QObject::tr("animaux ajouter.\n"
                                                                                    "Click Cancel to exit."), QMessageBox::Cancel);}
     ui->idp->clear();
    ui->nom->clear();
    ui->prix->clear();

    ui->masse->clear();
}


void MainWindow::on_AfficherC_clicked()
{
    ui->tabC->setModel(tmpnourriture.afficher());
}


void MainWindow::on_SupprimerC_clicked()
{
    int idp = ui->idSC->text().toInt();
    bool test=tmpnourriture.supprimer(idp);
    if(test)
    {ui->tabC->setModel(tmpnourriture.afficher());
        QMessageBox::information(nullptr,QObject::tr("Supprimer un nourriture"),QObject::tr("nourriture supprimer.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->idSC->clear();
}







void MainWindow::on_validerC_clicked()
{   int id =ui->idpC->text().toInt();
    QString nom=ui->nomC->text();



    int quantite =ui->quantiteC->text().toInt();

    nourriture c(id,nom,quantite);
    bool test=c.ajouter();
    if(test)
    {ui->tabC->setModel(tmpnourriture.afficher());
    QMessageBox::information(nullptr,QObject::tr("Ajouter un nourriture"),QObject::tr("nourriture ajouter.\n"
                                                                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->idpC->clear();
    ui->nomC->clear();



    ui->quantiteC->clear();

}








void MainWindow::on_ModifierC_clicked()
{
    int id = ui->idpC->text().toInt();
     QString nom= ui->nomC->text();


          int quantite= ui->quantiteC->text().toInt();
         nourriture f;
         bool test=f.modifier(id,nom,quantite);
       if(test)
         {
            ui->tabC->setModel((tmpnourriture.afficher()));//refresh
            QMessageBox::information(nullptr, QObject::tr("Modifier une nourriture !"),
                              QObject::tr(" nourriture modifié ! \n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
         }

         else {

             QMessageBox::critical(nullptr, QObject::tr("Modifier une nourriture"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }


}

void MainWindow::on_pushButton_clicked()
{

    bool test=true;
            if(test){

                   { ui->tabF->setModel(tmpanimaux.trier_prix());
                    QMessageBox::information(nullptr, QObject::tr("trier animaux"),
                                QObject::tr("animaux trier.\n"
                                            "Voulez-vous enregistrer les modifications ?"),
                                       QMessageBox::Save
                                       | QMessageBox::Cancel,
                                      QMessageBox::Save);
    }

                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("trier animaux"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    bool test=true;
            if(test){

                   { ui->tabC->setModel(tmpnourriture.trier_quantite());
                    QMessageBox::information(nullptr, QObject::tr("trier nourriture"),
                                QObject::tr("nourriture trier.\n"
                                            "Voulez-vous enregistrer les modifications ?"),
                                       QMessageBox::Save
                                       | QMessageBox::Cancel,
                                      QMessageBox::Save);
    }

                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("trier plantes"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_3_clicked()
{
    bool test=true;
            if(test){

                   { ui->tabF->setModel(tmpanimaux.trier_masse());
                    QMessageBox::information(nullptr, QObject::tr("trier animaux"),
                                QObject::tr("animaux trier.\n"
                                            "Voulez-vous enregistrer les modifications ?"),
                                       QMessageBox::Save
                                       | QMessageBox::Cancel,
                                      QMessageBox::Save);
    }

                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("trier animaux"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{

    {
        int id = ui->idS->text().toInt();
       ui->tabF->setModel(tmpanimaux.rechercher(id));

    }
}

void MainWindow::on_pushButton_5_clicked()
{
    {
        int id = ui->idSC->text().toInt();
       ui->tabC->setModel(tmpnourriture.rechercher(id));

    }
}
