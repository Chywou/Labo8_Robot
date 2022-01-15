//
// Created by timer on 14/01/2022.
//

#include "Jeu.h"
#include "Coordonnee.h"

Jeu::Jeu(unsigned int hauteur, unsigned int largeur, unsigned int nbreRobot, unsigned posDepart) :
         hauteur(hauteur), largeur(largeur), posDepart(posDepart) {

   robots.reserve(nbreRobot);
   for(unsigned i = 0; i < nbreRobot; ++i) {
      bool coordonneeUnique = true;
      do {
         Coordonnee coor = Coordonnee::generer(posDepart, largeur, hauteur);
         if(!CoordonneeUtilise(coor)){
            //ne cree pas de copy de l'object Coordonnee
            robots.emplace_back(coor);
            coordonneeUnique = false;
         }
      } while (coordonneeUnique);



   }

}


bool Jeu::directionValide(const Robot &r, Robot::Direction direction) {
   switch (direction) {
      case Robot::Direction::HAUT:
         if(r.coordonnee.y == 0) return false;
         break;
      case Robot::Direction::BAS:
         if(r.coordonnee.y  == hauteur - 1) return false;
         break;
      case Robot::Direction::GAUCHE:
         if(r.coordonnee.x  == 0) return false;
         break;
      case Robot::Direction::DROITE:
         if(r.coordonnee.x  == largeur - 1) return false;
         break;
   }
   return true;
}


