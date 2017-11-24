/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "cstring"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Catalogue::recherche(const char * depart,const char * destination) {
    bool utilise[nElements];
    for(int i=0;i<nElements;i++){
        utilise[i]=false;
    }
    recherche(depart,destination,utilise);
}
void Catalogue::recherche(const char *depart, const char *destination,bool * utilise) {
    if(strcmp(depart,destination)==0){

    }
    for(int i=0;i<taille;i++){
        if(!utilise[i]){
            if(strcmp(depart,tabTrajets[i]->getDepart())==0){
                utilise[i]=true;
                recherche(tabTrajets[i]->getDepart(),destination,utilise);
                utilise[i]=false;
            }
        }
    }
}

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue ) : TabTrajets(unCatalogue.taille)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
    for(int i=0;i<unCatalogue.nElements;i++){
        ajouterTrajet(*unCatalogue.tabTrajets[i]);
    }
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue (int t) : TabTrajets(t)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

