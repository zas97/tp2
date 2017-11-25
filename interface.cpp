#include <iostream>
#include "Catalogue.h"
#include "TrajetCompose.h"

using namespace std;


crduTransport getTransport(){
    bool ok = false;
    while(!ok) {
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
    cout<<"introduisez le nombre de trajets que vous allez mettre dans le catalogue"<<endl;
    cout<<"si vous savez pas exactement c'est pas grave, taper une aproximation"<<endl;
    int taille;
    cin>>taille;
    Catalogue catalogue(taille);
    int ordre;
    cout<<"1: ajouter un trajet simple"<<endl;
    cout<<"2: ajouter un trajet compose"<<endl;
    cout<<"3: afficher la liste de trajets"<<endl;
    cout<<"4: rechercher un parcours"<<endl<<endl;
    cout<<"tapez le numero de l'action que vous voulez realiser"<<endl;
    while(cin>>ordre && ordre !=-1){
        switch(ordre){
            case 1 : {
                cout << "ecrivez la ville de depart:" << endl;
                char depart[50];
                cin >> depart;
                cout << "ecrivez la ville de destination:" << endl;
                char destination[50];
                cin >> destination;
                crduTransport transport = getTransport();
                catalogue.ajouterTrajet(depart, destination, transport);
                cout<<endl;
                break;
            }
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
                    tc.ajouterTrajet(depart, destination, transport);
                }
                catalogue.ajouterTrajet(tc);
                break;
            }
            case 3: {
                cout << "le catalogue contient:" << endl;
                catalogue.afficher();
                cout<<endl;
                break;
            }
            case 4: {
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
                catalogue.afficher();
                cout << "vous pouvez aller de " << depart << " a " << destination << " avec:"<<endl;
                catalogue.recherche(depart,destination);
                cout<<endl;

                break;
            }


        }
        cout<<"1: ajouter un trajet simple"<<endl;
        cout<<"2: ajouter un trajet compose"<<endl;
        cout<<"3: afficher la liste de trajets"<<endl;
        cout<<"4: rechercher un parcours"<<endl<<endl;
        cout<<"tapez le numero de l'action que vous voulez realiser"<<endl;

    }

}