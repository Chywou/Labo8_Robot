/*
-----------------------------------------------------------------------------------
Nom du fichier : annexe.h
Nom du labo    : Labo06 Crible
Auteur(s)      : Tim Ernst
Date creation  : 19.11.2021
Description    : Ce programme permet de regrouper des fonctionnalités varier utile dans
               : la majorité des programmes
Remarque(s)    :
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO6_ANNEXE_H
#define LABO6_ANNEXE_H

#include <string>    // permet d'utiliser les string


/**----------------------------------------
* vider le buffer du CIN
----------------------------------------*/
void viderBuffer();

/**----------------------------------------
* pause permet de mettre en pause le programme et attend que
* l'utiliteur entre une valleur
* @param message    message d'information pour l'utilisateur
----------------------------------------*/
void pause(const std::string& message = "Veillez presser ENTRER pour quitter");

/**----------------------------------------
* saisir attend la saisi de l'utiliseur et controle si la
* valeur est entre les bornes min et max comprise
* @param   min              comprise dans l'interval autorisé
* @param   max              comprise dans l'interval autorisé
* @param   messageSaisie    message de saisi pour l'utilisateur
* @param   messageErreur    message d'erreur pour l'utilisateur
* @return  retourn la valeur saisi par l'utilisateur
----------------------------------------*/
template <typename T>
T  saisir(T min, T max, const std::string& messageSaisie,const std::string& messageErreur);


#include "annexe_def.h"

#endif //LABO6_ANNEXE_H