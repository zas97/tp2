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
#include "TrajetSimple.h"
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

bool TabTrajets::ajouterTrajet( char * depart, char * destination,crduTransport transport)
{
    if(nElements >= taille){
        return false;
    }
    tabTrajets[nElements] = new TrajetSimple(depart,destination,transport);
    ++nElements;
    return true;

}

bool TabTrajets::ajouterTrajet( char ** departs, char ** destinations,crduTransport * transports)
{
    if(nElements >= taille){
        return false;
    }
    int nbElements = sizeof(transports)/sizeof(crduTransport);

    TrajetCompose * tc = new TrajetCompose(nbElements);
    for(int i=0;i<nbElements;i++){
        tc->ajouterTrajet(departs[i],destinations[i],transports[i]);
    }
    tabTrajets[nElements] = tc;
    ++nElements;
    return true;

}


const int TabTrajets::getNelements() {
    return nElements;
}




int TabTrajets::getTaille() {
    return taille;
}

void TabTrajets::afficher()
{
    for(int i=0;i<nElements;i++)
    {
        cout<<i+1<<" : ";
        tabTrajets[i]->afficher();
        cout<<endl;
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
        ajouterTrajet(*tab.tabTrajets[i]);
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

