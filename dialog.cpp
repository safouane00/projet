#include "dialog.h"
#include "produitch.h"
#include "produitph.h"

#include "ui_dialog.h"
#include <QMessageBox>


#include "tableprinter.h"
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    physique f;
     ui->tabF->setModel(f.afficher());
    chimie c;
      ui->tabC->setModel(c.afficher());

}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_validerC_clicked()
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

void Dialog::on_valider_4_clicked()
{
    chimie f;
     ui->tabC->setModel(f.trier());
}



void Dialog::on_valider_6_clicked()
{
    chimie o;
    int a= ui->lineEdit->text().toInt();
    ui->tabC->setModel(o.chercher(this,a));
}

void Dialog::on_ModifierC_clicked()
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

void Dialog::on_tabC_activated(const QModelIndex &index)
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

void Dialog::on_SupprimerC_clicked()
{
    int id_ch = ui->cinSC->text().toInt();
    bool test=tmpchimie.supprimer(id_ch);
    if(test)
    {ui->tabC->setModel(tmpchimie.afficher());
        QMessageBox::information(nullptr,QObject::tr("Supprimer un chimie"),QObject::tr("chimie supprimer.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->cinSC->clear();
}
/*class PrintBorder : public PagePrepare
{
public:
    virtual void preparePage(QPainter *painter);
    static int pageNumber;
};

int PrintBorder::pageNumber = 0;

void PrintBorder::preparePage(QPainter *painter)
{ // print a border on each page
    QRect rec = painter->viewport();
    painter->setPen(QPen(QColor(0, 0, 0), 1));
    painter->drawRect(rec);
    painter->translate(10, painter->viewport().height() - 10);
    painter->drawText(0, 0, QString("Page %1").arg(pageNumber));
    pageNumber += 1;
}
void Dialog::print(QPrinter *printer)  {

    // ------------------ simplest example --------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 5  << 15;
    if(!tablePrinter.printTable(ui->tabC->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}
void Dialog::print1(QPrinter *printer)  {

    // ------------------ simplest example --------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 5  << 15;
    if(!tablePrinter.printTable(ui->tabF->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}



void Dialog::print_two_tables(QPrinter *printer) {

    // ------------------ two tables example --------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 2 << 5 << 15;
    if(!tablePrinter.printTable(ui->tabC->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    // print second table
    painter.translate(0, 100);
    if(!tablePrinter.printTable(ui->tabC->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}
void Dialog::print_two_tables1(QPrinter *printer) {

    // ------------------ two tables example --------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 2 << 5 << 15;
    if(!tablePrinter.printTable(ui->tabF->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    // print second table
    painter.translate(0, 100);
    if(!tablePrinter.printTable(ui->tabF->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}

void Dialog::uglyPrint(QPrinter *printer) {

    // ---------------- death-to-designers example ------------------

    QPainter uglyPainter;
    if(!uglyPainter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    TablePrinter uglyTablePrinter(&uglyPainter, printer);
    QVector<int> colStretch = QVector<int>() << 5 << 5 << 5 << 5 << 5 ;
    uglyTablePrinter.setPen(QPen(QColor(0, 100, 255), 3, Qt::DotLine)); // pen for borders
    uglyTablePrinter.setHeaderColor(Qt::red);
    uglyTablePrinter.setContentColor(Qt::green);
    QFont font1; // font for headers
    font1.setBold(true);
    QFont font2; // font for content
    font2.setItalic(true);
    uglyTablePrinter.setHeadersFont(font1);
    uglyTablePrinter.setContentFont(font2);
    PrintBorder *printB = new PrintBorder;
    printB->pageNumber = 1;
    uglyTablePrinter.setPagePrepare(printB);
    QVector<QString> headers = QVector<QString>() << "ID" << "CULTURE" << "SURFACE"<< "TYPEA"<<"aaaaa" ;
    uglyPainter.setPen(QPen(Qt::yellow));
    uglyPainter.drawText(uglyPainter.viewport().width()/2 - 40, 40, "TABLE produits physiques");
    uglyPainter.translate(0, 60); // start print point
    uglyTablePrinter.setCellMargin(10, 5, 5);
    uglyTablePrinter.setPageMargin(100, 40, 40);
    if(!uglyTablePrinter.printTable(ui->tabC->model(), colStretch, headers)) {
        qDebug() << uglyTablePrinter.lastError();
    }
    uglyPainter.end();
    delete printB;
}
void Dialog::uglyPrint1(QPrinter *printer) {

    // ---------------- death-to-designers example ------------------

    QPainter uglyPainter;
    if(!uglyPainter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    TablePrinter uglyTablePrinter(&uglyPainter, printer);
    QVector<int> colStretch = QVector<int>() << 5 << 5 << 5 << 5 << 5 ;
    uglyTablePrinter.setPen(QPen(QColor(0, 100, 255), 3, Qt::DotLine)); // pen for borders
    uglyTablePrinter.setHeaderColor(Qt::red);
    uglyTablePrinter.setContentColor(Qt::green);
    QFont font1; // font for headers
    font1.setBold(true);
    QFont font2; // font for content
    font2.setItalic(true);
    uglyTablePrinter.setHeadersFont(font1);
    uglyTablePrinter.setContentFont(font2);
    PrintBorder *printB = new PrintBorder;
    printB->pageNumber = 1;
    uglyTablePrinter.setPagePrepare(printB);
    QVector<QString> headers = QVector<QString>() << "ID" << "CULTURE" << "SURFACE"<< "TYPEA"<<"aaaaa" ;
    uglyPainter.setPen(QPen(Qt::yellow));
    uglyPainter.drawText(uglyPainter.viewport().width()/2 - 40, 40, "TABLE plantes");
    uglyPainter.translate(0, 60); // start print point
    uglyTablePrinter.setCellMargin(10, 5, 5);
    uglyTablePrinter.setPageMargin(100, 40, 40);
    if(!uglyTablePrinter.printTable(ui->tabF->model(), colStretch, headers)) {
        qDebug() << uglyTablePrinter.lastError();
    }
    uglyPainter.end();
    delete printB;
}

void Dialog::on_SupprimerC_2_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(uglyPrint(QPrinter*)));
    dialog.exec();
}*/

void Dialog::on_valider_3_clicked()
{
    physique f;
     ui->tabF->setModel(f.trier());
}

void Dialog::on_valider_5_clicked()
{
    physique o;
    int a= ui->lineEdit_2->text().toInt();
    ui->tabF->setModel(o.chercher(this,a));
}

void Dialog::on_ModifierF_clicked()
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

void Dialog::on_tabF_activated(const QModelIndex &index)
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

void Dialog::on_SupprimerF_clicked()
{
    int id_phy = ui->cinS->text().toInt();
    bool test=tmpphysique.supprimer(id_phy);
    if(test)
    {ui->tabF->setModel(tmpphysique.afficher());
        QMessageBox::information(nullptr,QObject::tr("Supprimer un physique"),QObject::tr("physique supprimer.\n"
                                                                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->cinS->clear();
}

/*void Dialog::on_valider_2_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(uglyPrint1(QPrinter*)));
    dialog.exec();

}*/
bool Dialog::verifform1(){

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

void Dialog::on_valider_clicked()
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
class PrintBorder : public PagePrepare
{
public:
    virtual void preparePage(QPainter *painter);
    static int pageNumber;
};

int PrintBorder::pageNumber = 0;

void PrintBorder::preparePage(QPainter *painter)
{ // print a border on each page
    QRect rec = painter->viewport();
    painter->setPen(QPen(QColor(0, 0, 0), 1));
    painter->drawRect(rec);
    painter->translate(10, painter->viewport().height() - 10);
    painter->drawText(0, 0, QString("Page %1").arg(pageNumber));
    pageNumber += 1;
}
void Dialog::uglyPrint(QPrinter *printer) {

    // ---------------- death-to-designers example ------------------

    QPainter uglyPainter;
    if(!uglyPainter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    TablePrinter uglyTablePrinter(&uglyPainter, printer);
    QVector<int> colStretch = QVector<int>() << 5 << 5 << 5 << 5 << 5 ;
    uglyTablePrinter.setPen(QPen(QColor(0, 100, 255), 3, Qt::DotLine)); // pen for borders
    uglyTablePrinter.setHeaderColor(Qt::red);
    uglyTablePrinter.setContentColor(Qt::green);
    QFont font1; // font for headers
    font1.setBold(true);
    QFont font2; // font for content
    font2.setItalic(true);
    uglyTablePrinter.setHeadersFont(font1);
    uglyTablePrinter.setContentFont(font2);
    PrintBorder *printB = new PrintBorder;
    printB->pageNumber = 1;
    uglyTablePrinter.setPagePrepare(printB);
    QVector<QString> headers = QVector<QString>() << "ID" << "CULTURE" << "SURFACE"<< "TYPEA"<<"aaaaa" ;
    uglyPainter.setPen(QPen(Qt::yellow));
    uglyPainter.drawText(uglyPainter.viewport().width()/2 - 40, 40, "TABLE plantes");
    uglyPainter.translate(0, 60); // start print point
    uglyTablePrinter.setCellMargin(10, 5, 5);
    uglyTablePrinter.setPageMargin(100, 40, 40);
    if(!uglyTablePrinter.printTable(ui->tabC->model(), colStretch, headers)) {
        qDebug() << uglyTablePrinter.lastError();
    }
    uglyPainter.end();
    delete printB;
}
void Dialog::uglyPrint1(QPrinter *printer) {

    // ---------------- death-to-designers example ------------------

    QPainter uglyPainter;
    if(!uglyPainter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    TablePrinter uglyTablePrinter(&uglyPainter, printer);
    QVector<int> colStretch = QVector<int>() << 5 << 5 << 5 << 5 << 5 ;
    uglyTablePrinter.setPen(QPen(QColor(0, 100, 255), 3, Qt::DotLine)); // pen for borders
    uglyTablePrinter.setHeaderColor(Qt::red);
    uglyTablePrinter.setContentColor(Qt::green);
    QFont font1; // font for headers
    font1.setBold(true);
    QFont font2; // font for content
    font2.setItalic(true);
    uglyTablePrinter.setHeadersFont(font1);
    uglyTablePrinter.setContentFont(font2);
    PrintBorder *printB = new PrintBorder;
    printB->pageNumber = 1;
    uglyTablePrinter.setPagePrepare(printB);
    QVector<QString> headers = QVector<QString>() << "ID" << "CULTURE" << "SURFACE"<< "TYPEA"<<"aaaaa" ;
    uglyPainter.setPen(QPen(Qt::yellow));
    uglyPainter.drawText(uglyPainter.viewport().width()/2 - 40, 40, "TABLE plantes");
    uglyPainter.translate(0, 60); // start print point
    uglyTablePrinter.setCellMargin(10, 5, 5);
    uglyTablePrinter.setPageMargin(100, 40, 40);
    if(!uglyTablePrinter.printTable(ui->tabF->model(), colStretch, headers)) {
        qDebug() << uglyTablePrinter.lastError();
    }
    uglyPainter.end();
    delete printB;
}


void Dialog::on_SupprimerC_2_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(uglyPrint(QPrinter*)));
    dialog.exec();

}

void Dialog::on_valider_2_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(uglyPrint1(QPrinter*)));
    dialog.exec();

}
