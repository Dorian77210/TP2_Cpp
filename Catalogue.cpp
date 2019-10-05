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
#include "Arbre.h"
#include "Trajet.h"
#include "Collection.h"

// ----------------- Constructeurs - destructeur
Catalogue::Catalogue ( unsigned int _tailleMax ) 
{
    #ifdef MAP
        cout << "Appel au constructeur du catalogue" << endl;
    #endif
    collectionTrajets = new Collection ( _tailleMax );
}

Catalogue::~Catalogue ( ) 
{
    #ifdef MAP
        cout << "Appel au destructeur du catalogue" << endl;
    #endif

    delete collectionTrajets;
}

// ------------ Méthodes publiques
void Catalogue::Afficher ( ) const 
{
    unsigned int i, tailleCollection;
    Trajet* trajet;

    tailleCollection = collectionTrajets->GetTaille ( );

    if ( tailleCollection == 0 ) 
    {
        // aucun trajet
        cout << "Aucun trajet n'est disponible." << endl;
        return;
    }

    for ( i = 0; i < tailleCollection; i++ ) 
    {
        trajet = collectionTrajets->GetTrajet ( i );
        cout << "Trajet numero " << ( i + 1 ) << " : ";
        trajet->Afficher ( );
    }
}

const Collection* Catalogue::GetCatalogue ( ) const 
{
    return collectionTrajets;
}

void Catalogue::Rechercher ( const char* depart, const char* arrivee ) const 
{
    Trajet* trajet;
    unsigned int i, tailleCollection;
    bool trajetsTrouves = false;

    tailleCollection = collectionTrajets->GetTaille ( );

    for ( i = 0; i < tailleCollection; i++ ) 
    {
        trajet = collectionTrajets->GetTrajet ( i );
        if ( trajet->EstValide ( depart, arrivee ) ) 
        {
            if ( !trajetsTrouves ) trajetsTrouves = true;
            cout << " - ";
            trajet->Afficher ( );
        }
    }

    if ( !trajetsTrouves ) 
    {
        cout << "Aucun trajet n'a été trouvé pour votre demande." << endl;
    }
}

void Catalogue::RechercheComplexe ( const char* depart, const char* arrivee ) const
{
    Arbre* arbre = new Arbre ( );
    arbre->RechercherTrajetsPossibles ( this, depart, arrivee );
    arbre->AfficherTrajetsPossibles ( );

    delete arbre;
}

void Catalogue::Ajouter ( Trajet* trajet ) 
{
    collectionTrajets->Ajouter ( trajet );
}