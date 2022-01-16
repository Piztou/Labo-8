/*
-----------------------------------------------------------------------------------
Nom du fichier : Plateau.h
Nom du Labo : 8 - Survivor
Auteur(s) : Gillioz Dorian & Yann Merk
Date creation : 14-01-2022
Description : <TODO>
Remarque(s) : <TODO>
Compilateur : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef INC_8_PLATEAU_H
#define INC_8_PLATEAU_H

#include <vector>

#include "Robot.h"

class Plateau {
public:
   // Quantité maximum de robots pouvant être gérés par le plateau
   static const unsigned NB_ROBOT_MAX = 10;
   /**
    * Crée un plateau avec les dimensions données
    * @param largeur Largeur du plateau
    * @param hauteur Hauteur du plateau
    */
   Plateau(unsigned largeur, unsigned hauteur);

   /**
    * Ajoute une certaines quantité de Robots sur le terrain à des emplacements
    * aléatoire \n
    * @remark Quitte le programme (assert) si NB_ROBOT_MAX n'est pas respecté
    * @param quantite La quantité de robot à ajouter
    */
   void ajouterRobots(unsigned quantite);
   void afficher();
   void bougerRobots();
   void testerCollisions(); // TODO directement dans bougerRobots?
   bool partieFinie();

private:
   unsigned largeur, hauteur;
   std::vector<Robot> robots;

   /**
    * Cherche un robot à une position, retourne true si au moins un est présent
    * autrement false
    * @param x Position horizontale à vérifier
    * @param y Position verticale à vérifier
    * @return true si un robot à été trouvé, autrement false
    */
   bool chercheRobot(unsigned x, unsigned y);
};


#endif //INC_8_PLATEAU_H
