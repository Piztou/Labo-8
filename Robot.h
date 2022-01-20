/*
-----------------------------------------------------------------------------------
Nom du fichier : Robot.h
Nom du Labo    : 8 - Survivor
Auteurs        : Gillioz Dorian & Yann Merk
Date creation  : 14-01-2022
Description    : Déclare l'objet robot, un bête objet muni de coordonnées et d'un ID
                 pouvant se déplacer dans les directions décrites dans Direction
                 N'a aucune notion de son environnement, les tests nécessaires
                 doivent être implémentés par l'appelant
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
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

   /**
    * Constructeur par copie
    * @param robot Le robot à copier
    */
   constexpr Robot(const Robot& robot) = default;

   /**
    * Opérateur d'affectation de Robot
    * @param robot Le robot dont il faut récupérer les valeurs
    * @return Le robot avec ses nouvelles valeurs
    * @remark Affecte id à l'aide d'une manipulation de pointeurs
    */
   Robot& operator=(Robot&& robot);

   /**
    * Compare la position de deux robots
    * @param robot le robot avec lequel comparer
    * @return true si les coordonnées des deux robots sont égales
    */
   bool operator==(const Robot& robot) const;

   // Enum listant toutes les directions possibles pour le robot
   enum class Direction {UP = 0, DOWN, RIGHT, LEFT};

   /**
    * Déplace le robot dans une Direction d'une certaine Distance\n
    * Le robot n'a aucune intelligence, ne gère pas le cas de dépassement du terrain
    * @param direction La direction dans laquelle se déplacer
    */
   void deplacement(Direction direction, unsigned distance = 1);
   unsigned getId() const;
   unsigned getX()  const;
   unsigned getY()  const;
   /**
    * Retourne le caractère représentant ce robot, déterminé à partir de son id
    */
   char  getChar()  const;

private:
   unsigned x,y;
   const unsigned id;
   static const char CHAR_INI;
   static unsigned next;
};


#endif //INC_8_ROBOT_H
