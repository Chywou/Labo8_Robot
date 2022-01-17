/*
-----------------------------------------------------------------------------------
Nom du fichier : Coordonnee.cpp
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Définition de la classe Coordonnee

Remarque(s)    :


Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <ctime>
#include "Coordonnee.h"

using namespace std;

Coordonnee::Coordonnee(unsigned int x, unsigned int y): x(x), y(y) {}

Coordonnee Coordonnee::generer(unsigned minX, unsigned minY, unsigned maxX, unsigned maxY) {
   static bool init = true;
   if(init){
      srand(time(NULL));
      init = false;
   }
   return {(rand()%(maxX-minX))+minX,(rand()%(maxY-minY))+minY};
}

bool Coordonnee::operator==(const Coordonnee& coordonnee) const {
   return (x == coordonnee.x && y == coordonnee.y);
}
