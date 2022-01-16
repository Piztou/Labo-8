/*
-----------------------------------------------------------------------------------
Nom du fichier : Robot_est_sur_ligne.h
Nom du Labo : 8 - Survivor
Auteur(s) : Gillioz Dorian & Yann Merk
Date creation : 16-01-2022
Description : Fourni un foncteur permettant de trouver si un robot est sur une
              certaine ligne ou non
Compilateur : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/


#ifndef INC_8_ROBOT_EST_SUR_LIGNE_H
#define INC_8_ROBOT_EST_SUR_LIGNE_H


#include "Robot.h"

class Robot_est_sur_ligne {
public:
   explicit Robot_est_sur_ligne(unsigned ligne) : ligne(ligne) {}
   bool operator() (const Robot& robot) const {return robot.getY() == ligne;}
private:
   const unsigned ligne;
};


#endif //INC_8_ROBOT_EST_SUR_LIGNE_H
