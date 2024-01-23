#pragma once

/*---------------------------------------------------------------------------
*
* Cr�ation Lucas.G
* 
*L�objet FeatureVector est pr�vu pour stocker un vecteur de caract�ristique ainsi 
que �a norme et proposer des m�thodes pour l�exploiter. On y retrouves les m�thodes 
suivantes:

 - norme qui calcul la norme du vecteur

 - getSize qui retourne la taille du vecteur (m�thode inline)

 - getNorme est une m�thode inline pour obtenir la norme

 - l'op�rateur * a �t� surcharger, il multiplie deux vecteurs case � case si et seulement si
 il ont la m�me taille -> � r�fl�chire si c'est le comportement souhait�

 - l'op�rateur [] a �t� surcharger, il permet d'acceder � la case du vecteur choisi

 - addFeatures qui permet d'ajouter des carat�ristiques au vecteur. Cette m�thode est utile
 en attendant la d�finition du constructeur de la class. Elle recalcule la norme du vecteur
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
public:
	float _norme;
	vector <float> _vector;

//public:

	/*------------D�finittion des m�thodes---------------*/

	float norme()const;
	int getSize()const; //m�thode qui peut �tre mise in line
	float getNorme()const;
	const std::vector<float>& getVector() const;

	/*------------D�finittion des op�rateurs-------------*/

	float operator[](unsigned int index)const; //fonction size de la stl renvoie un unsigned int
	FeatureVector operator*(FeatureVector& right)const;

	/*-----------M�thode non demand� utile pour tester et cr�er la class------------------*/

	void addFeatures(float a); //M�thode non demand� utile pour tester et cr�er la class et sans doute peut �tre mise in line
	void displayFeatureVector()const;

};

/*---------------------------------------------------------------------------*/
inline int FeatureVector::getSize()const {
	return _vector.size();
}

inline float FeatureVector::getNorme()const {
	return _norme;
}

inline const std::vector<float>& FeatureVector::getVector() const {
    return _vector;
}