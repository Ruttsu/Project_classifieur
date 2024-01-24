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

	// Charger les données d'apprentissage depuis le fichier
	Data trainingData("../doc/Digits/digits.svm", true);
	cout << "Fin de l'import des données d'apprentissage." << endl << endl;

	// FeatureVector de test (premier du fichier digits)
	FeatureVector testFeatures({0.793836, 0.264603, 0.10347, 0.12025, 0.457457, 0.130727, 0.247971, 0.163846, 0.416592, 0.0105225, 0.197518, 0.120068, 0.649331, 0.0546827, 0.0542517, 0.0481252, 0.137483, 0.111458, 0.15022, 0.131084, 0.182864, 0.129831, 0.0894998, 0.0827041, 0.051342, 0.422515, 0, 0.000284315, 0.029238, 0.0881091, 0, 0.00480701, 0.276144, 0.0405575, 0.254078, 0.490479, 0.53111, 0.171567, 0.413972, 0.268241, 0.200363, 0.161456, 0.370557, 0.123517, 0.224544, 0.0532561, 0.247592, 0.582612, 0.31274, 0.0197861, 0.641833, 0.426604, 0.363537, 0.340048, 0.578312, 0.191365, 0.0989377, 0.0580434, 0.214284, 0.17585, 0.0381746, 0.312853, 0, 0.00109727, 0.119835, 0.395257, 0, 0.00770754, 0.446204, 0.0789867});

	// Créer une instance de la classe KnnCosine avec les données d'apprentissage
	KnnCosine knnClassifier(trainingData);

	// fonction predictSingle pour obtenir les k plus proches voisins
	vector<pair<float, size_t>> nearestNeighborsSort = knnClassifier.predictSingle(testFeatures); // variable pour stocker les voisins

	// ChooseK() retourne le K plus proche voisi et compre() retourne le tag et la proba de la prédiction
	for(int k=0; k<50 ;k++) knnClassifier.compare(knnClassifier.chooseK(nearestNeighborsSort, k));

	return 0;
}
