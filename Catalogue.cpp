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
int Catalogue::Recherche(const char *depart, const char *destination) const
{
    bool utilise[nElements];
    for(int i=0;i<nElements;i++){
        utilise[i]=false;
    }
    int parcours[nElements];
    int count = 0;
    Recherche(depart, destination, utilise, parcours, 0, count);
    cout<<endl;
    return count;
}

void Catalogue::Recherche(const char *depart, const char *destination, bool *utilise, int *parcours, int index,
                          int &count) const
{
    if(strcmp(depart,destination)==0){
        ++count;
        cout<<"(";
        for(int i=0;i<index-1;i++){
            cout<<"T"<<parcours[i]<<"+";
        }
        cout<<"T"<<parcours[index-1]<<") ";
    }
    for(int i=0;i<nElements;i++){
        if(!utilise[i]){
            if(strcmp(depart,tabTrajets[i]->getDepart())==0){
                utilise[i]=true;
                parcours[index]=i+1;
                Recherche(tabTrajets[i]->getDestination(), destination, utilise, parcours, index + 1, count);
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
        AjouterTrajet(*unCatalogue.tabTrajets[i]);
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

