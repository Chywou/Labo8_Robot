/*
-----------------------------------------------------------------------------------
Nom du fichier : annexe_def.h
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Définition de la fonction générique de annexe.h

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <iostream>  // cin, cout

template <typename T>
T saisir(T min, T max, const std::string& messageSaisie, const std::string& messageErreur){
   T  saisie;
   bool erreur;

   do {
      // Message et saisie
      std::cout << messageSaisie << "[" << min << " : " << max << "] :";
      std::cin >> saisie;

      // Vérification
      erreur = std::cin.fail() || saisie < min || saisie > max;
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
