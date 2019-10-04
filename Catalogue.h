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
#include "Collection.h"

class Catalogue 
{
    //--------------------------- PARTIE PUBLIQUE
    public: 
        //-------- Constructeurs et destructeur ----------
        Catalogue ( unsigned int _tailleMax =  COLLECTION_TAILLE_PAR_DEFAUT );
        // Mode d'emploi 
            // La classe <Catalogue> permet de construire un catalogue de trajets
            // Le parametre "_tailleMax" permet de definir une taille maximale par defaut pour la liste de trajets

        // Destructeur de la classe
        virtual ~Catalogue ( );

        //------------------------------- Méthodes publiques
        void Afficher ( ) const;
        // La methode "Afficher" permet d'afficher le catalogue

        void Rechercher ( const char* depart, const char* arrivee ) const;
        // La methode "Rechercher" permet à l'utilisateur de rechercher un trajet
        // en fonction d'un depart et d'une arrivee
        // Dans le methode, l'utilisateur pourra choisir un depart et une arrivee

        void Ajouter ( Trajet* trajet );
        // La methode "Ajouter" permet d'ajouter un trajet 

    protected:
        Collection collectionTrajets;
};

#endif