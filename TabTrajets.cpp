/*************************************************************************
                           TabTrajets  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TabTrajets> (fichier TabTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TabTrajets.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TabTrajets::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool TabTrajets::ajouterTrajet(const Trajet & t)
{
    if(nElements >= taille){
        return false;
    }
    tabTrajets[nElements] = t.clone();
    ++nElements;
    return true;


}
int TabTrajets::getNelements() {
    return nElements;
}




int TabTrajets::getTaille() {
    return taille;
}

void TabTrajets::afficher()
{
    for(int i=0;i<nElements;i++)
    {
        tabTrajets[i]->afficher();
    }
}



Trajet * TabTrajets::getElement(int pos) const
{
    return tabTrajets[pos];
}


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur



TabTrajets::TabTrajets (int t ) : taille(t)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TabTrajets>" << endl;
#endif
    tabTrajets = new Trajet * [taille];
    nElements = 0;
} //----- Fin de TabTrajets

TabTrajets::TabTrajets (const TabTrajets & tab){
    taille = tab.taille;
    nElements = 0;
    tabTrajets = new Trajet * [taille];
    for(int i=0;i<tab.nElements;i++){
        ajouterTrajet(*tab.getElement(i));
    }

}

TabTrajets::~TabTrajets ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TabTrajets>" << endl;
#endif
    for(int i=0;i<nElements;i++){
        delete tabTrajets[i];
    }
    delete [] tabTrajets;
} //----- Fin de ~TabTrajets


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

