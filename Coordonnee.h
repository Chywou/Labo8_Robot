/*
-----------------------------------------------------------------------------------
Nom du fichier : Coordonnee.h
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Déclaration de la classe Coordonnee. Elle permet la gestion des
                 coordonnées des objets de la classe Robot.

Remarque(s)    :


Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO8_ROBOT_COORDONNEE_H
#define LABO8_ROBOT_COORDONNEE_H

#include <ostream>
class Robot;
class Jeu;

class Coordonnee {
   friend class Jeu;
   friend class Robot;

   friend std::ostream& operator<< ( std::ostream& os, const Jeu& jeu);
public:

   /// Nom             Coordonnee
   /// But             Constructeur à paramètres de la classe Coordonnee
   /// \param x        Coordonnee x
   /// \param y        Coordonnee y
   Coordonnee(unsigned x, unsigned y);

   /// Nom             operator==
   /// But             Détérminer si deux Coordonnee sont égales
   /// \param coor     Coordonnee à comparer
   /// \return         Retourne vrai si les deux coordonne sont égales, sinon faux
   bool operator==(const Coordonnee& coor) const;

   /// Nom             generer
   /// But             Generer un objet Coordonne
   /// \param min      Valeur minmale
   /// \param maxX     Valeur maximale pour x
   /// \param maxY     Valeur maximale pour y
   /// \return         Retourne un objet Coordonne
   static Coordonnee generer(unsigned min, unsigned maxX, unsigned maxY);

private:
   unsigned x;
   unsigned y;
};


#endif //LABO8_ROBOT_COORDONNEE_H
