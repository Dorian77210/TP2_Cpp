/*************************************************************************
                           Collection.h  -  Interface de la classe Collection
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : dorian.terba@insa-lyon.fr
*************************************************************************/

//------------------ Interface de la classe <Collection> (fichier Collection.h)----------

#if ! defined ( COLLECTION_H )
#define COLLECTION_H

//--------- INCLUDES
#include "Trajet.h"

// ------ Constantes
const unsigned int COLLECTION_TAILLE_PAR_DEFAUT = 10;
const unsigned int FACTEUR_REDIMENSIONNEMENT = 10;

class Collection 
{
    //--------------------------- PARTIE PUBLIQUE
    public: 
        //-------- Constructeurs et destructeur ----------
        Collection ( unsigned int tailleMax = COLLECTION_TAILLE_PAR_DEFAUT );
        // Constructeur permettant de creer un collection de trajets
        
        Collection ( const Collection & collection );
        // Constructeur de copie pour la classe Collection
        // Elle prend en parametre une collection pour la copier

        virtual ~Collection ( );
        // Destructeur d'une collection

        //------------------------------- Méthodes publiques
        void Ajouter ( Trajet* trajet );
        // La methode "Ajouter" permet d'ajouter un trajet dans la collection courante

        Trajet* GetTrajet ( unsigned int index ) const;
        // Permet de recuperer un trajet dans la collection a l'indice "index"

        unsigned int GetTaille ( ) const;
        // Permet de recuperer la taille de la collection

    //----------------------- PARTIE PRIVEE
    private:
        //--------------- Méthodes privées
        void reajuster ( );
        // Methode qui permet d'augementer la capacité du tableau de trajets

    //----------------------- PARTIE PROTEGEE
    protected:
        unsigned int tailleMax;
        unsigned int tailleCourante;
        Trajet** trajets;
};

#endif