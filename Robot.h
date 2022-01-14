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

#ifndef INC_8_ROBOT_H
#define INC_8_ROBOT_H


class Robot {
   Robot(unsigned x, unsigned y);
   ~Robot();
   enum class Direction {UP, DOWN, RIGHT, LEFT};
   void deplacement(Direction direction);

   unsigned getId() const;
   unsigned getX();
   unsigned getY();
   static unsigned getTotal();
private:
   unsigned x,y;
   const unsigned id;
   static unsigned total;
   static unsigned next;
};


#endif //INC_8_ROBOT_H
