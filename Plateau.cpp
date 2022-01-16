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
#include <iostream>
#include "Plateau.h"
#include "Robot_est_sur_ligne.h"
#include "annexes.h"

using namespace std;

const unsigned Plateau::NB_ROBOT_MAX = 10;

const char Plateau::CAR_LIGNE = '-';
const char Plateau::CAR_COL   = '|';
const char Plateau::CAR_VIDE  = ' ';

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
         //TODO const ?
         x = aleatoire(0u, largeur);
         y = aleatoire(0u, hauteur);
         // Vérifie que l'endroit est vide
      } while (chercheRobot(x,y));

      // Crée le nouveau robot
      // Note : emplace_back suggéré par Warning, fonctionne comme un push_back
      // mais ne génère pas de variable temporaire, donc plus efficient
      robots.emplace_back(Robot(x,y));
   }
}



void Plateau::afficher() {
   // Le + 2 est pour la largeur de la bordure
   // TODO const pour ça?
   afficheTrait(largeur + 2);
   cout << endl;

   for (unsigned ligne = 0; ligne < hauteur; ++ligne) {

      cout << CAR_COL;

      // Cherche les robots dans cette ligne
      vector<size_t> robotsSurLigne = trouveRobotsSurLigne(ligne);

      // S'il n'y en a pas, écrit directement une ligne vide
      if (robotsSurLigne.empty()) {
         afficheTrait(largeur, CAR_VIDE);
         //finit la ligne
         cout << CAR_COL << endl;
         continue;
      }
      // Autrement, parcours toute la ligne
      for (unsigned col = 0; col < largeur; ++col) {
         // Vérifie si un robot est à cet emplacement
         bool foundRobot = false;
         for (size_t index : robotsSurLigne ) {
            if (robots[index].getX() == col) {
               cout << robots[index].getId();
               // Quitte immédiatement la boucle pour éviter le cas où 2 robots
               // serait au même endroit
               foundRobot = true;
               break;
            }
         }
         // Si on n'a pas trouvé de robot, met un caractère vide à la place
         if (!foundRobot) {
            cout << CAR_VIDE;
         }
      }
      // Finit la ligne
      cout << CAR_COL << endl;
   }

   afficheTrait(largeur + 2);
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

void Plateau::afficheTrait(unsigned int taille, char caractere) {
   for (unsigned i = 0; i < taille; ++i) {
      cout << caractere;
   }
}

vector<size_t> Plateau::trouveRobotsSurLigne(unsigned int ligne) {
   vector<size_t> result;
   // Cherche tous les robots sur la ligne
   vector<Robot>::iterator iterateur = robots.begin();
   while ((iterateur = find_if(iterateur, robots.end(),
                                Robot_est_sur_ligne(ligne))) != robots.end() ) {
      // Stock l'indexe du robot (son indexe dans robots)
      result.push_back(distance(robots.begin(), iterateur));
      ++iterateur;
   }
   return result;
}
