// Classifieur.cpp : définit le point d'entrée de l'application.

#include "Classifieur.h"
#include "Data.h"
#include "FeatureVector.h"
#include "KnnEuclidien.h"
#include "KnnManhattan.h"
#include "Knncosine.h"
#include "ClassificationReport.h"

using namespace std;

int main() {
/*
    Data file("D:/Cours/INSA/Cpp/ProjetClassifieur/doc/Digits/Digits/digits.svm", 1);
    file.displayData();
    cout << "Fini de l'import" << endl << endl;


	Sample test, data1, data2;
	KnnEuclidien A;
	KnnManhattan B;
	KnnCosine C;

	data1.addFeatures(200);	// avec 200 = resultat sympa !
	data1.addFeatures(19);
	data1.addFeatures(18);
	data1.addFeatures(17);

	data2.addFeatures(150);
	data2.addFeatures(-15);
	data2.addFeatures(18);
	data2.addFeatures(1);

	test.addFeatures(21);
	test.addFeatures(20);
	test.addFeatures(19);
	test.addFeatures(18);

	cout << "Data1 : ";
	data1.displayFeatureVector();
	cout << "Data2 : ";
	data2.displayFeatureVector();
	cout << "Test : ";
	test.displayFeatureVector();
	cout << endl;

	cout << "Méthode Euclidienne : " << endl;
	cout << "Distance Data1 & Test : " << A.similarity(test,data1) << endl;
	cout << "Distance Data2 & Test : " << A.similarity(test,data2) << endl;

	string DataEuclidien = (A.similarity(test,data1) < A.similarity(test,data2))? "Data1":"Data2";
	cout << DataEuclidien << " est le plus proche voisin de Test !" << endl << endl;


	cout << "Méthode Manhattan : " << endl;
	cout << "Distance Data1 & Test : " << B.similarity(test,data1) << endl;
	cout << "Distance Data2 & Test : " << B.similarity(test,data2) << endl;

	string DataManhatan = (B.similarity(test,data1) < B.similarity(test,data2))? "Data1":"Data2";
	cout << DataManhatan << " est le plus proche voisin de Test !" << endl << endl;


	cout << "Méthode Cosine : " << endl;
	cout << "Distance Data1 & Test : " << C.similarity(test,data1) << endl;
	cout << "Distance Data2 & Test : " << C.similarity(test,data2) << endl;

	string DataCosine = (C.similarity(test,data1) > C.similarity(test,data2))? "Data1":"Data2";
	cout << DataCosine << " est le plus proche voisin de Test !" << endl;
*/

ClassificationReport test;

test.displayTabConfusion();

    test.setTabConfusion(1,1);
    test.setTabConfusion(1,1);
    test.setTabConfusion(1,1);
    test.setTabConfusion(1,1);
    test.setTabConfusion(1,1);
    test.setTabConfusion(1,1);
    test.setTabConfusion(1,1);
    test.setTabConfusion(1,1);
    test.setTabConfusion(1,1);
    test.setTabConfusion(1,1);
    test.setTabConfusion(1,1);
    test.setTabConfusion(1,1);

test.displayTabConfusion();

	return 0;
}
