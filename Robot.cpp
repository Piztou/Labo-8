/*
-----------------------------------------------------------------------------------
Nom du fichier : Robot.cpp
Nom du Labo    : 8 - Survivor
Auteurs        : Gillioz Dorian & Yann Merk
Date creation  : 14-01-2022
Description    : Implémentation de Robot
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include "Robot.h"

const char Robot::CHAR_INI  = '1';
unsigned Robot::next  = 0;

Robot::Robot(unsigned x, unsigned y) : id(next) {
   ++next;
   this->x = x;
   this->y = y;
}

Robot &Robot::operator=(Robot &&robot) {
   x = robot.x;
   y = robot.y;

   // Affecte id par pointeur
   const unsigned *ptr_const = &id;
   unsigned *ptr = (unsigned *)ptr_const;
   *ptr = robot.id;

   return *this;
}

bool Robot::operator==(const Robot &robot) const {
   return robot.x == x && robot.y == y;
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
         x -= distance;
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

char Robot::getChar() const {
   return char(id + CHAR_INI);
}
