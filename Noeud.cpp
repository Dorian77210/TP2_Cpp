/*************************************************************************
                        Noeud  -  Classe qui represente un noeud
                        dans un arbre de trajets 
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

// ---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) -------

// --------------- INCLUDES SYSTEMES
#include <iostream>
#include <cstring>

// -------------- INCLUDES SYSTEMES
#include <iostream>
using namespace std;
// -------------- Includes personnels
#include "Noeud.h"
#include "Trajet.h"

Noeud::Noeud ( const Trajet* _trajetAssocie, Noeud* _parent ) 
    : estValide ( false )
{
    #ifdef MAP
        cout << "Appel au constructeur de la classe <Noeud>" << endl;
    #endif

    trajetAssocie = _trajetAssocie;
    parent = _parent;
    enfant = prochain = NOEUD_NULL;
}

Noeud::~Noeud ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de la classe <Noeud>" << endl;
    #endif

    Noeud* noeud, *tmp;

    // supprimer les voisins
    if ( prochain != NOEUD_NULL ) 
    {
        for ( noeud = prochain; noeud->prochain != NULL; )
            {
                tmp = noeud->prochain;
                delete noeud;
                noeud = tmp;
            }
    }
    
    // supprime l'enfant
    delete enfant;
}

void Noeud::Ajouter ( const Trajet* trajet, const char* arrivee )
{
    const char* trajetArrivee = trajet->GetVilleArrivee ( );
    const char* trajetDepart = trajet->GetVilleDepart ( );
    const char* departAssocie = trajetAssocie->GetVilleDepart ( );
    const char* arriveeAssociee = trajetAssocie->GetVilleArrivee ( );

    if ( enfant != NOEUD_NULL ) enfant->Ajouter ( trajet, arrivee );
    if ( prochain != NOEUD_NULL ) prochain->Ajouter ( trajet, arrivee );

    if ( strcmp ( trajetArrivee, arrivee ) == 0 ) 
    {
        // on arrive en fin de branche, cette branche est donc un trajet possible
        estValide = true;
        // creation du noeuf enfant ou rajout a la fin de l'enfant
        if ( enfant == NOEUD_NULL ) 
        {
            enfant = new Noeud ( trajet, this );
            enfant->estValide = true;    
        } else
        {
            enfant->AjouterVoisin ( trajet );
        }
        // on remonte dans l'arbre
        Noeud* _parent = parent;
        while ( _parent != NULL ) 
        {
            _parent->estValide = true;
            _parent = _parent->parent;
        }
    } else if ( strcmp ( departAssocie, trajetDepart ) == 0 && strcmp ( arriveeAssociee, arrivee ) != 0 )
    {
        // doit ajouter un voisin
        AjouterVoisin ( trajet );
    } else if ( strcmp ( arriveeAssociee, departAssocie ) ) 
    {
        // ajout de l'enfant
        enfant = new Noeud ( trajet, this );
    } else {
        // arrive != depart, fin de branche
        return;
    }
}

Noeud* Noeud::AjouterVoisin ( const Trajet* trajet )
{
    Noeud* courant;

    for ( courant = this; courant->prochain != NULL; courant = courant->prochain )
    {
        if ( trajet == trajetAssocie ) return NOEUD_NULL; // noeud deja present
    }

    Noeud* noeud = new Noeud ( trajet, parent );
    courant->prochain = noeud;

    return noeud;
}

void Noeud::Afficher ( void ) 
{
    // affichage pour les voisins
    Noeud* noeud = this;

    for ( noeud = this; noeud != NOEUD_NULL; noeud = noeud->prochain )
    {
        if ( noeud->estValide ) 
        {
            if ( enfant != NOEUD_NULL ) 
            {
                trajetAssocie->Afficher ( );
                enfant->Afficher ( );
            } else
            {
                noeud->trajetAssocie->Afficher ( );
                cout << endl;
            }
        }
    }
}

const bool Noeud::EstValide ( void ) const
{
    return estValide;
}

void Noeud::SetEstValide ( bool _estValide ) 
{
    estValide = _estValide;
}