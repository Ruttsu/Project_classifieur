#pragma once

/*---------------------------------------------------------------------------
*
* Création Lucas.G
* 
*L’objet FeatureVector est prévu pour stocker un vecteur de caractéristique ainsi 
que ça norme et proposer des méthodes pour l’exploiter. On y retrouves les méthodes 
suivantes:

 - norme qui calcul la norme du vecteur

 - getSize qui retourne la taille du vecteur (méthode inline)

 - getNorme est une méthode inline pour obtenir la norme

 - l'opérateur * a été surcharger, il multiplie deux vecteurs case à case si et seulement si
 il ont la même taille -> à réfléchire si c'est le comportement souhaité

 - l'opérateur [] a été surcharger, il permet d'acceder à la case du vecteur choisi

 - addFeatures qui permet d'ajouter des caratéristiques au vecteur. Cette méthode est utile
 en attendant la définition du constructeur de la class. Elle recalcule la norme du vecteur
 a chaque ajout.

 - displayFeatures qui permet d'afficher les informations contenu dans la class
*
*----------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class FeatureVector
{
	float _norme;
	vector <float> _vector;

public:

	/*------------Définittion des méthodes---------------*/

	float norme()const;
	int getSize()const; //méthode qui peut être mise in line
	float getNorme()const;

	/*------------Définittion des opérateurs-------------*/

	float operator[](int index)const;
	FeatureVector operator*(FeatureVector& right)const;

	/*-----------Méthode non demandé utile pour tester et créer la class------------------*/

	void addFeatures(float a); //Méthode non demandé utile pour tester et créer la class et sans doute peut être mise in line
	void displayFeatureVector()const;

};

/*---------------------------------------------------------------------------*/
inline int FeatureVector::getSize()const {
	return _vector.size();
}

inline float FeatureVector::getNorme()const {
	return _norme;
}