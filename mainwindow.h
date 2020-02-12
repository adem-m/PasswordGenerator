#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "passwordwindow.h"

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <fstream>
#include <QInputDialog>
#include <QMessageBox>
#include <QIcon>

class mainWindow : public QWidget
{
    Q_OBJECT

public:
    mainWindow();

public slots:
    void generation();
    void sauvegarde();
    void setNbCaracteres(int n);
    void setNb8();
    void setNb12();
    void setNb16();
    void creationFenetrePass();

private:
    int nbCaracteres;
    bool doublon;
    std::string cheminLibelle;
    std::string cheminMdp;
    QString dernierMdp;
    QPushButton *boutonGenerer;
    QPushButton *boutonSave;
    QPushButton *boutonAfficher;
    QLabel *texte;
    QLabel *texte2;
    QLineEdit *champ;
    QRadioButton *bouton8;
    QRadioButton *bouton12;
    QRadioButton *bouton16;
    QVBoxLayout *vbox;
    QIcon *icone;

    passwordWindow *fenetreMdp;


};

#endif // MAINWINDOW_H
