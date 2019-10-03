/*************************************************************************
                           Trajet.h  -  Interface de la classe Trajet
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : dorian.terba@insa-lyon.fr
*************************************************************************/

//------------------ Interface de la classe <Catalogue> (fichier Catalogue.h)----------

#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

// ---------------- INTERFACE UTILISEES
#include "Trajet.h"

//----------- CONSTANTES
const int TAILLE_PAR_DEFAUT = 10;

class Catalogue 
{
    //--------------------------- PARTIE PUBLIQUE
    public: 
        //-------- Constructeurs et destructeur ----------
        Catalogue ( int _tailleMax = TAILLE_PAR_DEFAUT );
        // Mode d'emploi 
            // La classe <Catalogue> permet de construire un catalogue de trajets
            // Le parametre "_tailleMax" permet de definir une taille maximale par defaut pour la liste de trajets

        // Deconstructeur de la classe
        virtual ~Catalogue ( );

        //------------------------------- Méthodes publiques


    protected:
        int tailleMax;
        int tailleCourante;
        Trajet** trajets;
};

#endif