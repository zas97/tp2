/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "TabTrajets.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void TrajetCompose::afficher() {
    cout<<"trajet compose de "<<getDepart()<<" a "<<getDestination()<<" avec: "<<endl;
    tabTrajets->afficher();

}
const char * TrajetCompose::getDepart() {
    return tabTrajets->getElement(0)->getDepart();
}

const char * TrajetCompose::getDestination() {
    return tabTrajets->getElement(tabTrajets->getNelements()-1)->getDestination();
}

TrajetCompose * TrajetCompose::clone() const{
    return new TrajetCompose(*this);
}



//-------------------------------------------- Constructeurs - destructeur



TrajetCompose::TrajetCompose ( int t)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    tabTrajets = new TabTrajets(t);

} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose ( const TabTrajets & tab )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    tabTrajets = new TabTrajets(tab);

} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose(const TrajetCompose & t){
    tabTrajets = new TabTrajets(*t.tabTrajets);
}

TrajetCompose::~TrajetCompose() {
    delete tabTrajets;
}



//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées

