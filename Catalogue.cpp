/*************************************************************************
                        Catalogue  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

//-- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) --

using namespace std;
// ----------- INCLUDES SYSTEME
#include <iostream>

//------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "Collection.h"

// ----------------- Constructeurs - destructeur
Catalogue::Catalogue ( unsigned int _tailleMax ) 
{
    #ifdef MAP
        cout << "Appel au constructeur du catalogue" << endl;
    #endif
    collectionTrajets = Collection ( _tailleMax );
}

Catalogue::~Catalogue ( ) 
{
    #ifdef MAP
        cout << "Appel au destructeur du catalogue" << endl;
    #endif
}

// ------------ Méthodes publiques
void Catalogue::Afficher ( ) const 
{
    unsigned int i, tailleCollection;
    Trajet* trajet;

    tailleCollection = collectionTrajets.GetTaille ( );

    if ( tailleCollection == 0 ) 
    {
        // aucun trajet
        cout << "Aucun trajet n'est disponible." << endl;
        return;
    }

    for ( i = 0; i < tailleCollection; i++ ) 
    {
        trajet = collectionTrajets.GetTrajet ( i );
        cout << "Trajet numero " << ( i + 1 ) << ":";
        trajet->Afficher ( );
    }
}

void Catalogue::Rechercher ( const char* depart, const char* arrivee ) const 
{

}

void Catalogue::Ajouter ( Trajet* trajet ) 
{
    collectionTrajets.Ajouter ( trajet );
}