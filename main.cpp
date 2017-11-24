#include <iostream>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TabTrajets.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
using namespace std;


void ajouterTrajets(Catalogue & catalogue){
    //TS1
    catalogue.ajouterTrajet("Lyon","Bordeaux",Train);

    //TC2
    char * departs[] = {"Lyon","Marseille"};
    char * destinations[] = {"Marseille","Paris"};
    crduTransport transports[] = {Bateau,Avion};
    catalogue.ajouterTrajet(departs,destinations,transports);
//    TrajetCompose tc(2);
//    tc.ajouterTrajet("Lyon","Marseille",Bateau);
//    tc.ajouterTrajet("Marseille","Paris",Avion);
//    catalogue.ajouterTrajet(tc);


    //TS3
    catalogue.ajouterTrajet("Lyon","Paris",Auto);


}

void ajouterTrajets2(Catalogue & catalogue){
    //TS1
    TrajetSimple ts1("Lyon","Bordeaux",Train);
    catalogue.ajouterTrajet(ts1);

    //TC2
    TrajetCompose tc(2);
    tc.ajouterTrajet("Lyon","Marseille",Bateau);
    tc.ajouterTrajet("Marseille","Paris",Avion);
    catalogue.ajouterTrajet(tc);


    //TS3
    TrajetSimple ts3("Lyon","Bordeaux",Train);
    catalogue.ajouterTrajet(ts3);

    catalogue.ajouterTrajet("Bordeaux","Paris",Train);


}






int main() {
    Catalogue catalogue(1);
    catalogue.ajusterTaille(10);
    catalogue.ajusterTaille(-10);
    ajouterTrajets(catalogue);
    ajouterTrajets2(catalogue);
    catalogue.afficher();
    catalogue.recherche("Lyon","Paris");

}