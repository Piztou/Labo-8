//
// Created by Dorian on 16.01.2022.
//

#ifndef INC_8_ANNEXESIMPL_H
#define INC_8_ANNEXESIMPL_H

#include <time.h>
#include <iostream>

template <typename T>
T saisir(const std::string& msgSaisie,
         const std::string& msgErreur,
         T min, T max) {
   bool erreur;
   T valeur;
   do {
      std::cout << msgSaisie << " [" << min << ".." << max << "] :";
      erreur = !(std::cin >> valeur) || valeur < min || valeur > max;

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
   if (premiereFois){
      // génère un seed pour les randoms
      srand((unsigned int)time(NULL));
      premiereFois = false;
   }
   // retourne un nombre entier entre min et max
   return rand() % (max - min + 1) + min;
}

#endif //INC_8_ANNEXESIMPL_H
