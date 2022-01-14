//
// Created by timer on 14/01/2022.
//

#include "Jeu.h"
#include <ctime>

Jeu::Jeu(unsigned int hauteur, unsigned int largeur, unsigned int nbreRobot) :
         hauteur(hauteur), largeur(largeur) {

   robots.reserve(nbreRobot);
   for(unsigned i = 0; i < nbreRobot; ++i) {
      // Ajouter un test des positions générée avant la création du robot
      robots.push_back({generer(0, largeur - 1), generer(0, hauteur - 1)});
   }

}

unsigned int Jeu::generer(unsigned int min, unsigned int max) {
   static bool premierCycle = true;

   const unsigned DIFFERENCE_MIN_MAX = max + 1 - min;

   if (premierCycle) { // Doit être réalisé une seule fois
      srand((unsigned)time(NULL));
      premierCycle = false;
   }

   // Génère un nombre aléatoire entre min et max compris
   unsigned chiffreAlea = rand() % DIFFERENCE_MIN_MAX + min;

   return chiffreAlea;
}

bool Jeu::directionValide(const Robot &r, Robot::Direction direction) {
   switch (direction) {
      case Robot::Direction::HAUT:
         if(r.y == 0) return false;
         break;
      case Robot::Direction::BAS:
         if(r.y == hauteur - 1) return false;
         break;
      case Robot::Direction::GAUCHE:
         if(r.x == 0) return false;
         break;
      case Robot::Direction::DROITE:
         if(r.x == largeur - 1) return false;
         break;
   }
   return true;
}


