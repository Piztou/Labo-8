/*
-----------------------------------------------------------------------------------
Nom du fichier : Plateau.cpp
Nom du Labo : 8 - Survivor
Auteur(s) : Gillioz Dorian & Yann Merk
Date creation : 14-01-2022
Description : <TODO>
Remarque(s) : <TODO>
Compilateur : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <cassert>
#include "Plateau.h"
Plateau::Plateau(unsigned int largeur, unsigned int hauteur) {
   this->largeur = largeur;
   this->hauteur = hauteur;
}

void Plateau::ajouterRobots(unsigned int quantite) {
   // S'assure qu'on ne dépasse pas la quantité max de robots
   assert((quantite + robots.size()) <= NB_ROBOT_MAX);

   for(unsigned i = 0; i < quantite; ++i) {
      // Génère des coordonnées
      unsigned x, y;
      do {
         //TODO random
         x = 0; y = 0;
         // Vérifie que l'endroit est vide
      } while (chercheRobot(x,y));

      // Crée le nouveau robot
      // Note : emplace_back suggéré par Warning, fonctionne comme un push_back
      // mais ne génère pas de variable temporaire, donc plus efficient
      robots.emplace_back(Robot(x,y));
   }
}

bool Plateau::chercheRobot(unsigned int x, unsigned int y) {
   // Parcours la liste de robot pour en chercher un qui aurait les mêmes coordonnées
   for (Robot & robot : robots) {
      if(robot.getX() == x && robot.getY() == y) {
         return true;
      }
   }
   return false;
}
