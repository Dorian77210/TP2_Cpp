/*************************************************************************
                           Trajet.h  -  Interface de la classe Trajet
                             -------------------
    début                : 03/10/2019
    copyright            : (C) 2019 par Dorian TERBAH
    e-mail               : dorian.terba@insa-lyon.fr
*************************************************************************/

//------------------ Interface de la classe <Trajet> (fichier Trajet.h)----------
#if ! defined ( TRAJET_H )
#define TRAJET_H

// La classe a pour rôle de représenter un trajet. Elle sert de classe mère pour les
// classes <TrajetSimple> et <TrajetCompose>

class Trajet 
{
    //--------------------------- PARTIE PUBLIQUE
    public: 
        //-------- Constructeurs et destructeur ----------
        Trajet ( const char* _depart, const char* _arrivee );
        // Mode d'emploi 
            // La classe <Trajet> construit un trajet a partir d'un départ et d'une arrivée

        virtual ~Trajet ( );
        // Deconstructeur de la classe

        //------------------------------- Méthodes publiques
        virtual void Afficher ( ) const = 0;
        // La méthode "Afficher" permet d'afficher le trajet 

        virtual bool EstValide ( const char* src, const char* dst ) const = 0;
        // La méthode "EstValide" permet de savoir si un trajet est valide ou non
        // en fonction d'un source et d'une destination
        // Les parametres sont "src" qui permet de definir le depart du trajet
        // et "dst" qui permet de definir l'arrivee du trajet

    //------------------------- PARTIE PROTEGEE
    protected:
        char* depart;
        char* arrivee;
};

#endif