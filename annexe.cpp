/*
-----------------------------------------------------------------------------------
Nom du fichier : annexe.cpp
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Définition des fonctions du fichier annexe.h

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <iostream>  // cout
#include <limits>    // numeric_limits
#include <ctime>     // time
#include <cstdlib>   // srand, rand

#include "annexe.h"

using namespace std;

void viderBuffer() {
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pause (const string& message) {
   cout << endl;
   cout << message << endl;
   viderBuffer();
}

int aleatoire(int min, int max) {
   static bool init = true;
   if(init) {
      srand((unsigned)time(nullptr));
      init = false;
   }
   return (rand()%(max-min))+min;
}