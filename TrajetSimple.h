/*************************************************************************
                        TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées

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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    TrajetSimple & operator = ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi :
    //
    // Contrat :
    //


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
    char    *moyenTransport;
};

//----------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

