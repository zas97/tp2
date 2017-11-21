#include <iostream>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TabTrajets.h"
#include "TrajetCompose.h"
using namespace std;


void test(TabTrajets &tab){
    TrajetSimple t("Barcelone","Lleida",Avion);
    TrajetSimple t2("Lyon","Lleida",Train);
    tab.ajouterTrajet(t);
    tab.ajouterTrajet(t2);
//    t.afficher();
}



int main() {

    TabTrajets tab(2);
    test(tab);
//    tab.getElement(0)->afficher();
//    cout<<endl;
//    tab.getElement(1)->afficher();
//    cout<<tab.getTaille()<<endl;
//    cout<<tab.getElement(0)->getDestination()<<endl;
//    cout<<tab.getElement(0)->getDepart()<<endl;
    TrajetCompose tc(tab);
//    tab.afficher();

    tc.afficher();
    
//    tc.afficher();


    return 0;
}