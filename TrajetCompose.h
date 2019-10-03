/*************************************************************************
                        TrajetCompose  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Alexandre DUFOUR
    e-mail               : alexandre.dufour@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ---
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Collection.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
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
    TrajetCompose ( Collection* unListeTrajets );
    // Mode d'emploi :
    //  Construit un trajet composé en initialisant sa liste de trajets.

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //  Détruit en profondeur le trajet simple.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Collection*  listeTrajets;
};

//----------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H

