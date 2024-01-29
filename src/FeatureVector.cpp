#include "../include/FeatureVector.h"

/*Penser � la construction et le n�cessiter des constructeur par d�faut et d�structeur*/

/*Besoin d'un constructeur qui prend en entr�e "_features" (carat�ristiques) , je pense que c'est les donn�es
a mettre dans le vecteur !! est ce que c'est pas une copie en trop*/

FeatureVector::FeatureVector() {}

FeatureVector::FeatureVector(initializer_list<float> args) {
	for (float a:args) {
		_vector.push_back(a);
	}
	_norme = norme();
}


/*------------D�finittion des m�thodes---------------*/

float FeatureVector::norme()const {

	float result=0;

	for (const float element : _vector)
	{
		result += pow(element, 2);
	}

	return sqrt(result);

}

/*------------D�finittion des op�rateurs-------------*/

float FeatureVector::operator[](unsigned int index)const {

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
		//return erreur les deux vecteurs ne sont pas de la m�me taille
	}

	result._norme = result.norme();//!!!!!! sans doute a changer mis la pour que �a compile

	return result;

}


/*-----------M�thode non demand� utile pour tester et cr�er la class------------------*/

void FeatureVector::addFeatures(float a) {
	_vector.push_back(a);
	_norme = norme();
}

void FeatureVector::displayFeatureVector()const {

	cout << "La norme est : " << _norme << endl;
	cout << "Le vecteur est : ";

	for (const float& element : _vector)
	{
		cout << element << " ";
	}
	cout << endl;
}
