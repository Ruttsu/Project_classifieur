#pragma once
/*---------------------------------------------------------------------------
*
* Création Lucas.G
*
*L’objet Sample est prévu pour stocker le tag et un vecteur de cratéristiques,
c'est deux éléments décrive l'échantillon qui correspond à une ligne dans le 
codument txt. Cette object propose des méthodes pour l’exploiter. On y retrouves 
les méthodes suivantes :

 - tag qui permet d'attribuer un tag à la ligne (chiffre quelle represente) si
 le chiffre est inconnu le tag=-1;

 - features qui permet d'ajouter une cractéristique au FeatureVector

 -getTag qui permet de renvoyer le tag correspondant à l'échantillon

 -displaySample qui permet d'afficher le contenu de l'échantillon
*
*----------------------------------------------------------------------------*/
#include "FeatureVector.h"

class Sample{

	int _tag;
	FeatureVector _features;

public:

    /*------------Définittion des méthodes---------------*/
	void tag(int t);
	void features(float f);
    void displaySample()const;

    int getTag()const;

};

inline int Sample::getTag()const{
    return _tag;
}