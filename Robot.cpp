/*
-----------------------------------------------------------------------------------
Nom du fichier : Robot.cpp
Nom du Labo : 8 - Survivor
Auteur(s) : Gillioz Dorian & Yann Merk
Date creation : 14-01-2022
Description : <TODO>
Remarque(s) : <TODO>
Compilateur : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include "Robot.h"

unsigned Robot::next  = 0;
unsigned Robot::total = 0;

Robot::Robot(unsigned int x, unsigned int y) : id(next) {
   ++next;
   ++total;
   this->x = x;
   this->y = y;
}

Robot::~Robot() {
   --total;
}

void Robot::deplacement(Direction direction, unsigned distance) {

   switch (direction) {
      case Direction::UP:
         y -= distance;
         break;
      case Direction::DOWN:
         y += distance;
         break;
      case Direction::RIGHT:
         x += distance;
         break;
      case Direction::LEFT:
         x += distance;
         break;
   }
}

unsigned Robot::getId() const {
   return id;
}

unsigned Robot::getX() const {
   return x;
}

unsigned Robot::getY() const {
   return y;
}

unsigned Robot::getTotal() {
   return total;
}
