#include <iostream>
#include "Catalogue.h"
#include "TrajetCompose.h"

using namespace std;






/**
 * c'est methode permet à l'utilisateur de choisir un moyen de transport
 * dans la liste des moyens disponible
 * @return moyen de transport choisit
 */
crduTransport getTransport(){
    //il demande de nouveau le trajet si l'utilisateur
    //ne saisit pas correctement
    while(true) {
        cout << "1: Train" << endl;
        cout << "2: Auto" << endl;
        cout << "3: Bateau" << endl;
        cout << "4: Avion" << endl;
        cout << "Choisisez un transport" << endl;
        int transport;
        cin >> transport;
        if(transport < 1 || transport > 4){
            cout<<"transport invalide"<<endl;
            cout<<"s'il vous plait, choisisez un transport de la liste"<<endl;
            continue;
        }
        return static_cast<crduTransport > (transport);
    }


}



int main(){
    //d'abord l'utilisateur choisi une taille pour le catalogue
    //la taille du Catalogue s'ajuste automatiquement si on veut
    //ajouter un trajet et le catalogue est plein, donc il doit pas
    //etre 100% precis ici
    cout<<"introduisez le nombre de trajets que vous allez mettre dans le catalogue"<<endl;
    cout<<"si vous savez pas exactement c'est pas grave, taper une aproximation"<<endl;
    int taille;
    cin>>taille;
    Catalogue catalogue(taille);

    //l'utilisateur choisi c'est qu'il veut faire avec le catalogue
    int ordre;
    cout<<"1: ajouter un trajet simple"<<endl;
    cout<<"2: ajouter un trajet compose"<<endl;
    cout<<"3: Afficher la liste de trajets"<<endl;
    cout<<"4: rechercher un parcours"<<endl<<endl;
    cout<<"tapez le numero de l'action que vous voulez realiser, tapez -1 pour sortir"<<endl;
    while(cin>>ordre && ordre !=-1){
        switch(ordre){
            //ajouter un trajet simple
            case 1 : {
                cout << "ecrivez la ville de depart:" << endl;
                char depart[50];
                cin >> depart;
                cout << "ecrivez la ville de destination:" << endl;
                char destination[50];
                cin >> destination;
                crduTransport transport = getTransport();
                catalogue.AjouterTrajet(depart, destination, transport);
                cout<<endl;
                break;
            }
            //ajouter un trajet compose
            case 2 : {
                cout << "ecrivez le nombre de trajets conetnus" << endl;
                int nTrajets;
                cin >> nTrajets;
                TrajetCompose tc(nTrajets);
                for (int i = 0; i < nTrajets; i++) {
                    cout << "ecrivez la ville de depart du trajet" << i + 1 << ":" << endl;
                    char depart[50];
                    cin >> depart;
                    cout << "ecrivez la ville de destination du trajet" << i + 1 << ":" << endl;
                    char destination[50];
                    cin >> destination;
                    crduTransport transport = getTransport();
                    tc.AjouterTrajet(depart, destination, transport);
                }
                catalogue.AjouterTrajet(tc);
                break;
            }
            //afficher ce qu'il y a dans le catalogue
            case 3: {
                cout << "le catalogue contient:" << endl;
                catalogue.Afficher();
                cout<<endl;
                break;
            }
            //rechercher un parcours entre de villes

            case 4: {
                //il realise pas de recherche si le catalogue est plein
                if(catalogue.getNelements()==0){
                    cout<<"Il y a pas des trajets"<<endl;
                    break;
                }
                cout << "ecrivez la ville de depart du parcours:" << endl;
                char depart[50];
                cin >> depart;
                cout << "ecrivez la ville de destination du parcours:" << endl;
                char destination[50];
                cin >> destination;
                cout << "avec les les trajets disponibles:" << endl;
                catalogue.Afficher();
                cout << "vous pouvez aller de " << depart << " a " << destination << " avec:"<<endl;
                catalogue.Recherche(depart,destination);
                cout<<endl;

                break;
            }
            //en cas ou l'utilisateur saisit un numero qui est pas dans la liste
            default :{
                cout<<"s'il tu plait, selectione un ordre dans la liste"<<endl;
                cout<<endl;
            }


        }
        cout<<"1: ajouter un trajet simple"<<endl;
        cout<<"2: ajouter un trajet compose"<<endl;
        cout<<"3: Afficher la liste de trajets"<<endl;
        cout<<"4: rechercher un parcours"<<endl<<endl;
        cout<<"tapez le numero de l'action que vous voulez realiser"<<endl;

    }

}