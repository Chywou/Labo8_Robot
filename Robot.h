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
#include "Coordonnee.h"      // Utilisation de la class Coordonnee

class Robot {
public:

   /// Nom                 Robot
   /// But                 Constructeur à 1 paramètre de la classe Robot, initialise
   ///                     coordonne et atribue un id unique à l'objet
   /// \param coordonnee
   Robot(const Coordonnee& coordonnee, unsigned id);


   /// Nom                 operator=
   /// But                 Opérateur d'affectation
   /// \param robot        robot a copier dans le nouveau robot
   /// \return             le robot copier
   Robot& operator= (const Robot& robot);

   /// Nom                 memeEmplacement
   /// But                 Détérminer si le robot passé en paramètre est situé à la
   ///                     même position que le robot implicite
   /// \param robot        Le robot à comparer
   /// \return             Vrai si les 2 robots sont sur les même coordonnées, faux sinon
   bool memeEmplacement (const Robot& robot);

   /// Nom                 memeEmplacement
   /// But                 Détérminer si les coordonnée passée en paramètre sont
   ///                     identiques au robot implicite
   /// \param coordonne   Coordonnée à comparer
   /// \return             Vrai si les coordonnées sont identiques au robot, faux sinon
   bool memeEmplacement (const Coordonnee& coordonnee);

   /// Nom                 deplacement
   /// But                 Déplacer le robot d'une distance détérminée dans une direction
   ///                     détérminée
   /// \param direction    Direction du déplacement
   /// \param distance     Nombre d'unité dont le robot se déplace
   void deplacement(Coordonnee::Direction direction, unsigned distance = 1);

   /// Nom                 getId
   /// But                 Retourner l'id de l'objet courant
   /// \return             Retourne id
   unsigned getId() const;

   /// Nom                 getCoordonnee
   /// But                 Retourner les coordoonées du robot
   /// \return             Retourne coordonnee
   Coordonnee getCoordonnee() const;

private:
   Coordonnee coordonnee;
   const unsigned id;
};


#endif //LABO8_ROBOT_ROBOT_H
