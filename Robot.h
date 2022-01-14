//
// Created by timer on 14/01/2022.
//

#ifndef LABO8_ROBOT_ROBOT_H
#define LABO8_ROBOT_ROBOT_H
#include "Jeu.h"

class Robot {
   friend class Jeu;

public:
   enum class Direction {HAUT, BAS, GAUCHE, DROITE};
   Robot(unsigned x, unsigned y);
   void deplacement(Direction direction, int distance = 1);
   bool memeDirection(const Robot& robot) const;
private:
   unsigned x, y;
   const unsigned id;
   static unsigned idSuivant;
};


#endif //LABO8_ROBOT_ROBOT_H
