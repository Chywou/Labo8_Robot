//
// Created by timer on 14/01/2022.
//

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
   //===================================
   // Constructeur Robot a besoin de coordonnee
   // pour etre cree. il va initialiser coordonnee
   // et attribuer un id
   //===================================
   Robot(const Coordonnee& coordonnee);
   //===================================
   // fonction qui permet de déplacer le robot
   // dans une certaine direction et a une certaine
   // distance
   //===================================
   void deplacement(Direction direction, unsigned distance = 1);
   //===================================
   // cette fonction gnerere une direction
   // de maniere aleatoire
   //===================================
   static Direction genererDirection();
private:
   Coordonnee coordonnee;                 // coordonnee du robot
   //===================================
   // l'id du robot ne peux pas etre const sinon
   // l'operateur = est implicitement supprimé
   //===================================
   unsigned id;
   static unsigned idCourant;             // l'id courant est egale au nombre de robot cree
   static const unsigned NBRE_DIRECTION;  // nombre de direction que le robot peut se deplacer
};


#endif //LABO8_ROBOT_ROBOT_H
