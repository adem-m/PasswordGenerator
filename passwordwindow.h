#ifndef PASSWORDWINDOW_H
#define PASSWORDWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <fstream>
#include <QIcon>
#include <QComboBox>

class passwordWindow : public QDialog
{
    Q_OBJECT

public:
    passwordWindow();

public slots:
    void afficher(int indice);

private:
    std::string chemin;
    std::string cheminLibelle;
    std::string cheminMdp;
    std::vector<std::string> tableauMdp;
    QLineEdit *affichage;
    QIcon *icone;
    QComboBox *liste;


};

#endif // PASSWORDWINDOW_H
