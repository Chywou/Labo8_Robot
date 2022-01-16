//
// Created by Tim on 15/01/2022.
//

#ifndef LABO8_ROBOT_COORDONNEE_H
#define LABO8_ROBOT_COORDONNEE_H

#include <ostream>
class Robot;
class Jeu;

class Coordonnee {
   friend class Jeu;
   friend class Robot;

   friend std::ostream& operator<< ( std::ostream& os, const Jeu& jeu);
public:
   Coordonnee(unsigned x, unsigned y);
   bool operator==(const Coordonnee& c);
   static Coordonnee generer(unsigned min, unsigned maxX, unsigned maxY);

private:
   unsigned x;
   unsigned y;
};


#endif //LABO8_ROBOT_COORDONNEE_H
