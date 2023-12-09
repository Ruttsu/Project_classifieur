#pragma once

/*---------------------------------------------------------------------------
*
* Création Lucas.G
* 
*L’objet est prévu pour stocker un vecteur de caractéristique et proposer des
méthodes pour l’exploiter. On y retrouves les méthodes suivantes:
 -
 -
 -
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

	float norme()const;
	int size()const; //méthode qui peut être mise in line je suppose

};

/*---------------------------------------------------------------------------*/
inline int FeatureVector::size()const {
	return _vector.size();
}