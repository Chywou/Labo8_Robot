/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Nom du labo :
Auteur(s) : tim ernst
Date creation : <jj.mm.aaaa>
Description :
Remarque(s) :
Compilateur : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>
#include "Jeu.h"
#include "annexe.h"
using namespace std;
int main() {
   const unsigned MAX_HAUTEUR = 1000;
   const unsigned MAX_LARGEUR = 1000;
   const unsigned MAX_ROBOT   = 9;

   unsigned hauteur = saisir<unsigned>(0,
                                       MAX_HAUTEUR,
                                       "Saisir la hauteur :",
                                       "Recommencer la saisie");
   unsigned largeur = saisir<unsigned>(0,
                                       MAX_LARGEUR,
                                       "Saisir la largeur :",
                                       "Recommencer la saisie");
   unsigned nbreRobot = saisir<unsigned>(1,
                                       MAX_ROBOT,
                                       "Saisir le nombre de robot:",
                                       "Recommencer la saisie");


   Jeu j(hauteur,largeur,nbreRobot);
   j.demmarer();


//   Jeu u(hauteur,largeur,nbreRobot);
//   u.demmarer();

   pause();
   return EXIT_SUCCESS;
}