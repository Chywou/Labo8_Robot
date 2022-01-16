/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Ce programme permet de ...

Remarque(s)    :


Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include "Jeu.h"
#include "annexe.h"
using namespace std;
int main() {
   const unsigned MAX_HAUTEUR = 1000;
   const unsigned MAX_LARGEUR = 1000;
   const unsigned MAX_ROBOT   = 9;

   unsigned hauteur = saisir<unsigned>(10,
                                       MAX_HAUTEUR,
                                       "Saisir la hauteur ",
                                       "Recommencer la saisie");
   unsigned largeur = saisir<unsigned>(10,
                                       MAX_LARGEUR,
                                       "Saisir la largeur ",
                                       "Recommencer la saisie");
   unsigned nbreRobot = saisir<unsigned>(1,
                                       MAX_ROBOT,
                                       "Saisir le nombre de robot ",
                                       "Recommencer la saisie");


   Jeu j(hauteur,largeur,nbreRobot);
   j.demmarer();


//   Jeu u(hauteur,largeur,nbreRobot);
//   u.demmarer();

   pause();
   return EXIT_SUCCESS;
}