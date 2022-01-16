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
#include "Plateau.h"

using namespace std;

int main() {
   std::cout << "Hello, World!" << std::endl;

   // TODO : utiliser un using pour le type des coordonnées ?

   Plateau plateau (10,10);

   plateau.ajouterRobots(10);

   plateau.afficher();

   return 0;
}
