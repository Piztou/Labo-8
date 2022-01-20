/*
-----------------------------------------------------------------------------------
Nom du fichier : annexes.h
Nom du Labo    : 8 - Survivor
Auteurs        : Gillioz Dorian & Yann Merk
Date creation  : 16-01-2022
Description    : En-tête de la librairie annexes, qui contient les déclarations des
                 fonctions viderBuffer, saisir et aléatoire
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef INC_8_ANNEXES_H
#define INC_8_ANNEXES_H

#include <string>

/**
 * Permet de vider le buffer
 */
void viderBuffer();

/**
 * Permet à l'utilisateur de saisir une valeur
 * entre deux bornes données
 * @tparam T        le type de la valeur que l'on veut saisir
 * @param msgSaisie Message à afficher lors la saisie
 * @param msgErreur Message à afficher en cas d'erreur de saisie
 * @param min       La valeur minimale autorisée
 * @param max       La valeur maximale autorisée
 * @return          la valeur saisie
 */
template <typename T>
T saisir(const std::string& msgSaisie,
         const std::string& msgErreur,
         T min, T max);

/**
 * génère une valeur aléatoire entre deux bornes données
 * @tparam T  le type de la valeur que l'on veut générer
 * @param min la valeur minimale qui peut être générée
 * @param max la valeur maximale qui peut être générée
 * @return    le nombre aléatoire généré
 */
template <typename T>
T aleatoire(T min, T max);

#include "annexesImpl.h"

#endif //INC_8_ANNEXES_H
