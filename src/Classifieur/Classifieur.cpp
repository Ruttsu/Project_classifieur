// Classifieur.cpp : définit le point d'entrée de l'application.

#include "Classifieur.h"
#include "Data.h"
#include "FeatureVector.h"
#include "KnnEuclidien.h"
#include "KnnManhattan.h"
#include "Knncosine.h"

using namespace std;

int main() {

	int ind = 1;
    Data file("../../doc/Digits/Digits/digits.svm", 1);
    // file.displayData();
    cout << "Fini de l'import" << endl << endl;

	file[ind].displaySample();
	cout << endl;

	Sample test(-1, {0.793836,0.264603,0.10347,0.12025,0.457457,0.130727,0.247971,0.163846,0.416592,0.0105225,0.197518,0.120068,0.649331,0.0546827,0.0542517,0.0481252,0.137483,0.111458,0.15022,0.131084,0.182864,0.129831,0.0894998,0.0827041,0.051342,0.422515,0,0.000284315,0.029238,0.0881091,0,0.00480701,0.276144,0.0405575,0.254078,0.490479,0.53111,0.171567,0.413972,0.268241,0.200363,0.161456,0.370557,0.123517,0.224544,0.0532561,0.247592,0.582612,0.31274,0.0197861,0.641833,0.426604,0.363537,0.340048,0.578312,0.191365,0.0989377,0.0580434,0.214284,0.17585,0.0381746,0.312853,0,0.00109727,0.119835,0.395257,0,0.00770754,0.446204,0.0789867});
	test.displaySample();
	test.displayFeatureVector();
	cout << "Data Size : " << file[ind].getSize();
	cout << "Size : " << test.getSize();

	KnnEuclidien A;
	KnnManhattan B;
	KnnCosine C;
	cout << endl << "Distance Data & Test : " << A.similarity(test,file[ind]) << endl;
	cout << "Distance Data & Test : " << B.similarity(test,file[ind]) << endl;
	cout << "Distance Data & Test : " << C.similarity(test,file[ind]) << endl;

/*
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
	return 0;
}
