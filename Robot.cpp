//
// Created by timer on 14/01/2022.
//
#include <ctime>
#include <cstdlib>
#include "Robot.h"

unsigned Robot::idCourant = 0;
const unsigned Robot::NBRE_DIRECTION = 4;
Robot::Robot(const Coordonnee &coordonnee): coordonnee(coordonnee), id(idCourant) {
   ++idCourant;
}

void Robot::deplacement(Direction direction, unsigned distance) {
   switch (direction) {
      case Robot::Direction::HAUT:
         coordonnee.y -= distance;
         break;
      case Robot::Direction::BAS:
         coordonnee.y += distance;
         break;
      case Robot::Direction::GAUCHE:
         coordonnee.x -= distance;
         break;
      case Robot::Direction::DROITE:
         coordonnee.x += distance;
         break;

   }
}


Robot::Direction Robot::genererDirection() {
   static bool premierCycle = true;

   if (premierCycle) { // Doit être réalisé une seule fois
      srand((unsigned)time(NULL));
      premierCycle = false;
   }

   // Génère un nombre aléatoire 0 et le nombre de direction
   return Robot::Direction(rand()%(NBRE_DIRECTION-1));
}

Robot& Robot::operator=(const Robot &r) {
   this->coordonnee = r.coordonnee;
   this->id = r.id;

   return *this;
}
