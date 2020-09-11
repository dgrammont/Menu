#include <iostream>
#include <menu.h>

using namespace std;
enum CHOIX_MENU
{
    OPTION_1 = 1,
    OPTION_2,
    OPTION_3,
    OPTION_4,
    QUITTER
};

int main()
{
    try {

    int choix;
    Menu leMenu("menu.txt");
    Menu leMenu1("menu1.txt");
    do
    {
        choix = leMenu.Afficher();
        switch (choix)
        {
        case OPTION_1:
            leMenu1.Afficher();

            Menu::AttendreAppuiTouche();
            break;
        case OPTION_2:
            cout <<"Vous avez choisi l'option n°2"<<endl;
            Menu::AttendreAppuiTouche();
            break;
        case OPTION_3:
            cout <<"Vous avez choisi l'option n°3"<<endl;
            Menu::AttendreAppuiTouche();
            break;
        case OPTION_4:
            cout <<"Vous avez choisi l'option n°4"<<endl;
            Menu::AttendreAppuiTouche();
            break;
        /*case OPTION_5:
            cout <<"Vous avez choisi l'option n°5"<<endl;
            Menu::AttendreAppuiTouche();
            break;*/
        }
    }while (choix !=QUITTER);
}
    catch (ErreurIndice const &exp) {
            cout<<"Erreur " <<exp.ObtenirCodeErreur()<<endl;
            cout<<exp.ObtenirDescription()<<endl;
            exit(EXIT_FAILURE);
        }
    catch (ErreurCreation const &exp) {
            cout<<"Erreur " <<exp.ObtenirCodeErreur()<<endl;
            cout<<exp.ObtenirDescription()<<endl;
            exit(EXIT_FAILURE);
        }

    return 0;
}
