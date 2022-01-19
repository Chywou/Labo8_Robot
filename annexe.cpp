/*
-----------------------------------------------------------------------------------
Nom du fichier : annexe.cpp
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Définition de la classe Coordonnee

Remarque(s)    :


Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include "annexe.h"

using namespace std;

void viderBuffer(){
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pause (const string& message){
   cout << endl;
   cout << message << endl;
   viderBuffer();
}


unsigned  aleatoire(unsigned min, unsigned max){
   static bool init = true;
   if(init){
      srand(time(NULL));
      init = false;
   }
   return (rand()%(max-min))+min;
}