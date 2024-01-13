#include "FeatureVector.h"

/*Penser à la construction et le nécessiter des constructeur par défaut et déstructeur*/

/*Besoin d'un constructeur qui prend en entrée "_features" (caratéristiques) , je pense que c'est les données
a mettre dans le vecteur !! est ce que c'est pas une copie en trop*/

/*------------Définittion des méthodes---------------*/

float FeatureVector::norme()const {

	float result=0;

	for (const float& element : _vector)
	{
		result += pow(element, 2);
	}

	return sqrt(result);

}

/*------------Définittion des opérateurs-------------*/

float FeatureVector::operator[](int index)const {

    if (index < _vector.size())
    {
        return _vector[index];
    }
    else
    {
        throw out_of_range("Index is too big for operator [] of class FeatureVector");
    }

}

FeatureVector FeatureVector::operator*(FeatureVector& right)const {

	FeatureVector result;

	if (getSize() == right.getSize())
	{
		for (int i = 0; i<getSize(); i++)
		{
			result._vector.push_back(_vector[i] * right[i]);
		}
	}
	else
	{
		//return erreur les deux vecteurs ne sont pas de la même taille
	}

	result._norme = result.norme();//!!!!!! sans doute a changer mis la pour que ça compile

	return result;

}


/*-----------Méthode non demandé utile pour tester et créer la class------------------*/

void FeatureVector::addFeatures(float a) {
	_vector.push_back(a);
	_norme = norme();
}

void FeatureVector::displayFeatureVector()const {

	cout << "La norme est : " << _norme << "\n" << endl;

	for (const float& element : _vector)
	{
		cout << element << "\n" << endl;
	}

}
