/*
-----------------------------------------------------------------------------------
Nom du fichier : annexe.h
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    :

Remarque(s)    :


Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO6_ANNEXE_H
#define LABO6_ANNEXE_H

#include <string>    // Utilisation de string



/// Nom             viderBuffer
/// But             Permet de vider le buffer cin
void viderBuffer();

/// Nom             pause
/// But             Permet de mettre en pause le programme
/// \param message
void pause(const std::string& message = "Veillez presser ENTRER pour quitter");

/// Nom                     Saisie
/// But                     Permet de récupérer une saisie d'utilisateur contrôlée
///                         entre une valeur min et max comprises.
/// \tparam T
/// \param min              Valeur minimale comprise
/// \param max              Valeur maximale comprise
/// \param messageSaisie    Message à afficher lors de la saisie
/// \param messageErreur    Message à afficher lors d'une erreur de saisie
/// \return                 Retourne la valeur saisie de l'utilisateur de type T
template <typename T>
T  saisir(T min, T max, const std::string& messageSaisie,const std::string& messageErreur);

/// Nom                     aleatoire
/// But                     Générer un nombre aléatoire
/// \param min              Valeur min du nombre aléatoire
/// \param max              Valeur max non comprise du nombre aléatoire
/// \return                 Valeur générée aléatoirement
unsigned aleatoire(unsigned min, unsigned max);


#include "annexe_def.h"

#endif //LABO6_ANNEXE_H