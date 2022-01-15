//
// Created by timer on 14/01/2022.
//

#ifndef LABO8_ROBOT_ROBOT_H
#define LABO8_ROBOT_ROBOT_H
#include "Coordonnee.h"


class Robot {
   friend class Jeu;

public:
   enum class Direction {HAUT, BAS, GAUCHE, DROITE};
   Robot(const Coordonnee& coordonnee);
   void deplacement(Direction direction, unsigned distance = 1);
   bool memeDirection(const Robot& robot) const;
   static Direction genererDirection();
private:
   Coordonnee coordonnee;
   const unsigned id;
   static unsigned idCourant;
   static const unsigned NBRE_DIRECTION;
};


#endif //LABO8_ROBOT_ROBOT_H
