/*************************************************************************
                        TrajetSimple  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Alexandre DUFOUR
    e-mail               : alexandre.dufour@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

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
    void    Afficher() const;
    // Mode d'emploi :
    //  Affiche les caractéristiques du voyage

    const char    *GetVilleDepart() const;
    // Mode d'emploi :
    //  Renvoie un pointeur sur la ville de départ du trajet (pas de copie).

    const char    *GetVilleArrivee() const;
    // Mode d'emploi :
    //  Renvoie un pointeur sur la ville d'arrivée du trajet (pas de copie).

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const char * villeDepart, const char * villeArrivee, const char * moyTrans );
    // Mode d'emploi :
    //  Construit un trajet simple en initialisant ses attributs.

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //  Détruit en profondeur le trajet simple.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char    *depart;
    char    *arrivee;
    char    *moyenTransport;
};

//----------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

