/*
-----------------------------------------------------------------------------------
Nom du fichier : annexe.h
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Fichier annexe contenant des fonctions réutilisables dans divers
                 contexte comme de l'aléatoire ou une fonctions de saisie.

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

/// Nom                     aleatoire
/// But                     Générer un nombre aléatoire
/// \param min              Valeur min du nombre aléatoire
/// \param max              Valeur max non comprise du nombre aléatoire
/// \return                 Valeur générée aléatoirement
int aleatoire(int min, int max);

/// Nom                     Saisie
/// But                     Permet de récupérer une saisie d'utilisateur contrôlée
///                         entre une valeur min et max comprises.
/// \tparam T               Type utilisé
/// \param min              Valeur minimale comprise
/// \param max              Valeur maximale comprise
/// \param messageSaisie    Message à afficher lors de la saisie
/// \param messageErreur    Message à afficher lors d'une erreur de saisie
/// \return                 Retourne la valeur saisie de l'utilisateur de type T
template <typename T>
T  saisir(T min, T max, const std::string& messageSaisie,const std::string& messageErreur);

#include "annexe_def.h"

#endif //LABO6_ANNEXE_H