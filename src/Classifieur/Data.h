#pragma once
/*---------------------------------------------------------------------------
*
* Cr�ation Lucas.G
*
*L�objet Data est pr�vu pour stocker un vecteur de d'�chantillon ainsi que le
le nombre de carat�ristique par �chantillon, et le nombre d'�chantillon enregistrer
L'objet propose des m�thodes pour l�exploiter. On y retrouves les m�thodes
suivantes:

- un constructeur a qui on donne le chemin depuis la racine du document txt a
scanner. En deuxième paramètre il faut lui passer une valeur booléenne 1 si
c'est des données d'appprentissage et 0 si c'est des données a définir.

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

	Data(string path, bool donneeApprentissage);
};