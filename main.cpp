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
#include <string>
#include "Jeu.h"
#include "annexe.h"
using namespace std;
int main() {
   const string   MSG_ERREUR      = "Recommencer la saisie";
   const string   MSG_HAUTEUR     = "Saisir la hauteur ";
   const string   MSG_LARGEUR     = "Saisir la largeur ";
   const string   NBR_ROBOT       = "Saisir le nombre de robot ";

   const unsigned MIN_HAUTEUR = 10;
   const unsigned MIN_LARGEUR = 10;
   const unsigned MAX_HAUTEUR = 1000;
   const unsigned MAX_LARGEUR = 1000;
   const unsigned MIN_ROBOT   = 1;
   const unsigned MAX_ROBOT   = 9;

   unsigned hauteur = saisir<unsigned>(MIN_HAUTEUR, MAX_HAUTEUR,
                                       MSG_HAUTEUR, MSG_ERREUR);
   unsigned largeur = saisir<unsigned>(MIN_LARGEUR, MAX_LARGEUR,
                                       MSG_LARGEUR, MSG_ERREUR);
   unsigned nbreRobot = saisir<unsigned>(MIN_ROBOT, MAX_ROBOT,
                                         NBR_ROBOT, MSG_ERREUR);


   Jeu j(hauteur,largeur,nbreRobot);
   j.demmarer();


   pause();
   return EXIT_SUCCESS;
}