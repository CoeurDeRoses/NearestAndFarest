#include <iostream>
#include "unfichier.h"
#include <string>

using namespace std;

int main()
{

    string recommencer;
    do
    {

    //Le programme a pour but d'afficher le nombre le plus proche d'un nombre x déterminé par l'utilisateur
    // et le nombre le plus loin de x, dans le cas ou x = 50 et que nous avons 51 et 19 par exemple
    // donc deux nombres, dont un superieur a x et l'autre inferieur a x mais possèdant chacun exactement le même écard
    // vis à vis de x
    // pour l'instant, je n'implémenterais pas le code nécessaire pour gérer ce genre de cas.
    //  suite à plusieurs tentatives de réalisation de cette algo... échouées

    int choixUser(0), tableau[5];

    //lePlusLoin bahhh euuu pour stocker le plus loin :D
    //lePlusProche bahhhh euu pour stocker le plus proche :D
    //Ces variables seront aux format string pour faire des concaténation
    // si le cas expliquer juste en haut dans les commentaires arrive


    std::string lePlusLoin(""), lePlusProche("");

    //Les variables ecart serviront pour les comparaisons dans la boucle
    int plusPetitEcart(0), plusGrandEcard(0);

    cout << "Tapez le nombre qui servira de comparaison avec les autres " << endl;
    cout << "le programme determinera quel est le plus proche et quel " << endl;
    cout << "est le plus loin de ce nombre dans une liste: ";

    cin >> choixUser;
    cout << "Tapez 5 valeures: " << endl;
    for(int i(0); i<5; i++)
    {
        cout << "Tapez la "<<i+1<<" e valeure: " << endl;
        cin >> tableau[i];
    }

    //Traitement dans la boucle pour obtenir le nombre le plus éloigné et le plus proche
    for(int i(0); i<5;i++)
    {
        //Il faudra attribuer un premier nombre à la première itération
        // aux variables lePlusProche et lePlusLoin
        // sans comparaison, nécessaire pour commencer à comparer
        // même si ce n'est pas forcément vrai qu'il soit le plus proche ou le plus loin

        if(i==0)
        {
            //Les affections n'auront aucun sens dans ce if
            // mais c'est juste histoire d'avoir une valeur dans chaque variables
            // pour démarrer les comparaison après le premier tour


            plusGrandEcard = CalculEcart(choixUser, tableau[i]);
            plusPetitEcart = CalculEcart(choixUser, tableau[i]);


            lePlusProche = std::to_string(tableau[i]);
            lePlusLoin = std::to_string(tableau[i]);
        }

        //Les comparaisons peuvent débuter
        if(i>0)
        {
            //Si le nombre dans l'itération actuel possède un plus petit écard
            // que celui enregistré dans plusPetitEcart alors on mets à jour cette variable
            // et "lePlusProche" prend donc come valeur le nombre de l'itération en cours


            if(plusPetitEcart>CalculEcart(choixUser,tableau[i]))
            {
                  plusPetitEcart = CalculEcart(choixUser,tableau[i]);
                  lePlusProche = std::to_string(tableau[i]);
            }

            //On applique la même logique pour lePlusLoin
            if(plusGrandEcard<CalculEcart(choixUser,tableau[i]))
            {
                  plusGrandEcard = CalculEcart(choixUser,tableau[i]);
                  lePlusLoin = std::to_string(tableau[i]);
            }

        }
    }

     cout << "Le plus proche est: "<<lePlusProche << endl;
     cout << "Le plus loin est: "<<lePlusLoin << endl;
     cout << "Voulez vous recommencer ?Tapez Tapez la lettre o  pour recommecer ou une autre pour arreter."<<endl;
     cout << "puis entrer pour confirmer: ";

     cin>>recommencer;


    }while(recommencer=="o");
    return 0;
}

//nbUser pour le nombre à comparé et
//nb pour le nombre en cours d'itération dans la seconde boucle for
int CalculEcart(int nbUser, int nb){

    //Il faut déterminer d'abord le sens ou on compte l'écart
    // Si le nombre du tableau est inférieur au nombre à comparé
    // on incrémente si il est supérieur on décremente
    //Une variable de compteur servira a décrémenter ou incrémenter
    int compteurEcart(0);

    // si le nombre à comparé est superieur
    if(nbUser>nb)
    {   //i(nb) on compte à partir du nombre jusqu'a nbUser
        for(int i(nb); i<nbUser; i++)
        {
            compteurEcart++;
        }
    }

    // si il est inferieur
    if(nbUser<nb)
    {
        for(int i(nb); i>nbUser; i--)
        {
            compteurEcart++;
        }
    }

    return compteurEcart;
}


