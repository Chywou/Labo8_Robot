//
// Created by timer on 14/01/2022.
//

#include "Robot.h"

unsigned Robot::idCourant = 0;

Robot::Robot(unsigned int x, unsigned int y) : x(x), y(y), id(++idCourant) {}

void Robot::deplacement(Direction direction, unsigned distance) {
   switch (direction) {
      case Robot::Direction::HAUT:
         y -= distance;
         break;
      case Robot::Direction::BAS:
         y += distance;
         break;
      case Robot::Direction::GAUCHE:
         x -= distance;
         break;
      case Robot::Direction::DROITE:
         x += distance;
         break;

   }
}