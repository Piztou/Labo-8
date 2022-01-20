/*
-----------------------------------------------------------------------------------
Nom du fichier : Plateau.cpp
Nom du Labo    : 8 - Survivor
Auteurs        : Gillioz Dorian & Yann Merk
Date creation  : 14-01-2022
Description    : Partie implémentation de la classe Plateau.
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <cassert>
#include <iostream>
#include "Plateau.h"
#include "Robot_est_sur_ligne.h"
#include "annexes.h"

using namespace std;

const unsigned Plateau::NB_ROBOT_MAX = 9;

const char     Plateau::CAR_LIGNE         = '-';
const char     Plateau::CAR_COL           = '|';
const char     Plateau::CAR_VIDE          = ' ';
const unsigned Plateau::EPAISSEUR_BORDURE = 1;
const unsigned Plateau::NB_ROBOT_FIN      = 1;

const char* Plateau::MESSAGE_KILL_1 = "Le robot ";
const char* Plateau::MESSAGE_KILL_2 = " a tue ";

const char* Plateau::SYSTEM_CLEAR   = "cls";


Plateau::Plateau(unsigned largeur, unsigned hauteur) {
   this->largeur = largeur;
   this->hauteur = hauteur;

   messages_kills= ""s;
}

void Plateau::ajouterRobots(unsigned quantite) {
   // S'assure qu'on ne dépasse pas la quantité max de robots
   assert((quantite + robots.size()) <= NB_ROBOT_MAX);

   for(unsigned i = 0; i < quantite; ++i) {
      // Génère des coordonnées
      unsigned x, y;
      do {
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
   // Vide la console
   system(SYSTEM_CLEAR);

   // Dessine la première ligne
   for (unsigned i = 0; i < EPAISSEUR_BORDURE; ++i) {
      afficheChar(largeur + 2 * EPAISSEUR_BORDURE);
      cout << endl;
   }
   // Pour chaque ligne...
   for (unsigned ligne = 0; ligne < hauteur; ++ligne) {

      afficheChar(EPAISSEUR_BORDURE, CAR_COL);

      // Cherche les robots dans cette ligne
      vector<Robot*> robotsSurLigne = trouveRobotsSurLigne(ligne);

      // S'il n'y en a pas, écrit directement une ligne vide
      if (robotsSurLigne.empty()) {
         afficheChar(largeur, CAR_VIDE);
         //finit la ligne
         afficheChar(EPAISSEUR_BORDURE, CAR_COL);
         cout << endl;
         continue;
      }
      // Autrement, parcours toute la ligne
      for (unsigned col = 0; col < largeur; ++col) {
         // Vérifie si un des robots sur cette ligne est à cet emplacement
         bool foundRobot = false;
         for (Robot* robot : robotsSurLigne ) {
            if (robot->getX() == col) {
               afficheChar(1, robot->getChar());
               // Quitte immédiatement la boucle pour éviter le cas où 2 robots
               // serait au même endroit
               foundRobot = true;
               break;
            }
         }
         // Si on n'a pas trouvé de robot, met un caractère vide à la place
         if (!foundRobot) {
            afficheChar(1, CAR_VIDE);
         }
      }
      // Finit la ligne
      afficheChar(EPAISSEUR_BORDURE, CAR_COL);
      cout << endl;
   }

   // Dessine la ligne finale
   for (unsigned i = 0; i < EPAISSEUR_BORDURE; ++i) {
      afficheChar(largeur + 2 * EPAISSEUR_BORDURE);
      cout << endl;
   }

   // Affiche les destructions
   cout << messages_kills;
}

bool Plateau::chercheRobot(unsigned x, unsigned y) {
   // Parcours la liste de robot pour en chercher un qui aurait les mêmes coordonnées
   for (Robot& robot : robots) {
      if(robot.getX() == x && robot.getY() == y) {
         return true;
      }
   }
   return false;
}

void Plateau::afficheChar(unsigned taille, char caractere) {
   for (unsigned i = 0; i < taille; ++i) {
      cout << caractere;
   }
}

vector<Robot*> Plateau::trouveRobotsSurLigne(unsigned ligne) {
   vector<Robot*> result;
   // Cherche tous les robots sur la ligne
   vector<Robot>::iterator iterateur = robots.begin();
   while ((iterateur = find_if(iterateur, robots.end(),
                               Robot_est_sur_ligne(ligne))) != robots.end() ) {
      // Stock un pointeur vers ce robot
      result.push_back(&*iterateur);
      ++iterateur;
   }
   return result;
}

void Plateau::bougerRobots() {
   for (vector<Robot>::iterator it = robots.begin(); it != robots.end(); ++it) {
      Robot::Direction direction;
      do {
         direction = (Robot::Direction) aleatoire<int>(0, 3);
      } while (direction == Robot::Direction::UP    && it->getY()     <= 0       ||
               direction == Robot::Direction::DOWN  && it->getY() + 1 >= hauteur ||
               direction == Robot::Direction::LEFT  && it->getX()     <= 0       ||
               direction == Robot::Direction::RIGHT && it->getX() + 1 >= largeur);

      it->deplacement(direction, 1);

      // Tester les collisions
      appliquerCollisions(it);
   }
}
void Plateau::appliquerCollisions(vector<Robot>::iterator& itRobot) {
   vector<Robot>::iterator iterateur = robots.begin();
   // Cherche si il y a un autre robot sur cette case
   while ((iterateur = find(iterateur, robots.end(), *itRobot)) != robots.end() ) {
      // Ignore le robot lui-même
      if(itRobot == iterateur) {
         ++iterateur;
         continue;
      }
      // Ajoute un message de destruction
      ajouteMessageDestruction(*itRobot, *iterateur);

      // Remet l'itérateur sur le bon élément si besoin
      if(iterateur < itRobot) {
         --itRobot;
      }

      // Enlève le robot du vecteur
      iterateur = robots.erase(iterateur, iterateur+1);
      ++iterateur;
   }
}

bool Plateau::partieFinie() {
   return robots.size() <= NB_ROBOT_FIN;
}

void Plateau::ajouteMessageDestruction(const Robot& tueur, const Robot& tue) {
   messages_kills += MESSAGE_KILL_1;
   messages_kills += tueur.getChar();
   messages_kills += MESSAGE_KILL_2;
   messages_kills += tue.getChar();
   messages_kills += '\n';
}
