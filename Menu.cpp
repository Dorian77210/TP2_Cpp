/*************************************************************************
                        Menu  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : $EMAIL$
*************************************************************************/

//-- Réalisation de la classe <Menu> (fichier Menu.cpp) --

using namespace std;
// ----------- INCLUDES SYSTEMES
#include <iostream>
// ---------- Includes personnels
#include "Menu.h"
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

// ---------------- Constructeurs - destructeur
Menu::Menu ( void ) 
{
    catalogue = new Catalogue ( );
}

Menu::~Menu ( )
{
    delete catalogue;
}

// -------------- Méthodes publiques
void Menu::Run ( void ) 
{
    bool loop = true;
    int choix;

    while ( loop ) 
    {
        afficherMenu ( );
        cin >> choix;
    }
}


// ------------- Méthodes protégées
void Menu::afficherMenu ( void ) const 
{
    cout << "Option 1 : Ajouter un trajet" << endl;
    cout << "Option 2 : Afficher le catalogue" << endl;
    cout << "Option 3 : Rechercher un parcours" <<endl;
    cout << "Choisissez l'option qui vous convient" << endl;
}

void Menu::rechercherTrajet ( void ) const
{

}

void Menu::ajouterTrajet ( void ) 
{
    char* depart, *arrivee;
    Trajet* trajet;
    Collection* collectionTrajets;
    int choice = 0;

    cout << "Option 1 : Création d'un trajet simple" << endl;
    cout << "Option 2 : Création d'un trajet composé" << endl;
    
    while ( ( choice != TRAJET_COMPOSE_OPTION ) && ( choice != TRAJET_SIMPLE_OPTION ) ) 
    {
        cout << "Choisissez l'option que vous souhaitez : ";
        cin >> choice;
    }

    if ( choice == TRAJET_SIMPLE_OPTION ) 
    {
        // trajet simple
        char* moyenTransport;
        // allocation des char*

        depart = new char [ MAX_TAILLE_STRING ];
        arrivee = new char [ MAX_TAILLE_STRING ];
        moyenTransport = new char [ MAX_TAILLE_STRING ];

        // edition du depart
        cout << "Départ : ";
        cin >> depart;

        // edition de l'arrivee 
        cout << "Arrivée : ";
        cin >> arrivee;

        // edition du moyen de transport
        cout << "Moyen de transport : ";
        cin >> moyenTransport;

        // creation du trajet simple, puis insertion dans le catalogue
        trajet = new TrajetSimple ( depart, arrivee, moyenTransport );
        catalogue->Ajouter ( trajet );
    } else 
    {
        // trajet composé
        int nbrTrajets, i;

        // TODOD
    }
}

void Menu::afficherCatalogue ( void ) const
{
    catalogue->Afficher ( );
}