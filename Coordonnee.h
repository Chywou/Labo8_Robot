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

class Coordonnee {
public:
   enum class Direction {HAUT, BAS, GAUCHE, DROITE};

   /// Nom                 Coordonnee
   /// But                 Constructeur à paramètres de la classe Coordonnee
   /// \param x            Coordonnee x
   /// \param y            Coordonnee y
   Coordonnee(unsigned x, unsigned y);

   /// Nom                 operator==
   /// But                 Détérminer si deux Coordonnee sont égales
   /// \param coor         Coordonnee à comparer
   /// \return             Retourne vrai si les deux coordonne sont égales, sinon faux
   bool operator==(const Coordonnee& coordonnee) const;

   /// Nom                 deplacement
   /// But                 Deplacer les coordonnée dans une direction et une distance choisie
   /// \param direction    Direction du déplacement
   /// \param distance     Nombre d'unité dont le robot se déplace
   void deplacement(Direction direction, unsigned distance = 1);

   /// Nom                 getX
   /// But                 Retourner la position x
   /// \return             retourne x
   unsigned getX() const;

   /// Nom                 Y
   /// But                 Retourner la position y
   /// \return             retourne y
   unsigned getY() const;

   /// Nom                 getNbrDirection
   /// But                 retourner le nombre de direction possible pour une coordonnée
   /// \return             retourne NBRE_DIRECTION
   static unsigned getNbrDirection();

private:
   unsigned x;
   unsigned y;

   static const unsigned NBRE_DIRECTION;  // Nombre de directions que le robot peut se deplacer
};


#endif //LABO8_ROBOT_COORDONNEE_H
