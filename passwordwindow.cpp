#include "passwordwindow.h"
#include <QPushButton>

passwordWindow::passwordWindow() : QDialog()
{
    setWindowTitle("Mots de passe");
    setFixedSize(350, 60);
    icone = new QIcon("icon.png");
    setWindowIcon(*icone);

    cheminMdp = "dataM.pgg";
    cheminLibelle = "dataL.pgg";

    tableauMdp.push_back("Mot de passe");

    std::ifstream fluxMdp(cheminMdp.c_str());
    if(fluxMdp)
    {
        std::string ligne;
        while(std::getline(fluxMdp, ligne))
        {
            tableauMdp.push_back(ligne);
        }
    }

    affichage = new QLineEdit("Mot de passe", this);
    affichage->setReadOnly(true);
    affichage->move(200,20);
    affichage->setCursor(Qt::IBeamCursor);

    liste = new QComboBox(this);
    liste->move(20,20);
    liste->setCursor(Qt::PointingHandCursor);
    liste->insertItem(1, "Sélectionner");

    std::ifstream fluxLibelle(cheminLibelle.c_str());
    if(fluxLibelle)
    {
        int n=2;
        std::string line;
        while(std::getline(fluxLibelle, line))
        {
            liste->insertItem(n, QString::fromStdString(line));
            n++;
        }
    }

    connect(liste, SIGNAL(activated(int)), this, SLOT(afficher(int)));
}
void passwordWindow::afficher(int indice)
{
    affichage->setText(QString::fromStdString(tableauMdp[indice]));
}
