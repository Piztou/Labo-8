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
   void testerCollisions(); // TODO directement dans bougerRobots?
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
    * Surcharge d'afficheChar pour afficher un robot
    * Affiche le numéro d'ID du robot
    * @param robot Le robot à afficher
    */
   static void afficheChar(const Robot& robot);

   /**
    * Cherche tous les robots sur une ligne, retourne un tableau de leurs indexes
    * @param ligne La ligne où chercher les robots
    * @return Un liste d'indexes de robots
    */
   std::vector<size_t> trouveRobotsSurLigne (unsigned ligne);
};


#endif //INC_8_PLATEAU_H
