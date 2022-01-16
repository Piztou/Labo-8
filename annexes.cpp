/*
-----------------------------------------------------------------------------------
Nom du fichier : annexes.cpp
Nom du Labo : 8 - Survivor
Auteur(s) : Gillioz Dorian & Yann Merk
Date creation : 16-01-2022
Description : <TODO>
Remarque(s) : <TODO>
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
/*
int saisir(const std::string& msgSaisie,
           const std::string& msgErreur,
           int min, int max) {
   bool erreur;
   int valeur;
   do {
      cout << msgSaisie << " [" << min << ".." << max << "] :";
      erreur = !(cin >> valeur) || valeur < min || valeur > max;

      if (erreur) {
         cout << msgErreur << endl;
         cin.clear();
      }
      viderBuffer();
   } while (erreur);

   return valeur;
}*/
