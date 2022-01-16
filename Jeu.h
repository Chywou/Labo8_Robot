//
// Created by timer on 14/01/2022.
//

#ifndef LABO8_ROBOT_JEU_H
#define LABO8_ROBOT_JEU_H
#include <vector>
#include <string>
#include <ostream>
#include "Coordonnee.h"
#include "Robot.h"

class Jeu {
   friend std::ostream& operator<< ( std::ostream& os, const Jeu& jeu);
public:
   Jeu(unsigned hauteur, unsigned largeur, unsigned nbreRobot, unsigned posDepart = 0);
   void demmarer();
private:
   const unsigned hauteur, largeur, posDepart;
   std::vector<Robot> robots;
   std::vector<std::string> raport;

   bool CoordonneeUtilise(const Coordonnee& c);
   bool directionValide(const Robot& r, Robot::Direction direction);
   Robot::Direction genererDirection (const Robot& r);
};


#endif //LABO8_ROBOT_JEU_H
