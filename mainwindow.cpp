#include "mainwindow.h"
#include <iostream>

mainWindow::mainWindow() : QWidget()
{
    nbCaracteres = 8;
    cheminLibelle = "dataL.pgg";
    cheminMdp = "dataM.pgg";
    doublon = true;

    icone = new QIcon("icon.png");

    setWindowTitle("Générateur de mot de passe");
    setFixedSize(500, 500);
    setWindowIcon(*icone);

    boutonGenerer = new QPushButton("Générer", this);
    boutonGenerer->setCursor(Qt::PointingHandCursor);
    boutonGenerer->move(200,400);

    boutonSave = new QPushButton("Enregistrer", this);
    boutonSave->move(360, 348);
    boutonSave->setCursor(Qt::PointingHandCursor);

    boutonAfficher = new QPushButton("Afficher les mots de passe enregistrés", this);
    boutonAfficher->move(10,460);
    boutonAfficher->setCursor(Qt::PointingHandCursor);

    texte = new QLabel("Bienvenue dans mon générateur de mot de passe \n \nIl suffit simplement de choisir le nombre de caractères \nsouhaités puis de cliquer sur Générer \nLe mot de passe généré peut être enregistré", this);
    texte->move(100, 50);

    texte2 = new QLabel("Nombre de caractères", this);
    texte2->move(180,180);

    champ = new QLineEdit("Mot de passe", this);
    champ->move(180, 350);
    champ->setReadOnly(true);
    champ->setCursor(Qt::IBeamCursor);

    bouton8 = new QRadioButton("8", this);
    bouton8->setChecked(true);
    bouton12 = new QRadioButton("12", this);
    bouton16 = new QRadioButton("16", this);

    vbox = new QVBoxLayout(this);
    vbox->addWidget(bouton8);
    vbox->addWidget(bouton12);
    vbox->addWidget(bouton16);

    QGroupBox *groupeNbCarac = new QGroupBox(this);
    groupeNbCarac->setLayout(vbox);
    groupeNbCarac->move(210, 200);


    connect(boutonGenerer, SIGNAL(clicked()), this, SLOT(generation()));
    connect(bouton8, SIGNAL(clicked()), this, SLOT(setNb8()));
    connect(bouton12, SIGNAL(clicked()), this, SLOT(setNb12()));
    connect(bouton16, SIGNAL(clicked()), this, SLOT(setNb16()));
    connect(boutonSave, SIGNAL(clicked()), this, SLOT(sauvegarde()));
    connect(boutonAfficher, SIGNAL(clicked()), this, SLOT(creationFenetrePass()));
}

void mainWindow::generation()
{
    int i;
    int n=0;
    int cursor;
    char password[nbCaracteres];
    int ordre[nbCaracteres];
    int nombres[nbCaracteres];
    QString finalPassword(nbCaracteres, '\0');

    srand (time(NULL));

    cursor=0;
    n=0;

    for (i=0; i<nbCaracteres/4; i++)                     // Génère majuscules
    {
        password[cursor] = rand()%25 + 65;
        cursor++;
    }

    for (i=0; i<nbCaracteres/4; i++)                     // Génère minuscules
    {
        password[cursor] = rand()%25 + 97;
        cursor++;
    }

    for (i=0; i<nbCaracteres/4; i++)                     // Génère chiffres
    {
        password[cursor] = rand()%10 + 48;
        cursor++;
    }

    for (i=0; i<nbCaracteres/4; i++)                     // Génère caractères spéciaux
    {
        password[cursor] = rand()%14 + 33;
        cursor++;
    }


    cursor = 0;



    for (i=0; i<nbCaracteres; i++)
    {
        nombres[i]=i;
        ordre[i]=9;
    }

    while (n<nbCaracteres)
    {
        cursor = rand()%nbCaracteres;
        if (ordre[cursor]==9)
        {
            ordre[cursor] = nombres[n];
            n++;
        }
    }

    for (i=0; i<nbCaracteres; i++)
    {
        finalPassword[i] = password[ordre[i]];
    }

    dernierMdp = finalPassword;
    doublon = false;

    champ->setText(finalPassword);
}
void mainWindow::setNbCaracteres(int n)
{
    nbCaracteres = n;
}
void mainWindow::setNb8()
{
    nbCaracteres = 8;
}
void mainWindow::setNb12()
{
    nbCaracteres = 12;
}
void mainWindow::setNb16()
{
    nbCaracteres = 16;
}
void mainWindow::sauvegarde()
{
    QString libelle;
    bool ok=false;

    if(!dernierMdp.isEmpty() && !doublon)
    {
        do
        {
            libelle = QInputDialog::getText(this, "Libellé", "Veuillez entrer un libellé", QLineEdit::Normal, QString(), &ok);
        }
        while(libelle.isEmpty() && ok);
        if(ok)
        {
            std::ofstream fluxLibelle(cheminLibelle.c_str(), std::ios::app);
            std::ofstream fluxMdp(cheminMdp.c_str(), std::ios::app);
            if(fluxLibelle)
            {
                fluxLibelle << libelle.toStdString() <<std::endl;
                QMessageBox::information(this, "Information", "Votre mot de passe a bien été sauvegardé");
            }
            if(fluxMdp)
            {
                fluxMdp << dernierMdp.toStdString() << std::endl;
            }
            doublon = true;
        }
    }
}
void mainWindow::creationFenetrePass()
{
    fenetreMdp = new passwordWindow();
    fenetreMdp->exec();
}
