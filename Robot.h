/*
-----------------------------------------------------------------------------------
Nom du fichier : Robot.h
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Déclaration de la classe Robot.

Remarque(s)    :


Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO8_ROBOT_ROBOT_H
#define LABO8_ROBOT_ROBOT_H
#include <ostream>
#include "Coordonnee.h"

class Jeu; //definir qu'une classe jeu existe

class Robot {
   friend class Jeu; // class en ami pour avoir acces au element prive de cette class
   friend std::ostream& operator<< ( std::ostream& os, const Jeu& jeu); // pour avoir acces au champs prive de la
                                                                        // class pour l'affichage du jeu
public:
   enum class Direction {HAUT, BAS, GAUCHE, DROITE};

   /// Nom                 Robot
   /// But                 Constructeur à 1 paramètre de la classe Robot, initialise
   ///                     coordonne et atribue un id unique à l'objet
   /// \param coordonnee
   Robot(const Coordonnee& coordonnee);

   /// Nom                 deplacement
   /// But                 Deplacer le robot dans une direction et d'une distance choisie
   /// \param direction    Direction dans laquelle le robot se déplace
   /// \param distance     Nombre d'unité dont le robot se déplace
   void deplacement(Direction direction, unsigned distance = 1);

   /// Nom                 genererDirection
   /// But                 Générer une direction aléatoirement
   /// \return
   static Direction genererDirection();
private:
   Coordonnee coordonnee;                 // coordonnee du robot
   //===================================
   // l'id du robot ne peux pas etre const sinon
   // l'operateur = est implicitement supprimé
   //===================================
   unsigned id;
   static unsigned idCourant;             // L'id courant est egale au nombre de robot cree
   static const unsigned NBRE_DIRECTION;  // Nombre de directions que le robot peut se deplacer
};


#endif //LABO8_ROBOT_ROBOT_H
