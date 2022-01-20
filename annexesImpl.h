/*
-----------------------------------------------------------------------------------
Nom du fichier : annexesImpl.h
Nom du Labo : 8 - Survivor
Auteur(s) : Gillioz Dorian & Yann Merk
Date creation : 16-01-2022
Description : Définitions des fonctions génériques saisir et aleatoire
Remarque(s) : -
Compilateur : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef INC_8_ANNEXESIMPL_H
#define INC_8_ANNEXESIMPL_H

#include <ctime>
#include <iostream>

template <typename T>
T saisir(const std::string& msgSaisie,
         const std::string& msgErreur,
         T min, T max) {
   bool erreur;
   T valeur;
   do {
      std::cout << msgSaisie << " [" << min << ".." << max << "] :";
      erreur = !(std::cin >> valeur) || valeur < min || valeur > max; // teste les erreurs de saisie

      if (erreur) {
         std::cout << msgErreur << std::endl;
         std::cin.clear();
      }
      viderBuffer();
   } while (erreur);

   return valeur;
}

template <typename T>
T aleatoire(T min, T max) {
   static bool premiereFois = true;

   // Si la fonction est appelée pour la première fois
   if (premiereFois) {
      // génère un seed pour les randoms
      srand((unsigned)time(NULL));
      premiereFois = false;
   }
   // retourne un nombre entier entre min et max
   return rand() % (max - min + 1) + min;
}

#endif //INC_8_ANNEXESIMPL_H
