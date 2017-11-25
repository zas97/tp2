/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H

#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum crduTransport { Train,Auto,Bateau,Avion };

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


    virtual const char * getDestination() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual const char * getDepart() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void Afficher() const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual TrajetSimple * Clone() const;
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur


    TrajetSimple (const char * depart, const char * destination, crduTransport trans);
    // Mode d'emploi :
    //
    // Contrat :
    //
    TrajetSimple(const TrajetSimple & t);

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    crduTransport transport;
    char * destination;
    char * depart;


};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H

