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
    // et le nombre le plus loin de x. Dans le cas ou x = 50 et que nous avons 51 et 49 par exemple
    // donc deux nombres, équidistants a x, dont un superieur a x et l'autre inferieur a x mais possèdant chacun exactement le même écard
    // vis à vis de x
    // j'implémenterais le code nécessaire pour gérer ce genre de cas.

    int X(0), tableau[5];

    //lePlusLoin bahhh euuu pour stocker le plus loin :D
    //lePlusProche bahhhh euu pour stocker le plus proche :D
    //Ces variables seront aux format string pour faire des concaténation
    // si le cas expliquer juste en haut dans les commentaires arrive


    //Variables qui serviront au traitenement pour les résultat finaux
    std::string lePlusLoin(""), lePlusProche("");
    int plusPetitEcart(0), plusGrandEcard(0);

    cout << "Tapez le nombre qui servira de comparaison avec les autres " << endl;
    cout << "le programme determinera quel est le plus proche et quel " << endl;
    cout << "est le plus loin de ce nombre dans une liste: ";

    cin >> X;
    cout << "Tapez 5 valeures: " << endl;
    for(int i(0); i<5; i++)
    {
        cout << "Tapez la "<<i+1<<" e valeure: " << endl;
        cin >> tableau[i];
    }

    //Je vais faire rendre le code apte de la manière suivante pour générer le cas à deux nombre équidistants de X
    //un for va gérer le nombre le plus loin et un autre le plus proche de  x inferieur à celui ci
    // par exemple X vaut 50 et on a 10 et 45 avec les variables nécessaires

    std::string lePlusLoinSousX(""), lePlusProcheSousX("");
    int plusPetitEcartSousX(0), plusGrandEcardSousX(0);

    //ensuite j'implémente deux for pour les nombres au dessus de X
    // 55 et 90 par exemple.

    std::string lePlusLoinOverX(""), lePlusProcheOverX("");
    int plusPetitEcartOverX(0), plusGrandEcardOverX(0);


    //Traitement dans la boucle pour obtenir le nombre le plus proche sous X
    for(int i(0); i<5;i++)
    {
        //Il faudra attribuer un premier nombre à la première itération
        // aux variables lePlusProche et lePlusLoin
        // sans comparaison, nécessaire pour commencer à comparer
        // même si ce n'est pas forcément vrai qu'il soit le plus proche ou le plus loin

        //la variable plusPetitEcartSousX est particulière
        // par default elle est initalisé à 0 ce qui signifique la condition pour vérifier les plus petit
        // coder dans le plusPetitEcartSousX>CalculEcart(X,tableau[i]) ne sera jamais valide peu importe les nombres rentré 0 sera toujours inferieur
        // et je ne l'ai pas jointe avec le if (i==0 && tableau[i]<X) car si un utilisateur tape le 1er nombre
        // superieur a x elle vaudra encore zero au premier tour et la condition dans plusPetitEcartSousX>CalculEcart(X,tableau[i])
        // sera invalide, c'est pour ça que je la code a part

        //Je n'ai pas besoin de faire quelque chose de spécial pour la variable plus grand écart sousX car même initaliser à 0
        // elle est voué à voir sa valeure croître
        if(i==0)
        {

            plusPetitEcartSousX = CalculEcart(X, tableau[i]);
            lePlusProcheSousX = std::to_string(tableau[i]);
        }

        if(i==0 && tableau[i]<X)
        {
            //Les affections n'auront aucun sens dans ce if
            // mais c'est juste histoire d'avoir une valeur dans chaque variables
            // pour démarrer les comparaison après le premier tour

            plusGrandEcardSousX = CalculEcart(X, tableau[i]);

            lePlusLoinSousX = std::to_string(tableau[i]);
        }

        //Les comparaisons peuvent débuter
        if(i>0 && tableau[i]<X)
        {

            //Si le nombre dans l'itération actuel possède un plus petit écard
            // que celui enregistré dans plusPetitEcart alors on mets à jour cette variable
            // et "lePlusProche" prend donc come valeur le nombre de l'itération en cours

            if(plusPetitEcartSousX>CalculEcart(X,tableau[i]))
            {

                  plusPetitEcartSousX = CalculEcart(X,tableau[i]);
                  lePlusProcheSousX = std::to_string(tableau[i]);

            }


            if(plusGrandEcardSousX<CalculEcart(X,tableau[i]))
            {

                  plusGrandEcardSousX = CalculEcart(X,tableau[i]);
                  lePlusLoinSousX = std::to_string(tableau[i]);

            }

        }
    }


     cout << "Le plus proche est: "<<lePlusProcheSousX << endl;
     cout << "Le plus loin est: "<<lePlusLoinSousX << endl;
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
