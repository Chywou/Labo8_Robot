/*
-----------------------------------------------------------------------------------
Nom du fichier : annexe_def.h
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    :

Remarque(s)    :


Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <iostream>  // cin, cout
#include <limits>    // numeric_limits

using namespace std;


void viderBuffer(){
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pause (const string& message){
   cout << message << endl;
   viderBuffer();
}

template <typename T>
T saisir(T min, T max, const string& messageSaisie, const string& messageErreur){
   T  saisie;
   bool erreur;

   do {
      // message et saisie
      cout << messageSaisie << "[" << min << " : " << max << "] :";
      cin >> saisie;

      // vérification
      erreur = cin.fail() or saisie < min or saisie > max;
      if (erreur) {
         if(!messageErreur.empty()){
            cout << messageErreur << endl;
         }
         cin.clear();
      }

      viderBuffer();

   } while(erreur);

   return saisie;
}