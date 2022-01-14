//
// Created by timer on 14/01/2022.
//

#ifndef LABO8_ROBOT_JEU_H
#define LABO8_ROBOT_JEU_H
#include <vector>
#include <ostream>
#include "Robot.h"


class Jeu {
   friend std::ostream& operator<< ( std::ostream& os, const Jeu& jeu);
public:
   Jeu(unsigned hauteur, unsigned largeur, unsigned nbreRobot);
   unsigned generer(unsigned min, unsigned max);
   bool directionValide(const Robot& r, Robot::Direction direction);
private:
   const unsigned hauteur, largeur;
   std::vector<Robot> robots;

};


#endif //LABO8_ROBOT_JEU_H
