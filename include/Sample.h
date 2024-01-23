#pragma once
/*---------------------------------------------------------------------------
*
* Cr�ation Lucas.G
*
*L�objet Sample est pr�vu pour stocker le tag et un vecteur de crat�ristiques,
c'est deux �l�ments d�crive l'�chantillon qui correspond � une ligne dans le 
codument txt. Cette object propose des m�thodes pour l�exploiter. On y retrouves 
les m�thodes suivantes :

 - tag qui permet d'attribuer un tag � la ligne (chiffre quelle represente) si
 le chiffre est inconnu le tag=-1;

 - features qui permet d'ajouter une cract�ristique au FeatureVector

 -getTag qui permet de renvoyer le tag correspondant � l'�chantillon

 -displaySample qui permet d'afficher le contenu de l'�chantillon
*
*----------------------------------------------------------------------------*/
#include "FeatureVector.h"

class Sample {
	int _tag;
	FeatureVector _features;

public:
	/*------------Constructeur---------------*/
	Sample();

    /*------------Definittion des methodes---------------*/
	void tag(int t);
	const FeatureVector& getFeatures() const; //getter qui retourne le Feature vector associé, je pense que c'est l'équivalent de la surcharge crochet de sample
    void displaySample()const;
    int getTag()const;
	void features(float f);
};

inline int Sample::getTag() const {
    return _tag;
}

inline const FeatureVector& Sample::getFeatures() const {
    return _features;
}
