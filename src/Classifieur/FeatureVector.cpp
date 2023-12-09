#include "FeatureVector.h"

/*R�flechir � l'utilister d'une class vector par rapport � la STL*/
/*Penser � la construction et le n�cessiter des constructeur par d�faut et d�structeur*/

/*Besoin d'un constructeur qui prend en entr�e "_features" (carat�ristiques) , je pense que c'est les donn�es
a mettre dans le vecteur !! est ce que c'est pas une copie en trop*/

float FeatureVector::norme()const {

	float result=0;

	for (const float& element : _vector)
	{
		result += pow(element, 2);
	}

	return sqrt(result);

}

