/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Nom du Labo    : 8 - Survivor
Auteurs        : Gillioz Dorian & Yann Merk
Date creation  : 14-01-2022
Description    : Le programme permet de simuler un combat de robots dans un plateau
                 de jeu. Le nombre de robots en jeu et les dimensions du plateau sont
                 données par l'utilisateur. La partie se termine lorsqu'il ne reste
                 qu'un robot en jeu.
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include <chrono>
#include <thread>

#include "annexes.h"
#include "Plateau.h"

using namespace std;

int main() {
   cout << "Ce programme permet de simuler un combat de robots dans un plateau avec le "
        << "nombre de robots et les dimensions du plateau parametrables." << endl;

                  // Temps d'attente entre chaque déplacement
   const unsigned SLEEP          = 1000,
                  // Largeur du plateau minimale
                  MIN_LARGEUR    = 10,
                  // Largeur du plateau minimale
                  MAX_LARGEUR    = 1000,
                  // Hauteur du plateau minimale
                  MIN_HAUTEUR    = 10,
                  // Hauteur du plateau maximale
                  MAX_HAUTEUR    = 1000,
                  // Nombre de robots minimum
                  MIN_NBR_OBJETS = 1;

   unsigned largeur    = saisir<unsigned>("largeur ", "erreur de saisie",
                                          MIN_LARGEUR, MAX_LARGEUR);
   unsigned hauteur    = saisir<unsigned>("hauteur ", "erreur de saisie",
                                          MIN_HAUTEUR, MAX_HAUTEUR);
   unsigned nbr_objets = saisir<unsigned>("nbre object ", "erreur de saisie",
                                          MIN_NBR_OBJETS, Plateau::NB_ROBOT_MAX);

   Plateau plateau (largeur, hauteur);

   plateau.ajouterRobots(nbr_objets);

   do {
      plateau.afficher();
      plateau.bougerRobots();
      this_thread::sleep_for(chrono::milliseconds(SLEEP));
   } while (!plateau.partieFinie());

   plateau.afficher();

   cout << "Partie terminee !" << endl;

   viderBuffer();

   return EXIT_SUCCESS;
}
