#pragma once

/*---------------------------------------------------------------------------
*
* Cr�ation Lucas.G
* 
*L�objet FeatureVector est pr�vu pour stocker un vecteur de caract�ristique ainsi 
que �a norme et proposer des m�thodes pour l�exploiter. On y retrouves les m�thodes 
suivantes:

 - norme qui calcul la norme du vecteur -> �volution peut �tre plut�t retourne la norme
 qui est pr�sente dans l'objet cette derni�re serait calculer lors de la construction
 de l'objet.

 - size qui retourne la taille du vecteur

 - l'op�rateur * a �t� surcharger, il multiplie deux vecteurs case � case si et seulement si
 il ont la m�me taille -> � r�fl�chire si c'est le comportement souhait�

 - l'op�rateur [] a �t� surcharger, il permet d'acceder � la case du vecteur choisi

 - addFeatures qui permet d'ajouter des carat�ristiques au vecteur. Cette m�thode est utile
 en attendant la d�finition du constructeur de la class

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

	/*------------D�finittion des m�thodes---------------*/

	float norme()const;
	int size()const; //m�thode qui peut �tre mise in line

	/*------------D�finittion des op�rateurs-------------*/

	float operator[](int index)const;
	FeatureVector operator*(FeatureVector& right)const;

	/*-----------M�thode non demand� utile pour tester et cr�er la class------------------*/

	void addFeatures(float a); //M�thode non demand� utile pour tester et cr�er la class et sans doute peut �tre mise in line
	void displayFeatureVector()const;

};

/*---------------------------------------------------------------------------*/
inline int FeatureVector::size()const {
	return _vector.size();
}