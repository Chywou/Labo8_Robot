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
#include <iostream>
#include <thread>
#include <algorithm>
#include "Jeu.h"

using namespace std;
Jeu::Jeu(unsigned int hauteur, unsigned int largeur, unsigned int nbreRobot, unsigned posDepart) :
         hauteur(hauteur), largeur(largeur), posDepart(posDepart) {

   robots.reserve(nbreRobot);
   for(unsigned i = 0; i < nbreRobot; ++i) {
      bool coordonneeUnique = true;
      do {
         Coordonnee coor = Coordonnee::generer(posDepart, largeur, hauteur);
         if(!coordonneeUtilise(coor)){
            // Ne crée pas de copy de l'object Coordonnee
            robots.emplace_back(coor);
            coordonneeUnique = false;
         }
      } while (coordonneeUnique);


   }
}

bool Jeu::coordonneeUtilise(const Coordonnee &coordonnee) const {
   for(Robot r: robots){
      if(r.coordonnee == coordonnee) return true;
   }
   return false;
}

bool Jeu::directionValide(const Robot &r, Robot::Direction direction) const {
   switch (direction) {
      case Robot::Direction::HAUT:
         if(r.coordonnee.y == posDepart) return false;
         break;
      case Robot::Direction::BAS:
         if(r.coordonnee.y  == hauteur - 1) return false;
         break;
      case Robot::Direction::GAUCHE:
         if(r.coordonnee.x  == posDepart) return false;
         break;
      case Robot::Direction::DROITE:
         if(r.coordonnee.x  == largeur - 1) return false;
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
      for(Robot& robot: robots){
         robot.deplacement(directionUtilisable(robot));
         for (vector<Robot>::iterator it = robots.begin(); it < robots.end(); ++it) {
            if(robot.coordonnee == it->coordonnee && robot.id != it->id){
               rapport.push_back(to_string(robot.id) + " a tue " + to_string(it->id));
               robots.erase(it);
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
   cout << robots[0].id << " a gagne !" << endl;
}

Robot::Direction Jeu::directionUtilisable(const Robot& robot) const {
   Robot::Direction direction;
   do {
      direction = Robot::genererDirection();
   } while (!directionValide(robot, direction));

   return direction;
}