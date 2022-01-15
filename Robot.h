//
// Created by timer on 14/01/2022.
//

#ifndef LABO8_ROBOT_ROBOT_H
#define LABO8_ROBOT_ROBOT_H
#include <ostream>
#include "Coordonnee.h"

class Jeu;
class Robot {
   friend class Jeu;
   friend std::ostream& operator<< ( std::ostream& os, const Jeu& jeu);
public:
   enum class Direction {HAUT, BAS, GAUCHE, DROITE};
   Robot(const Coordonnee& coordonnee);
   void deplacement(Direction direction, unsigned distance = 1);
   bool memeDirection(const Robot& robot) const;
   static Direction genererDirection();
   Robot& operator=(const Robot& r);//pour le vector<Robot>.erase
private:
   Coordonnee coordonnee;
   unsigned id; //attention modifier pour l'opérateur =
   static unsigned idCourant;
   static const unsigned NBRE_DIRECTION;
};


#endif //LABO8_ROBOT_ROBOT_H
