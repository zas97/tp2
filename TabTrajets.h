/*************************************************************************
                           TabTrajets  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TabTrajets> (fichier TabTrajets.h) ----------------
#if ! defined ( TabTrajets_H )
#define TabTrajets_H

#include "Trajet.h"
#include "TrajetSimple.h"



//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TabTrajets>
//
//
//------------------------------------------------------------------------
class TrajetCompose;

class TabTrajets
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool AjouterTrajet(const Trajet &t);
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool AjouterTrajet(char *depart, char *destination, crduTransport transport);
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool AjouterTrajet(char **departs, char **destinations, crduTransport *transports);
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Trajet * getElement(int pos) const;
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    int getTaille() const;
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual void Afficher() const;
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    int getNelements() const;
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool AjusterTaille(int delta);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

    TabTrajets(const TabTrajets & tab);

    TabTrajets ( int t );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TabTrajets ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int taille;
    Trajet ** tabTrajets;
    int nElements;

};

//-------------------------------- Autres définitions dépendantes de <TabTrajets>

#endif // TabTrajets_H

