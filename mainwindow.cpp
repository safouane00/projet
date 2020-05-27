#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


     chimie c;

       physique p;

       ui->tabF->setModel(p.afficher());
       ui->tabF->setModel(c.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}


//PHYYYYYYYYYYYSIIIIIIIIIQUUUUUUUUUUUE


void MainWindow::on_AfficherF_clicked()
{
    ui->tabF->setModel(tmpphysique.afficher());
}

void MainWindow::on_SupprimerF_clicked()
{
    int id_phy = ui->cinS->text().toInt();
    bool test=tmpphysique.supprimer(id_phy);
    if(test)
    {ui->tabF->setModel(tmpphysique.afficher());
        QMessageBox::information(nullptr,QObject::tr("Supprimer un physique"),QObject::tr("physique supprimer.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->cinS->clear();
}


bool MainWindow::verifform1(){

   if(ui->Cinn->text()!="" && ui->Nom->text()!="" && ui->Mail->text()!="" && ui->Prenom->text()!="" && ui->radioButton->isChecked() && !ui->radioButton_2->isChecked())
   {
       return true;
   }
   if(ui->Cinn->text()!="" && ui->Nom->text()!="" && ui->Mail->text()!="" && ui->Prenom->text()!="" && !ui->radioButton->isChecked() && ui->radioButton_2->isChecked())
   {
       return true;
   }
   return false;

}
void MainWindow::on_valider_clicked()
{


    if(!verifform1()){
        QMessageBox::critical(nullptr,QObject::tr("ajout unsuccessful"),QObject::tr("verifier vos parametres.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{

        int id_phy =ui->Cinn->text().toInt();
        QString nom=ui->Nom->text();
        QString marque=ui->Prenom->text();
        QString prix =ui->Mail->text();
       QString dispo;
        if(ui->radioButton->isChecked()){
           dispo="disponible";
        }
        else{
           dispo="nondisponible";
        }





        physique f(id_phy,nom,marque,prix,dispo);
        bool test=f.ajouter();
        if(test)
        {ui->tabF->setModel(tmpphysique.afficher());
        QMessageBox::information(nullptr,QObject::tr("Ajouter un physique"),QObject::tr("physique ajouter.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
        ui->Cinn->clear();
        ui->Nom->clear();
        ui->Prenom->clear();
        ui->Mail->clear();
        ui->radioButton->clearMask();
        ui->radioButton_2->clearMask();
    }

}


//CHIIIIIIIIMIIIIIIIIIIIIIIIIIIIIEEEEEEE


void MainWindow::on_AfficherC_clicked()
{
    ui->tabC->setModel(tmpchimie.afficher());
}


void MainWindow::on_SupprimerC_clicked()
{
    int id_ch = ui->cinSC->text().toInt();
    bool test=tmpchimie.supprimer(id_ch);
    if(test)
    {ui->tabC->setModel(tmpchimie.afficher());
        QMessageBox::information(nullptr,QObject::tr("Supprimer un chimie"),QObject::tr("chimie supprimer.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->cinSC->clear();
}



void MainWindow::on_validerC_clicked()
{

    QString nom =ui->NomC->text();
    QString marque= ui->PrenomC->text();
    int id_ch =ui->CinnC->text().toInt();
    QString prix =ui->NumeroC->text();
    QString quantit =ui->NombreA->text();


    chimie c(nom,marque,id_ch,prix,quantit);
    bool test=c.ajouter();
    if(test)
    {ui->tabC->setModel(tmpchimie.afficher());
    QMessageBox::information(nullptr,QObject::tr("Ajouter un chimie"),QObject::tr("chimie ajouter.\n"
                                                                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->NomC->clear();
    ui->PrenomC->clear();
    ui->CinnC->clear();
    ui->NumeroC->clear();
    ui->NombreA->clear();

}







void MainWindow::on_tabF_activated(const QModelIndex &index)
{
    int a=ui->tabF->model()->data(index).toInt();
ui->label->setNum(a);
    QSqlQuery q;
    q.prepare("select * from physique where id_phy = ?;");
     q.addBindValue(a);
     if(q.exec()){
         while(q.next()){
             ui->Cinn->setText(q.value(0).toString());
             ui->Nom->setText(q.value(1).toString());
             ui->Prenom->setText(q.value(2).toString());
             ui->Mail->setText(q.value(3).toString());

              if(q.value(4).toString()=="disponible"){
                  ui->radioButton->setChecked(true);
                  ui->radioButton_2->setChecked(false);
              }
              else
              {
                  ui->radioButton->setChecked(false);
                  ui->radioButton_2->setChecked(true);

              }



         }
     }
}



void MainWindow::on_ModifierF_clicked()
{
    int a=ui->label->text().toInt();

    QString b= ui->Nom->text();
    QString c= ui->Prenom->text();
    QString d= ui->Mail->text();
    QString e;
    if(ui->radioButton->isChecked()){
       e="disponible";
    }
    else{
       e="nondisponible";
    }

    physique o(a,b,c,d,e);
    if(o.modifier(a)){
        ui->tabF->setModel(o.afficher());


    }

}

void MainWindow::on_tabC_activated(const QModelIndex &index)
{
    int a=ui->tabC->model()->data(index).toInt();
ui->label_2->setNum(a);
    QSqlQuery q;
    q.prepare("select * from chimie where id_ch = ?;");
     q.addBindValue(a);
     if(q.exec()){
         while(q.next()){
             ui->NomC->setText(q.value(0).toString());
             ui->PrenomC->setText(q.value(1).toString());
             ui->CinnC->setText(q.value(2).toString());
             ui->NumeroC->setText(q.value(3).toString());
              ui->NombreA->setText(q.value(4).toString());



         }
     }

}

void MainWindow::on_ModifierC_clicked()
{
    int a=ui->label_2->text().toInt();

    QString b= ui->NomC->text();
    QString c= ui->PrenomC->text();
    QString d= ui->NumeroC->text();
    QString e=ui->NombreA->text();


    chimie o(b,c,a,d,e);
    if(o.modifier(a)){
        ui->tabC->setModel(o.afficher());


    }
}
