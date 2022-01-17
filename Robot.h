/*
-----------------------------------------------------------------------------------
Nom du fichier : Robot.cpp
Nom du Labo : 8 - Survivor
Auteur(s) : Gillioz Dorian & Yann Merk
Date creation : 14-01-2022
Description : <TODO> plus de commentaires?
Remarque(s) : <TODO>
Compilateur : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef INC_8_ROBOT_H
#define INC_8_ROBOT_H


class Robot {
public:
   /**
    * Initialisation d'un Robot
    * @param x Position horizontale
    * @param y Position verticale
    */
   Robot(unsigned x, unsigned y);

   ~Robot();
   enum class Direction {UP = 0, DOWN, RIGHT, LEFT};
   /**
    * Déplace le robot dans une Direction d'une certaine Distance\n
    * Le robot n'a aucune intelligence, ne gère pas le cas de dépassement du terrain
    * @param direction La direction dans laquel se déplacer
    */
   void deplacement(Direction direction, unsigned distance = 1);
   unsigned getId() const;
   unsigned getX() const;
   unsigned getY() const;
   static unsigned getTotal();
private:
   unsigned x,y;
   const unsigned id;
   static unsigned total;
   static unsigned next;
};


#endif //INC_8_ROBOT_H
