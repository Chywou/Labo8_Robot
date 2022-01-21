/*
-----------------------------------------------------------------------------------
Nom du fichier : Coordonnee.cpp
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Définition de la classe Coordonnee.

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include "Coordonnee.h"

const unsigned Coordonnee::NBRE_DIRECTION   = 4;

Coordonnee::Coordonnee(unsigned x, unsigned y): x(x), y(y) {}


bool Coordonnee::operator==(const Coordonnee& coordonnee) const {
   return x == coordonnee.x && y == coordonnee.y;
}


void Coordonnee::deplacement(Direction direction, unsigned distance) {
   switch (direction) {
      case Coordonnee::Direction::HAUT:
         y -= distance;
         break;
      case Coordonnee::Direction::BAS:
         y += distance;
         break;
      case Coordonnee::Direction::GAUCHE:
         x -= distance;
         break;
      case Coordonnee::Direction::DROITE:
         x += distance;
         break;
   }
}

unsigned Coordonnee::getX() const {
   return x;
}

unsigned Coordonnee::getY() const {
   return y;
}

unsigned Coordonnee::getNbrDirection() {
   return NBRE_DIRECTION;
}