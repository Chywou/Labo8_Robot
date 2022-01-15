//
// Created by Tim on 15/01/2022.
//

#include <ctime>
#include "Coordonnee.h"

using namespace std;

Coordonnee::Coordonnee(unsigned int x, unsigned int y): x(x), y(y) {}

Coordonnee Coordonnee::generer(unsigned min, unsigned maxX, unsigned maxY) {
   static bool init = true;
   if(init){
      srand(time(NULL));
      init = false;
   }
   return Coordonnee((rand()%(maxX-min))+min,(rand()%(maxY-min))+min);
}

bool Coordonnee::operator==(const Coordonnee &c) {
   return (x == c.x && y == c.y);
}

bool Coordonnee::operator<(const Coordonnee &c) const {
   if(y<c.y){
      return true;
   }
   if(y== c.y){
      if(x < c.x){
         return true;
      }
   }
   return false;
}

bool Coordonnee::operator<=(const Coordonnee &c) const {
   return !(*this < c);
}

bool Coordonnee::operator>(const Coordonnee &c) const {
   return c < *this;
}

bool Coordonnee::operator>=(const Coordonnee &c) const {
   return !(c < *this);
}