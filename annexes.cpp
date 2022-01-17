/*
-----------------------------------------------------------------------------------
Nom du fichier : annexes.cpp
Nom du Labo : 8 - Survivor
Auteur(s) : Gillioz Dorian & Yann Merk
Date creation : 16-01-2022
Description : Définition de la fonction viderBuffer
Remarque(s) : -
Compilateur : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include <limits>

#include "annexes.h"

using namespace std;

void viderBuffer() {
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
