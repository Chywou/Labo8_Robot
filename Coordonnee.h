//
// Created by Tim on 15/01/2022.
//

#ifndef LABO8_ROBOT_COORDONNEE_H
#define LABO8_ROBOT_COORDONNEE_H


class Robot;
class Jeu;

class Coordonnee {
   friend class Robot;
   friend class Jeu;
   friend std::ostream& operator<< ( std::ostream& os, const Jeu& jeu);
public:
   Coordonnee(unsigned x, unsigned y);

   bool operator==(const Coordonnee& c);
   bool operator<  (const Coordonnee& c) const;
   bool operator>  (const Coordonnee& c) const;
   bool operator<= (const Coordonnee& c) const;
   bool operator>= (const Coordonnee& c) const;
   static Coordonnee generer(unsigned min, unsigned maxX, unsigned maxY);

private:
   unsigned x;
   unsigned y;
};


#endif //LABO8_ROBOT_COORDONNEE_H
