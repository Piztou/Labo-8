/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Nom du Labo : 8 - Survivor
Auteur(s) : Gillioz Dorian & Yann Merk
Date creation : 14-01-2022
Description : <TODO>
Remarque(s) : <TODO>
Compilateur : Mingw-w64 g++ 11.2.0
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

   const unsigned SLEEP = 200;
   const unsigned MIN_LARGEUR    = 10,
                  MAX_LARGEUR    = 1000,
                  MIN_HAUTEUR    = 10,
                  MAX_HAUTEUR    = 1000,
                  MIN_NBR_OBJETS = 1,
                  MAX_NBR_OBJETS = 9;

   // TODO : utiliser un using pour le type des coordonnées ?

   unsigned largeur = saisir<unsigned>("largeur ", "erreur de saisie",
                                       MIN_LARGEUR, MAX_LARGEUR);
   unsigned hauteur = saisir<unsigned>("hauteur ", "erreur de saisie",
                                       MIN_HAUTEUR, MAX_HAUTEUR);
   unsigned nbr_objets = saisir<unsigned>("nbre object ", "erreur de saisie",
                                          MIN_NBR_OBJETS, MAX_NBR_OBJETS);

   Plateau plateau (largeur, hauteur);

   plateau.ajouterRobots(nbr_objets);

   do {
      plateau.afficher();
      plateau.bougerRobots();
      this_thread::sleep_for(chrono::milliseconds(SLEEP));
   } while (!plateau.partieFinie());

   viderBuffer();

   return EXIT_SUCCESS;
}
