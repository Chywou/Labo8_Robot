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
#include <ctime>     // time
#include <cstdlib>   // srand, rand



template <typename T>
T saisir(T min, T max, const std::string& messageSaisie, const std::string& messageErreur){
   T  saisie;
   bool erreur;

   do {
      // message et saisie
      std::cout << messageSaisie << "[" << min << " : " << max << "] :";
      std::cin >> saisie;

      // vérification
      erreur = std::cin.fail() or saisie < min or saisie > max;
      if (erreur) {
         if(!messageErreur.empty()){
            std::cout << messageErreur << std::endl;
         }
         std::cin.clear();
      }

      viderBuffer();

   } while(erreur);

   return saisie;
}

template <typename T>
T  aleatoire(T min, T max){
   static bool init = true;
   if(init){
      srand(time(NULL));
      init = false;
   }
   return (rand()%(max-min))+min;
}