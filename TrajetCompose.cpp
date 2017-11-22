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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void TrajetCompose::afficher() const{
    cout<<"TC ";
    for(int i=0;i<nElements;i++){
        tabTrajets[i]->afficher();
        if(i!=nElements-1) cout<<" - ";
    }

}
const char * TrajetCompose::getDepart() const{
    return tabTrajets[0]->getDepart();
}

const char * TrajetCompose::getDestination() const{
    return tabTrajets[nElements-1]->getDestination();
}

TrajetCompose * TrajetCompose::clone() const{
    return new TrajetCompose(*this);
}



//-------------------------------------------- Constructeurs - destructeur



TrajetCompose::TrajetCompose ( int t) : TabTrajets(t)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif


} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose ( const TabTrajets & tab ) : TabTrajets(tab)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif


} //----- Fin de TrajetCompose

TrajetCompose::TrajetCompose(const TrajetCompose & t) : TabTrajets(t.taille)
{
    for(int i=0;i<t.nElements;i++){
        ajouterTrajet(*t.tabTrajets[i]);
    }
}

TrajetCompose::~TrajetCompose() {

}



//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées

