#include "FeatureVector.h"

/*Réflechir à l'utilister d'une class vector par rapport à la STL*/
/*Penser à la construction et le nécessiter des constructeur par défaut et déstructeur*/

/*Besoin d'un constructeur qui prend en entrée "_features" (caratéristiques) , je pense que c'est les données
a mettre dans le vecteur !! est ce que c'est pas une copie en trop*/

float FeatureVector::norme()const {

	float result=0;

	for (const float& element : _vector)
	{
		result += pow(element, 2);
	}

	return sqrt(result);

}

