/*************************************************************************
                        TrajetCompose  -  description
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Alexandre DUFOUR
    e-mail               : alexandre.dufour@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "Collection.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void    TrajetCompose::Afficher ( ) const
{
	unsigned int    taille;
    unsigned int    i;

    taille = listeTrajets->GetTaille();
    cout << "Trajet composé des trajets :" << endl;
    for (i = 0; i < taille; i++)
        listeTrajets->GetTrajet(i).Afficher();
}


const char    *TrajetCompose::GetVilleDepart ( ) const
{
	return (listeTrajets.GetTrajet(0).GetVilleDepart());
}

const char    *TrajetCompose::GetVilleArrivee ( ) const
{
	return (listeTrajets.GetTrajet(listeTrajets.GetTaille() - 1).GetVilleArrivee());
}


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const Collection & uneListeTrajets )
    : listeTrajets ( uneListeTrajets )
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose> : ";
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
