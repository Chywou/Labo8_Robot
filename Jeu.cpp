//
// Created by timer on 14/01/2022.
//

#include "Jeu.h"
#include "Coordonnee.h"

using namespace std;
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

bool Jeu::CoordonneeUtilise(const Coordonnee &c) {
   for(Robot r: robots){
      if(r.coordonnee == c) return true;
   }
   return false;
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

Robot Jeu::prochainRobotAfficher(const Coordonnee& last) const {
   //exeception si robots.size() < 1
   Robot res = Robot(Coordonnee(largeur+1,hauteur+1));
   for(Robot r: robots) {
      if(last < r.coordonnee && res.coordonnee > r.coordonnee ){
         res = r;
      }
   }
   return res;
}

ostream& operator<< ( std::ostream& os, const Jeu& jeu){
//   for(Robot r: jeu.robots) {
//      os << r.id << " : " << r.cor.y << " " << r.cor.x << endl;
//   }

   os << string(jeu.largeur-jeu.posDepart +2, '-') << endl;
   Coordonnee c(jeu.posDepart,jeu.posDepart);
   //appelle a une fonction anonnyme
   Robot prochainRobot = *min_element(jeu.robots.begin(), jeu.robots.end(),[](const Robot& r, const Robot& u){
      return r.coordonnee < u.coordonnee;
   });
   for (; c.y < jeu.hauteur ; ++c.y) {
      os << "|";
      for (;c.x < jeu.largeur ; ++c.x) {
         if(c == prochainRobot.coordonnee) {
            os << prochainRobot.id;
            prochainRobot = jeu.prochainRobotAfficher(c);
         }else{
            os << " ";
         }
      }
      c.x = jeu.posDepart;
      os << "|" << endl;
   }
   os << string(jeu.largeur-jeu.posDepart +2, '-') << endl;
   return os;
}

