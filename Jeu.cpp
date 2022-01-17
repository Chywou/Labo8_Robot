/*
-----------------------------------------------------------------------------------
Nom du fichier : Jeu.cpp
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Définition de la classe Jeu.

Remarque(s)    :


Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <iostream>  // cout pour la fonction d'affichage
#include <thread>    // sleep_for pour mettre un temps entre l'affichage
#include <cassert>   // assert
#include "annexe.h"
#include "Jeu.h"


using namespace std;
Jeu::Jeu(unsigned int hauteur, unsigned int largeur, unsigned int nbreRobot, unsigned posDepartX, unsigned posDepartY) :
         hauteur(hauteur), largeur(largeur), posDepartX(posDepartX), posDepartY(posDepartY) {
   assert((largeur-posDepartX)*(hauteur-posDepartY) > nbreRobot);
   robots.reserve(nbreRobot);
   for(unsigned i = 1; i <= nbreRobot; ++i) {
      bool coordonneeUnique = true;
      do {
         Coordonnee coordonnee = Coordonnee(aleatoire(posDepartX,largeur),aleatoire(posDepartY,hauteur));
         if(!coordonneeUtilise(coordonnee)){
            // Ne crée pas de copy de l'object Coordonnee
            robots.emplace_back(coordonnee, i);
            coordonneeUnique = false;
         }
      } while (coordonneeUnique);
   }
}

bool Jeu::coordonneeUtilise(const Coordonnee& coordonnee) const {
   for(Robot r: robots){
      if(r.memeEmplacement(coordonnee)) return true;
   }
   return false;
}

bool Jeu::directionValide(const Robot& robot, Coordonnee::Direction direction, unsigned distance) const {
   switch (direction) {
      case Coordonnee::Direction::HAUT:
         if(robot.getCoordonnee().getY() == posDepartY) return false;
         break;
      case Coordonnee::Direction::BAS:
         if(robot.getCoordonnee().getY() == hauteur - 1) return false;
         break;
      case Coordonnee::Direction::GAUCHE:
         if(robot.getCoordonnee().getX()  == posDepartX) return false;
         break;
      case Coordonnee::Direction::DROITE:
         if(robot.getCoordonnee().getX() == largeur - 1) return false;
         break;
   }
   return true;
}

ostream& operator<< ( std::ostream& os, const Jeu& jeu){
   string plateau;
   string ligne;
   plateau.append(jeu.largeur+2, '-');
   plateau.append(1,'\n');
   ligne.append(1,'|');
   ligne.append(jeu.largeur,' ');
   ligne.append(1,'|');
   ligne.append(1,'\n');


   for (unsigned i = 0; i < jeu.hauteur; ++i) {
      plateau.append(ligne);
   }
   plateau.append(jeu.largeur+2, '-');

   for(Robot r: jeu.robots) {
      plateau[(r.coordonnee.y+1) * (jeu.largeur+3)+r.coordonnee.x+1] =  char(r.id + 48);
   }

   return os << plateau;

}

void Jeu::demmarer() {

   cout<< *this << endl;
   do {
      for (vector<Robot>::iterator robot = robots.begin(); robot < robots.end(); ++robot) {
         robot->deplacement(directionUtilisable(*robot));
         for (vector<Robot>::iterator it = robots.begin(); it < robots.end(); ++it) {
            if(robot->memeEmplacement(*it)){
               rapport.push_back(to_string(robot->getId()) + " a tue " + to_string(it->getId()));
               robots.erase(it);
               if(distance(it, robot) > 0) --robot;
               break;
            }
         }
      }


      system("cls");
      cout<< *this << endl;
      for(const string& s : rapport){
         cout << s << endl;
      }
      this_thread::sleep_for(200ms);
   } while (robots.size() > 1);
   cout << robots[0].getId() << " a gagne !" << endl;
}

Coordonnee::Direction Jeu::directionUtilisable(const Robot& robot) const {
   Coordonnee::Direction direction;
   do {
      direction = Coordonnee::Direction(aleatoire(0, (int)Coordonnee::getNbrDirection()));
   } while (!directionValide(robot, direction));

   return direction;
}