/*
-----------------------------------------------------------------------------------
Nom du fichier : Plateau.h
Nom du Labo : 8 - Survivor
Auteur(s) : Gillioz Dorian & Yann Merk
Date creation : 14-01-2022
Description : <TODO>
Remarque(s) : <TODO>
Compilateur : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef INC_8_PLATEAU_H
#define INC_8_PLATEAU_H

#include <vector>

#include "Robot.h"

class Plateau {
public:
   // Quantité maximum de robots pouvant être gérés par le plateau
   static const unsigned NB_ROBOT_MAX;
   /**
    * Crée un plateau avec les dimensions données
    * @param largeur Largeur du plateau
    * @param hauteur Hauteur du plateau
    */
   Plateau(unsigned largeur, unsigned hauteur);

   /**
    * Ajoute une certaines quantité de Robots sur le terrain à des emplacements
    * aléatoire
    * @remark Quitte le programme (assert) si NB_ROBOT_MAX n'est pas respecté
    * @param quantite La quantité de robot à ajouter
    */
   void ajouterRobots(unsigned quantite);
   void afficher();
   void bougerRobots();
   bool partieFinie();

private:
   // Le caractère utilisé pour le bord haut et bas du tableau
   static const char     CAR_LIGNE;
   // Le caractère utilisé pour le bord gauche et droit du tableau
   static const char     CAR_COL;
   // Le caractère utilisé quand il n'y a pas de robots
   static const char     CAR_VIDE;
   // L'épaisseur des bordures du tableau
   static const unsigned EPAISSEUR_BORDURE;
   // Le nombre de robot auquel la partie s'arrête (ou inférieur)
   static const unsigned NB_ROBOT_FIN;

   // Le message sortit quand un robot tue un autre, en 2 partie
   static const char* MESSAGE_KILL_1;
   static const char* MESSAGE_KILL_2;
   // La command système utilisée pour vider l'écran, dépendant du système
   // d'exploitation
   static const char* SYSTEM_CLEAR;

   // Pour stocker les messages de kills précédents
   std::string messages_kills;

   unsigned largeur, hauteur;
   std::vector<Robot> robots;

   /**
    * Cherche un robot à une position, retourne true si au moins un est présent
    * autrement false
    * @param x Position horizontale à vérifier
    * @param y Position verticale à vérifier
    * @return true si un robot à été trouvé, autrement false
    */
   bool chercheRobot(unsigned x, unsigned y);

   /**
    * cout (taille) fois le caractere, et reviens à la ligne
    * @param taille    Le nombre de caractère
    * @param caractere Le caractère à répéter pour la ligne
    */
   static void afficheChar(unsigned taille, char caractere = CAR_LIGNE);


   /**
    * Cherche tous les robots sur une ligne, retourne un tableau de leurs pointeurs
    * @param ligne La ligne où chercher les robots
    * @return Une Liste de pointeurs vers ces robots
    */
   std::vector<Robot*> trouveRobotsSurLigne (unsigned ligne);

   /**
    * Vérifie si le robot passé en itérateur est entré en collisions avec
    * un autre, et détruit l'autre si c'est le cas
    * @param itRobot le robot à tester
    *                L'itérateur sera décalé automatiquement si un élément précédent
    *                est supprimé
    */
   void appliquerCollisions(std::vector<Robot>::iterator& itRobot);

   /**
    * Ajoute un message de mort à messages_kills
    * @param tueur Le robot ayant détruit
    * @param tue   Le robot ayant été détruit
    */
   void ajouteMessageDestruction(const Robot& tueur, const Robot& tue);
};


#endif //INC_8_PLATEAU_H
