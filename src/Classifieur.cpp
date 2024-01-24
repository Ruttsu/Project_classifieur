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

	//Application app;
	//app.run();
	
/*
	//TEST de la class classificationReport
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

    test.displayTabConfusion();*/

    // Charger les données d'apprentissage depuis le fichier
    Data trainingData("../doc/Digits/digits.svm", true);
    std::cout << "Fin de l'import des données d'apprentissage" << std::endl;

    // FeatureVector de test (premier du fichier digits)
    FeatureVector testFeatures;
    testFeatures.addFeatures(0.793836);
	testFeatures.addFeatures(0.264603);
	testFeatures.addFeatures(0.10347);
	testFeatures.addFeatures(0.12025);
	testFeatures.addFeatures(0.457457);
	testFeatures.addFeatures(0.130727);
	testFeatures.addFeatures(0.247971);
	testFeatures.addFeatures(0.163846);
	testFeatures.addFeatures(0.416592);
	testFeatures.addFeatures(0.0105225);
	testFeatures.addFeatures(0.197518);
	testFeatures.addFeatures(0.120068);
	testFeatures.addFeatures(0.649331);
	testFeatures.addFeatures(0.0546827);
	testFeatures.addFeatures(0.0542517);
	testFeatures.addFeatures(0.0481252);
	testFeatures.addFeatures(0.137483);
	testFeatures.addFeatures(0.111458);
	testFeatures.addFeatures(0.15022);
	testFeatures.addFeatures(0.131084);
	testFeatures.addFeatures(0.182864);
	testFeatures.addFeatures(0.129831);
	testFeatures.addFeatures(0.0894998);
	testFeatures.addFeatures(0.0827041);
	testFeatures.addFeatures(0.051342);
	testFeatures.addFeatures(0.422515);
	testFeatures.addFeatures(0);
	testFeatures.addFeatures(0.000284315);
	testFeatures.addFeatures(0.029238);
	testFeatures.addFeatures(0.0881091);
	testFeatures.addFeatures(0);
	testFeatures.addFeatures(0.00480701);
	testFeatures.addFeatures(0.276144);
	testFeatures.addFeatures(0.0405575);
	testFeatures.addFeatures(0.254078);
	testFeatures.addFeatures(0.490479);
	testFeatures.addFeatures(0.53111);
	testFeatures.addFeatures(0.171567);
	testFeatures.addFeatures(0.413972);
	testFeatures.addFeatures(0.268241);
	testFeatures.addFeatures(0.200363);
	testFeatures.addFeatures(0.161456);
	testFeatures.addFeatures(0.370557);
	testFeatures.addFeatures(0.123517);
	testFeatures.addFeatures(0.224544);
	testFeatures.addFeatures(0.0532561);
	testFeatures.addFeatures(0.247592);
	testFeatures.addFeatures(0.582612);
	testFeatures.addFeatures(0.31274);
	testFeatures.addFeatures(0.0197861);
	testFeatures.addFeatures(0.641833);
	testFeatures.addFeatures(0.426604);
	testFeatures.addFeatures(0.363537);
	testFeatures.addFeatures(0.340048);
	testFeatures.addFeatures(0.578312);
	testFeatures.addFeatures(0.191365);
	testFeatures.addFeatures(0.0989377);
	testFeatures.addFeatures(0.0580434);
	testFeatures.addFeatures(0.214284);
	testFeatures.addFeatures(0.17585);
	testFeatures.addFeatures(0.0381746);
	testFeatures.addFeatures(0.312853);
	testFeatures.addFeatures(0);
	testFeatures.addFeatures(0.00109727);
	testFeatures.addFeatures(0.119835);
	testFeatures.addFeatures(0.395257);
	testFeatures.addFeatures(0);
	testFeatures.addFeatures(0.00770754);
	testFeatures.addFeatures(0.446204);
	testFeatures.addFeatures(0.0789867);

    // Créer une instance de la classe KnnCosine avec les données d'apprentissage
    KnnCosine knnClassifier(trainingData);

    // fonction predictSingle pour obtenir les k plus proches voisins
    int k = 15; // nombre de voisins

    std::vector<std::pair<float, size_t>> nearestNeighbors = knnClassifier.predictSingle(testFeatures, k); //variable pour stocker les voisins

    std::cout << "Les " << k << " plus proches voisins d'apprentissage sont :\n" << std::endl;

for (const auto& neighbor : nearestNeighbors) {
    double similarityValue = neighbor.first;  // La première valeur est la similarité
	int tag = neighbor.second;

    std::cout << "Tag du sample : " << tag << std::endl;
    std::cout << "Similarite : " << similarityValue << std::endl;
    std::cout << std::endl;
}

    return 0;
}
