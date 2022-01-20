/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Ce programme permet de simuler des robots autonomes dans un espace
                 donné. L'utilisateur doit saisire les dimension de l'espace ainsi
                 que le nombre de robots [1 - 9].

Remarque(s)    : Les saisies utilisateurs sont gérées.

Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>         // EXIT_SUCCESS
#include <string>          // Utilisation de string
#include "Jeu.h"           // Utilisation de la class jeu
#include "annexe.h"        // saisir

using namespace std;

int main() {

   // Constantes
   const string   MSG_ERREUR  = "Recommencer la saisie";
   const string   MSG_HAUTEUR = "Saisir la hauteur ";
   const string   MSG_LARGEUR = "Saisir la largeur ";
   const string   NBR_ROBOT   = "Saisir le nombre de robot ";

   const unsigned MIN_HAUTEUR = 10;
   const unsigned MIN_LARGEUR = 10;
   const unsigned MAX_HAUTEUR = 1000;
   const unsigned MAX_LARGEUR = 1000;
   const unsigned MIN_ROBOT   = 1;
   const unsigned MAX_ROBOT   = 9;

   // Présentation du programme
   cout << "Ce programme permet de simuler des robots autonomes se déplacant"
           "aléatoirement." << endl;

   // Saisie utilisateur
   unsigned hauteur = saisir<unsigned>(MIN_HAUTEUR, MAX_HAUTEUR,
                                       MSG_HAUTEUR, MSG_ERREUR);
   unsigned largeur = saisir<unsigned>(MIN_LARGEUR, MAX_LARGEUR,
                                       MSG_LARGEUR, MSG_ERREUR);
   unsigned nbreRobot = saisir<unsigned>(MIN_ROBOT, MAX_ROBOT,
                                         NBR_ROBOT, MSG_ERREUR);

   // Déroulement du jeu
   Jeu j(hauteur,largeur,nbreRobot);
   j.lancementJeu();


   // Fin du programme
   pause();
   return EXIT_SUCCESS;
}