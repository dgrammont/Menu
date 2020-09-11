#include "menu.h"

Menu::Menu(const string &_nom):
    nom(_nom),
    longueurMax(0),
    nbLignes(0)
{


    ifstream leFichier(nom.c_str());
    string test;
    if(!leFichier.is_open())

    {
        ErreurCreation excep(CREATION,"Le ficher n'a pas été trouvé");
        throw(excep);
    }
    else
        nbLignes=static_cast<int>(count(istreambuf_iterator<char>(leFichier),istreambuf_iterator<char>(),'\n'));
    leFichier.seekg(0,ios::beg);
    if(nbLignes <= 0 ){
        ErreurCreation excep(CREATION,"Le ficher  est vide");
        throw(excep);
    }
    else{
        options = new string[nbLignes];

        for(int indice=0;indice<nbLignes;indice++)
        {
            if(indice <0  || indice >nbLignes)
            {
                ErreurIndice excep(INDICE, "L'indice du tableau n'est pas correct lors de l'affectation");
                throw(excep);
            }
            else
            {
                getline(leFichier,test);
                if(test=="")
                {
                    nbLignes--;

                    indice--;
                }
                else{

                    options[indice]=test;
                    options[indice].length();
                    if(options[indice].length()>longueurMax)
                    {
                        longueurMax=options[indice].length();
                    }
                }

            }
        }
    }
}

Menu::~Menu()
{
    delete [] options;
}

int Menu::Afficher()
{
    int choix;
    cout <<"+" << setfill('-') <<setw(6) << "+" << setfill('-') <<setw(longueurMax+2)<< "+"<< endl;
    for(int i=0;i<nbLignes;i++)
    {
        cout <<"| "  <<right<<setfill(' ')<<setw(2)<<i+1<<setw(3)<<" |"<<setw(longueurMax+1)<<left<<options[i]<<"|"  <<endl;
    }
    cout <<right<<"+" << setfill('-') <<setw(6) << "+" << setfill('-') <<setw(longueurMax+2)<< "+"<< endl;
    cout<<endl;
    cout<<"Entrer un nombre entre 1 et 5 : ";
    if(!(cin>>choix))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        choix=-1;
    }
    return choix;
}
void Menu::AttendreAppuiTouche()
{
    string uneChaine;
    cout<<endl<<"appuyersurlatoucheEntréepourcontinuer...";
    getline(cin,uneChaine);
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    system("clear");
}
ErreurIndice::ErreurIndice(int _codeErreur, string _message):
    codeErreur(_codeErreur),
    message(_message)
{
}
int ErreurIndice::ObtenirCodeErreur() const
{
    return codeErreur;
}
string ErreurIndice::ObtenirDescription() const
{
    return  message;
}
ErreurCreation::ErreurCreation(int _codeErreur, string _message):
    codeErreur(_codeErreur),
    message(_message)
{
}
int ErreurCreation::ObtenirCodeErreur() const
{
    return codeErreur;
}
string ErreurCreation::ObtenirDescription() const
{
    return message;
}
