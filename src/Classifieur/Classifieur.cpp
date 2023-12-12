// Classifieur.cpp : définit le point d'entrée de l'application.
//

#include "Classifieur.h"
#include "FeatureVector.h"

using namespace std;

int main()
{
	FeatureVector test, test1, test2;

	test1.addFeatures(2);
	test1.addFeatures(3);

	test2.addFeatures(2);
	test2.addFeatures(3);

	test = test1 * test2; // l'operateur * n'existe pas pour les vector de base

	test.displayFeatureVector();

	//cout << test1[1] << endl;


	return 0;
}
