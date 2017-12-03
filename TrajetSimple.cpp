/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 3/12/2017
    copyright            : (C) 2017 par Joan Capell, Hua Yang
    e-mail               : joan.capell-gracia@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur



TrajetSimple::TrajetSimple(const char * dep, const char * dest, crduTransport trans)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    depart = new char[strlen(dep)+1];
    destination = new char[strlen(dest)+1];
    strcpy(depart,dep);
    strcpy(destination,dest);
    transport = trans;

} //----- Fin de TrajetSimple
TrajetSimple::TrajetSimple(const TrajetSimple &t){
    depart = new char[strlen(t.depart)+1];
    destination = new char[strlen(t.destination)+1];
    strcpy(depart,t.depart);
    strcpy(destination,t.destination);
    transport = t.transport;
}


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete [] depart;
    delete [] destination;
} //----- Fin de ~TrajetSimple

void TrajetSimple::Afficher(void) const{
    cout<<"de "<<depart<<" a "<<destination<<" en "<<"MT"<<transport;
}

const char * TrajetSimple::getDepart() const{
    return depart;
}

const char * TrajetSimple::getDestination() const{
    return destination;
}

TrajetSimple * TrajetSimple::Clone() const{
    return new TrajetSimple(*this);
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

