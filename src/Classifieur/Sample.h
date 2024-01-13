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

class Sample: public FeatureVector {

	int _tag;
	FeatureVector _features;

public:

    /*------------D�finittion des m�thodes---------------*/
	Sample();
	void tag(int t);
	void features(float f);
    void displaySample()const;

    int getTag()const;

};

inline int Sample::getTag()const{
    return _tag;
}