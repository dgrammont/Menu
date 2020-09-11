#ifndef MENU_H
#define MENU_H
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

enum erreurs
{
    CREATION,
    INDICE
};

class Menu{
private:
   string nom;
   string *options;
   int nbOptions;
   unsigned long longueurMax;
   int nbLignes;
public:
   Menu(const string &_nom);
   ~Menu();
   int Afficher();
   static void AttendreAppuiTouche();
};
class ErreurIndice
{
private:
    int codeErreur;
    string message;
public:
    ErreurIndice(int _codeErreur,
                 string _message);
    int ObtenirCodeErreur() const;
    string ObtenirDescription() const;
};
class ErreurCreation
{
private:
    int codeErreur;
    string message;
public:
    ErreurCreation(int _codeErreur,
                   string _message);
    int ObtenirCodeErreur() const;
    string ObtenirDescription() const;
};


#endif // MENU_H
