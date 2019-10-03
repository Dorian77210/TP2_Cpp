/*************************************************************************
                           Trajet.h  -  Interface de la classe Trajet
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : dorian.terba@insa-lyon.fr
*************************************************************************/

// ---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) -------

// --------- INCLUDE
#include <cstring>
#include <iostream>

// --------- Include personnel
#include "Trajet.h"

// ----------------- Constructeurs - destructeur
Trajet::Trajet ( const char* _depart, const char* _arrivee ) 
{
    #ifdef MAP
        cout << "Appel au constructeur de la classe Trajet" << endl;
    #endif
    // creation de variables pour la longueur des chaines de caracteres
    int _departLongueur = strlen ( _depart );
    int _arriveeLongueur = strlen ( _arrivee );

    depart = new char [ _departLongueur + 1 ];
    arrivee = new char [ _arriveeLongueur + 1 ];
    
    // copie des chaines de caracteres
    strncpy ( depart, _depart, _departLongueur + 1 );
    strncpy ( arrivee, _arrivee, _arriveeLongueur + 1 );
}

Trajet::~Trajet ( ) 
{
    #ifdef MAP
        cout << "Appel au deconstructeur de la classe Trajet" << endl;
    #endif

    delete [] depart;
    delete [] arrivee;
}