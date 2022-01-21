/*
-----------------------------------------------------------------------------------
Nom du fichier : Robot.cpp
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Définitiion de la classe Robot.

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include "Robot.h"

Robot::Robot(const Coordonnee& coordonnee, unsigned id): coordonnee(coordonnee), id(id) {}

Robot& Robot::operator=(const Robot& robot) {
   // cast permettant de changer la valeur d'une variable constante
   (unsigned &)this->id = robot.id;
   this->coordonnee = robot.coordonnee;

   return *this;
}

bool Robot::operator==(const Robot& robot) const {
  return coordonnee == robot.coordonnee && id != robot.id ;
}

bool Robot::operator==(const Coordonnee& coordonnee) const {
   return this->coordonnee == coordonnee;
}

void Robot::deplacement(Coordonnee::Direction direction, unsigned int distance) {
   coordonnee.deplacement(direction, distance);
}

unsigned Robot::getId() const {
   return id;
}

Coordonnee Robot::getCoordonnee() const {
   return coordonnee;
}