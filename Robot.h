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
   friend std::ostream& operator<< ( std::ostream& os, const Jeu& jeu); // pour avoir acces au champs prive de la
                                                                        // class pour l'affichage du jeu
public:


   /// Nom                 Robot
   /// But                 Constructeur à 1 paramètre de la classe Robot, initialise
   ///                     coordonne et atribue un id unique à l'objet
   /// \param coordonnee
   Robot(const Coordonnee& coordonnee, unsigned id);


   /// Nom                 operator=
   /// \param robot        robot a copier dans le nouveau robot
   /// \return             le robot copier
   Robot& operator= (const Robot& robot);

   bool memeEmplacement (const Robot& robot);
   bool memeEmplacement (const Coordonnee& coordonnee);

   unsigned getId();

   void deplacement(Coordonnee::Direction direction, unsigned distance = 1);

   Coordonnee getCoordonnee() const;

private:
   Coordonnee coordonnee;
   const unsigned id;
};


#endif //LABO8_ROBOT_ROBOT_H
