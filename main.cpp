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

#include "Plateau.h"

using namespace std;

int main() {
   std::cout << "Hello, World!" << std::endl;

   // TODO : utiliser un using pour le type des coordonnées ?

   Plateau plateau (20,10);

   plateau.ajouterRobots(10);

   for (int i = 0; i < 100; ++i) {
      plateau.afficher();
      plateau.bougerRobots();
      this_thread::sleep_for(chrono::milliseconds(200));
   }

   return 0;
}
