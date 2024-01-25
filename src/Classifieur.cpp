// Classifieur.cpp : définit le point d'entrée de l'application.

#include "../include/Classifieur.h"
#include "../include/Data.h"
#include "../include/FeatureVector.h"
#include "../include/KnnEuclidien.h"
#include "../include/KnnManhattan.h"
#include "../include/Knncosine.h"
#include "../include/ClassificationReport.h"
#include "../include/Application.h"

using namespace std;

int main() {

	// Charger les données d'apprentissage depuis le fichier (900 premiers)
	Data trainingData("../doc/Digits/trainingData.svm", true);
	cout << "Fin de l'import des données d'apprentissage." << endl;

	// Charger les données à prédir depuis le fichier (100 derniers)
	Data testingData("../doc/Digits/TestingData.svm", true);
	cout << "Fin de l'import des données à prédir." << endl;

	// Créer une instance de la classe KnnCosine avec les données d'apprentissage
	KnnCosine knnClassifier(trainingData);

	// fonction predictSingle pour obtenir les k plus proches voisins
	//vector<pair<float, size_t>> nearestNeighborsSort = knnClassifier.predict(testingData,15); // variable pour stocker les voisins
	knnClassifier.predict(testingData,15); // variable pour stocker les voisins

	// ChooseK() retourne le K plus proche voisi et compre() retourne le tag et la proba de la prédiction
	//for(int k=0; k<50 ;k++) knnClassifier.compare(knnClassifier.chooseK(nearestNeighborsSort, k));

	return 0;
}
