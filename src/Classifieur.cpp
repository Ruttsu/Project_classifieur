// Classifieur.cpp : définit le point d'entrée de l'application.

#include "Classifieur.h"
#include "Data.h"
#include "FeatureVector.h"
#include "KnnEuclidien.h"
#include "KnnManhattan.h"
#include "Knncosine.h"
#include "ClassificationReport.h"
#include "Application.h"

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
    Data trainingData("C:/Users/Jerome/Documents/Project_classifieur/doc/Digits/digits.svm", true);
    std::cout << "Fin de l'import des données d'apprentissage" << std::endl;

	Data testData("C:/Users/Jerome/Documents/Project_classifieur/doc/Digits/digits_copy.svm", false);
    std::cout << "Fin de l'import des données de test" << std::endl;

    // Créer une instance de la classe KnnCosine avec les données d'apprentissage
    KnnCosine knnClassifier(trainingData);

  // fonction predictSingle pour obtenir les k plus proches voisins
    int k = 15; // nombre de voisins

    std::vector<std::pair<float, size_t>> nearestNeighbors = knnClassifier.predict(testData, k); // variable pour stocker les voisins

    // Affichage de la paire de clés à la fin
    for (const auto& neighbor : nearestNeighbors) {
        std::cout << "Tag predit : " << neighbor.second << std::endl;
        std::cout << "Pourcentage de certitude : " << neighbor.first << "%\n" << std::endl;
    }

    return 0;
}
