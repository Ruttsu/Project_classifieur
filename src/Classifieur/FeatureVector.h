#pragma once

/*---------------------------------------------------------------------------
*
* Cr�ation Lucas.G
* 
*L�objet est pr�vu pour stocker un vecteur de caract�ristique et proposer des
m�thodes pour l�exploiter. On y retrouves les m�thodes suivantes:
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
	int size()const; //m�thode qui peut �tre mise in line je suppose

};

/*---------------------------------------------------------------------------*/
inline int FeatureVector::size()const {
	return _vector.size();
}