/*************************************************************************
                        TrajetSimple  -  Interface de TrajetSimple
                             -------------------
    début                : 03/10/2019
    copyright            : (C) $YEAR$ par Dorian TERBAH
    e-mail               : dorian.terba@insa-lyon.fr
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
    TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi (constructeur de copie) :
    //  Construit un trajet simple en copiant les attributs de celui passé
    //  en paramètre (copie profonde des chaines de caractères);

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
    char    *arrive;
    char    *moyenTransport;
};

//----------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

