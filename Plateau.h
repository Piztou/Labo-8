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
   Plateau(unsigned largeur, unsigned hauteur);

   void ajouterRobots(unsigned quantite);
   void afficher();
   void bougerRobots();
   void testerCollisions(); // TODO directement dans bougerRobots?
   bool partieFinie();

private:
   unsigned largeur, hauteur;
   std::vector<Robot> robots;
};


#endif //INC_8_PLATEAU_H
