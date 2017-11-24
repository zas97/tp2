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
    bool ajuste = false;
    if(nElements >= taille){
        ajusterTaille(1);
        ajuste=true;
    }
    tabTrajets[nElements] = t.clone();
    ++nElements;
    return ajuste;
}

bool TabTrajets::ajouterTrajet( char * depart, char * destination,crduTransport transport)
{
    bool ajuste = false;
    if(nElements >= taille){
        ajusterTaille(1);
        ajuste=true;
    }
    tabTrajets[nElements] = new TrajetSimple(depart,destination,transport);
    ++nElements;
    return ajuste;

}

bool TabTrajets::ajouterTrajet(char **departs, char **destinations, crduTransport *transports)
{
    bool ajuste = false;
    if(nElements >= taille){
        ajusterTaille(1);
        ajuste=true;
    }
    int nbElements = sizeof(transports)/sizeof(crduTransport);

    TrajetCompose * tc = new TrajetCompose(nbElements);
    for(int i=0;i<nbElements;i++){
        tc->ajouterTrajet(departs[i],destinations[i],transports[i]);
    }
    tabTrajets[nElements] = tc;
    ++nElements;
    return ajuste;

}


int TabTrajets::getNelements() const
{
    return nElements;
}




int TabTrajets::getTaille() const
{
    return taille;
}

bool TabTrajets::ajusterTaille(int delta)
{
    if(delta + taille < nElements)
        return false;
    taille += delta;
    Trajet ** newTab = new Trajet* [taille];
    for(int i=0;i<nElements;i++){
        newTab[i] = tabTrajets[i];
    }
    Trajet ** aux = tabTrajets;
    tabTrajets = newTab;
    delete [] aux;
}

void TabTrajets::afficher() const
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

