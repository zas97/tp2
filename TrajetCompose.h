/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H
#include "Trajet.h"
#include "TabTrajets.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------



class TrajetCompose : public Trajet, public TabTrajets
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher() const;
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    const char * getDepart() const;

    const char * getDestination() const;

    TrajetCompose * Clone() const;




//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose (int t);
    // Mode d'emploi :
    //
    // Contrat :
    //
    TrajetCompose (const TabTrajets & tab);
    // Mode d'emploi :
    //
    // Contrat :
    //
    TrajetCompose(const TrajetCompose & t);


    ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées




//----------------------------------------------------- Attributs protégés



};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H

