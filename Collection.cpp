/*************************************************************************
                        Collection  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

//-- Réalisation de la classe <Collection> (fichier Collection.cpp) --

using namespace std;
#include <iostream>

// -------- Include personnel
#include "Collection.h"
#include "Trajet.h"

// ----------------- Constructeurs - destructeur
Collection::Collection ( unsigned int _tailleMax, bool _doitSupprimer ) 
    : tailleMax ( _tailleMax ), tailleCourante ( 0 )
{
    #ifdef MAP
        cout << "Appel au constructeur de la classe Collection" << endl;
    #endif
    
    trajets = new const Trajet* [ tailleMax ];
}

Collection::Collection ( const Collection & collection ) 
    : tailleMax ( collection.tailleMax )
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de la classe Collection" << endl;
    #endif

    trajets = new const Trajet* [ tailleMax ];

    for ( tailleCourante = 0; tailleCourante < collection.tailleCourante; tailleCourante++ ) 
    {
        trajets [ tailleCourante ] = collection.trajets [ tailleCourante ];
    }
}

Collection::~Collection ( ) 
{  
    #ifdef MAP
        cout << "Appel au destructeur de la classe Collection" << endl;
    #endif
    
    if ( doitSupprimer ) 
    {
        unsigned int i;

        // supprime tous les trajets dans la collection
        for ( i = 0; i < tailleCourante; i++ ) 
        {
            delete trajets [ i ];
        }

        delete [] trajets;
    }
}

// ---------------- Méthodes publiques
void Collection::Ajouter ( const Trajet* trajet )
{

    if ( tailleCourante == tailleMax ) 
    {
        reajuster ( );
    }

    trajets [ tailleCourante ] = trajet;
    tailleCourante++;
}

const Trajet* Collection::GetTrajet ( unsigned int index ) const
{
    return trajets [ index ];
}

unsigned int Collection::GetTaille ( ) const 
{ 
    return tailleCourante;
}

// -------------- Méthodes privées
void Collection::reajuster ( ) 
{
    unsigned int i;
    // reajustement de la taille
    tailleMax += FACTEUR_REDIMENSIONNEMENT;
    const Trajet** _trajets = new const Trajet* [ tailleMax ];

    for ( i = 0; i < tailleCourante; i++ )
    {
        _trajets [ i ] = trajets [ i ];
    }

    delete [] trajets;
    trajets = _trajets;
}

