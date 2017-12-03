/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 3/12/2017
    copyright            : (C) 2017 par Joan Capell, Hua Yang
    e-mail               : joan.capell-gracia@insa-lyon.fr
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
void TrajetCompose::Afficher() const{
    cout<<"TC ";
    for(int i=0;i<nElements;i++){
        tabTrajets[i]->Afficher();
        if(i!=nElements-1) cout<<" - ";
    }

}
const char * TrajetCompose::getDepart() const{
    return tabTrajets[0]->getDepart();
}

const char * TrajetCompose::getDestination() const{
    return tabTrajets[nElements-1]->getDestination();
}

TrajetCompose * TrajetCompose::Clone() const{
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
        AjouterTrajet(*t.tabTrajets[i]);
    }
}

TrajetCompose::~TrajetCompose() {

}



//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées

