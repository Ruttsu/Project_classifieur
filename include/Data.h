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

 - getNbFeatures qui retourne le nombre de caratéristique par ligne dans le fichier

 - getNbSample qui retourne le nombre de ligne dans le fichier / le nombre de chiffre
 représenté

 -displayData qui permet d'afficher le contenu de data
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
	Data();
    /*-------Définittion des constructeurs et destructeur------*/
	Data(string path, bool donneeApprentissage);

    /*------------Définittion des méthodes---------------*/
    int getNbFeatures()const;
    int getNbSample()const;
    void displayData()const;
    //const std::vector<float>& aspirelesdonnees() const;

    /*------------Définittion des opérateurs-------------*/
    Sample operator[](unsigned int index)const; //unsigned car la fonction size de la stl renvoie un unsigned
};
/*---------------------------------------------------------------------------*/
inline int Data::getNbFeatures()const {
    return _nb_features;
}

inline int Data::getNbSample()const{
    return _nb_sample;
}