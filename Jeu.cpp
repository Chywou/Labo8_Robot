/*
-----------------------------------------------------------------------------------
Nom du fichier : Jeu.cpp
Nom du labo    : Labo 08 : Survivor
Auteur(s)      : Laetitia Guidetti et Tim Ernst
Date creation  : 14.01.2022
Description    : Définition de la classe Jeu.

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <iostream>  // cout
#include <thread>    // sleep_for
#include <cassert>   // assert
#include "annexe.h"  // aleatoire
#include "Jeu.h"

using namespace std;

ostream& operator<< ( std::ostream& os, const Jeu& jeu) {

   // Création d'un string correspondant au terrain de jeu vide
   string plateau;
   string ligne;
   plateau.append(jeu.largeur+2, '-');
   plateau.append(1,'\n');
   ligne.append(1,'|');
   ligne.append(jeu.largeur,' ');
   ligne.append(1,'|');
   ligne.append(1,'\n');

   for (unsigned i = 0; i < jeu.hauteur; ++i) {
      plateau.append(ligne);
   }
   plateau.append(jeu.largeur+2, '-');

   // Ajoute les robots au string aux bonnes coordonnées
   for(const Robot& r: jeu.robots) {
      plateau[(r.getCoordonnee().getY()+1) *
              (jeu.largeur+3)+r.getCoordonnee().getX()+1] =  char(r.getId() + '0');
   }

   return os << plateau;
}

Jeu::Jeu(unsigned hauteur, unsigned largeur, unsigned nbreRobot) :
         hauteur(hauteur), largeur(largeur) {

   // Vérifie que le programme contient suffisamment de place pour placer tous les robots
   assert((largeur)*(hauteur) >= nbreRobot);

   robots.reserve(nbreRobot);

   // Crée et ajoute au vecteur robots le nombre de robots indiqué par nbrRobot
   for(unsigned i = 1; i <= nbreRobot; ++i) {
      bool coordonneeUnique = true;
      do {
         Coordonnee coordonnee = Coordonnee((unsigned)aleatoire(0,(int)largeur),
                                            (unsigned)aleatoire(0,(int)hauteur));

         // Vérifie que les coordonnées ne sont pas déjà occupées par un autre robot
         if(!coordonneeUtilise(coordonnee)) {
            robots.emplace_back(coordonnee, i);
            coordonneeUnique = false;
         }
      } while (coordonneeUnique);
   }
}

void Jeu::lancementJeu() {

   // Appelle de ostream& operator<< ( std::ostream& os, const Jeu& jeu)
   cout<< *this << endl;

   do {
      for (vector<Robot>::iterator robot = robots.begin(); robot < robots.end(); ++robot) {
         // Déplacement du robot dans une direction aléatoire
         robot->deplacement(directionUtilisable(*robot));

         for (vector<Robot>::iterator it = robots.begin(); it < robots.end(); ++it) {
            // Vérifie si le robot en se déplacant a mangé un autre robot ou non
            if(robot->memeEmplacement(*it)){
               rapport.push_back(to_string(robot->getId()) +
                                 " a tue " + to_string(it->getId()));
               robots.erase(it);

               if(distance(it, robot) > 0) {
                  // Permet d'éviter que le tour d'un robot soit sauté dans le cas où
                  // le robot mangueur est situé après le robot mangé
                  --robot;
               }
               break; // Il n'est pas possible de manger plus d'un robot par déplacement
            }
         }
      }

      // Clear la console, ATTENTION valable uniquement pour Windows
      system("cls");

      affichageJeu();

      this_thread::sleep_for(200ms);
   } while (robots.size() > 1);

   cout << robots[0].getId() << " a gagne !" << endl;
}

bool Jeu::coordonneeUtilise(const Coordonnee& coordonnee) const {
   for(const Robot& r: robots) {
      if(r.memeEmplacement(coordonnee)) {
         return true;
      }
   }
   return false;
}

bool Jeu::directionValide(const Robot& robot, Coordonnee::Direction direction,
                          unsigned distance) const {
   switch (direction) {
      case Coordonnee::Direction::HAUT:
         if(robot.getCoordonnee().getY() < distance) return false;
         break;
      case Coordonnee::Direction::BAS:
         if(robot.getCoordonnee().getY() + distance > hauteur - 1) return false;
         break;
      case Coordonnee::Direction::GAUCHE:
         if(robot.getCoordonnee().getX() < distance) return false;
         break;
      case Coordonnee::Direction::DROITE:
         if(robot.getCoordonnee().getX() + distance > largeur - 1) return false;
         break;
   }
   return true;
}

Coordonnee::Direction Jeu::directionUtilisable(const Robot& robot,
                                               unsigned distance) const {
   Coordonnee::Direction direction;

   // S'execute tant qu'une direction utilisable n'a pas été trouvée
   do {
      direction = Coordonnee::Direction(aleatoire(0, (int)Coordonnee::getNbrDirection()));
   } while (!directionValide(robot, direction, distance));

   return direction;
}

void Jeu::affichageJeu() const {
   cout << *this << endl;
   for(const string& s : rapport) {
      cout << s << endl;
   }
}