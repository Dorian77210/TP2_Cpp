/*************************************************************************
                        TrajetSimple  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Alexandre DUFOUR
    e-mail               : $EMAIL$
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void    TrajetSimple::Afficher ( ) const
{
	cout << depart << " -> " << arrivee << " par " << moyenTransport << endl;
}


const char    *GetVilleDepart ( ) const
{
	return (depart);
}

const char    *GetVilleArrivee ( ) const
{
	return (arrivee);
}


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
    strcpy(depart, unTrajetSimple.depart);
    strcpy(arrivee, unTrajetSimple.arrivee);
    strcpy(moyenTransport, unTrajetSimple.moyenTransport);
} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple ( const char * villeDepart, const char * villeArrivee, const char * moyTrans )
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple> : ";
    cout << villeDepart << " -> " << villeArrivee;
    cout << " par " << moyTrans <<< endl;
#endif
    strcpy(depart, villeDepart);
    strcpy(arrivee, villeArrivee);
    strcpy(moyenTransport, moyTrans);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete depart;
    delete arrivee;
    delete moyenTransport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

