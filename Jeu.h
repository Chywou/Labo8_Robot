/*
-----------------------------------------------------------------------------------
Nom du fichier : Jeu.h
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Déclaration de la classe Jeu. Elle permet de gérer les différents
                 robots participents au jeu. Elle est également chargée de faire un
                 affichage du jeu.

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO8_ROBOT_JEU_H
#define LABO8_ROBOT_JEU_H

#include <vector>              // Utilisation de vector
#include <string>              // Utilisation de string
#include <ostream>             // std::ostream& operator<<
#include "Coordonnee.h"        // Utilisation de la class Coordonnee
#include "Robot.h"             // Utilisation de la class Robot

class Jeu {

   /// Nom                 operator<<
   /// But                 Fonction amie permettant d'afficher le jeu via un cout
   /// \param os           Objet ostream
   /// \param jeu          Jeu à afficher
   /// \return             L'objet ostream modifié
   friend std::ostream& operator<< ( std::ostream& os, const Jeu& jeu);

public:

   /// Nom                 Jeu
   /// But                 Constructeur de Jeu. Initialise les variables privées
   /// \param hauteur      Hauteur du jeu
   /// \param largeur      Largeur du jeu
   /// \param nbreRobot    Nombre de Robots
   Jeu(unsigned hauteur, unsigned largeur, unsigned nbreRobot);

   /// Nom                 lancementJeu
   /// But                 Lancer le jeu
   void lancementJeu();

private:

   const unsigned hauteur, largeur;
   std::vector<Robot> robots;
   std::vector<std::string> rapport;

   /// Nom                 coordonneeUtilise
   /// But                 Détériminée si des coordonnées sont déjà utilisée par un robot
   /// \param coordonnee   Coordonnnee à vérifier
   /// \return             Returne vrai si un Robot est déjà présent sur coordonnee
   bool coordonneeUtilise(const Coordonnee& coordonnee) const;

   /// Nom                 directionValide
   /// But                 Détérminer si une direction fournie est valide pour un
   ///                     robot donné
   /// \param robot        Robot dont la direction doit être vérifiée
   /// \param direction    Direction à vérifier
   /// \param distance     Distance de déplacement du robot
   /// \return             Retourne vrai si la direction est valide, faux sinon
   bool directionValide(const Robot& robot, Coordonnee::Direction direction,
                        unsigned distance = 1) const;

   /// Nom                 directionUtilisable
   /// But                 Obtenir une direction utilisable par le robot
   /// \param robot        Robot dont une direction utilisable doit être détérminée
   /// \param distance     Distance de déplacement du robot
   /// \return             Direction utilisable
   Coordonnee::Direction directionUtilisable (const Robot& robot,
                                              unsigned distance = 1) const;

   /// Nom                 affichageJeu
   /// But                 Afficher le jeu
   void affichageJeu() const;

};


#endif //LABO8_ROBOT_JEU_H
