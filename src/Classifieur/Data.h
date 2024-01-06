#pragma once
/*---------------------------------------------------------------------------
*
* Création Lucas.G
*
*L’objet Data est prévu pour stocker un vecteur de d'échantillon ainsi que le
le nombre de caratéristique par échantillon, et le nombre d'échantillon enregistrer
L'objet propose des méthodes pour l’exploiter. On y retrouves les méthodes
suivantes:

- un constructeur a qui on donne le chemin depuis la racine du document txt a
scanner.->il va falloir l'améliorer pour dire si les échantiollon son connu ou
inconnu.

 - 
*
*----------------------------------------------------------------------------*/

#include "FeatureVector.h"
#include "Sample.h"
#include <vector>
#include <string>

class Data {

	vector<Sample> _data;
	int _nb_features;
	int _nb_sample;

public:

	Data(string path);
};