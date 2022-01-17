/*
-----------------------------------------------------------------------------------
Nom du fichier : Jeu.h
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Déclaration de la classe Jeu. Elle permet de gérer les différents
                 robots participents au jeu.

Remarque(s)    :


Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO8_ROBOT_JEU_H
#define LABO8_ROBOT_JEU_H
#include <vector>              // Permet d'utiliser les vector
#include <string>              // Permet d'utiliser les string
#include <ostream>             //
#include "Coordonnee.h"
#include "Robot.h"

class Jeu {
   friend std::ostream& operator<< ( std::ostream& os, const Jeu& jeu);

public:
   /// Nom                 Jeu
   /// But                 Constructeur de Jeu. Initialise les variables privées
   /// \param hauteur      Hauteur du jeu
   /// \param largeur      Largeur du jeu
   /// \param nbreRobot    Nombre de Robots
   /// \param posDepart
   Jeu(unsigned hauteur, unsigned largeur, unsigned nbreRobot, unsigned posDepartX = 0,unsigned posDepartY = 0 );

   /// Nom                 demmarrer
   /// But
   void demmarer();

private:
   const unsigned hauteur, largeur, posDepartX, posDepartY;
   std::vector<Robot> robots;
   std::vector<std::string> rapport;

   /// Nom                 coordonneeUtilise
   /// But                 Détériminée si des coordonnée sont déjà utilisée par un robot
   /// \param coordonnee   Coordonnneee à vérifier
   /// \return             Returne vrai si un Robot est déjà précend sur c
   bool coordonneeUtilise(const Coordonnee& coordonnee) const;

   /// Nom                 directionValide
   /// But                 Détérminer si une direction fournie est valide pour un
   ///                     robot donné
   /// \param r            Robot dont la direction doit être vérifiée
   /// \param direction    Direction à vérifier
   /// \return             Retourne vrai si la direction est valide, faux sinon
   bool directionValide(const Robot& robot, Robot::Direction direction, unsigned  = 1) const;

   /// Nom                 directionUtilisable
   /// But                 Obtenir une direction utilisable par le robot
   /// \param robot        Robot dont une direction utilisable doit être détérminée
   /// \return             Direction utilisable
   Robot::Direction directionUtilisable (const Robot& robot) const;

};


#endif //LABO8_ROBOT_JEU_H
