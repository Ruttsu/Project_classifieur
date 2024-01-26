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
	KnnCosine knnCosine(trainingData);
	KnnEuclidien knnEuclide(trainingData);
	KnnManhattan knnManhattan(trainingData);

    ClassificationReport reportCosine;
	ClassificationReport reporEuclide;
	ClassificationReport reportManhattan;

	int k = 10; //tester avec 10 et 15
	// fonction predict pour obtenir les k plus proches voisins de tout les valeurs de testingData
	cout << endl << "Cosine : " << endl;
	vector<pair<int, int>> predictedCosine = knnCosine.predict(testingData,k); // variable pour stocker les voisins
//	for( const auto& predicted : predictedCosine) reportCosine.setTabConfusion(predicted.first, predicted.second);
//	reportCosine.displayTabConfusion();
    reportCosine.displayReport(predictedCosine);

	cout << endl << "Euclidien : " << endl;
	vector<pair<int, int>> predictedEuclide = knnEuclide.predict(testingData,k);	//Attention j'ai du mettre héritage public et non protected pour que ça marche
	for( const auto& predicted : predictedEuclide) reporEuclide.setTabConfusion(predicted.first, predicted.second);
	reporEuclide.displayTabConfusion();

	cout << endl << "Manhattan : " << endl;
	vector<pair<int, int>> predictedManhattan = knnManhattan.predict(testingData,k);	//Attention j'ai du mettre héritage public et non protected pour que ça marche
	for( const auto& predicted : predictedManhattan) reportManhattan.setTabConfusion(predicted.first, predicted.second);
	reportManhattan.displayTabConfusion();

	// ChooseK() retourne le K plus proche voisi et compre() retourne le tag et la proba de la prédiction
	//for(int k=0; k<50 ;k++) knnClassifier.compare(knnClassifier.chooseK(nearestNeighborsSort, k));

	return 0;
}
