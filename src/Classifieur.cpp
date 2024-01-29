// Classifieur.cpp : définit le point d'entrée de l'application.

#include "Classifieur.h"
#include "Data.h"
#include "FeatureVector.h"
#include "KnnEuclidien.h"
#include "KnnManhattan.h"
#include "Knncosine.h"
#include "ClassificationReport.h"
#include "Application.h"
#include <fstream> //for file

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
    int k = 5; // nombre de voisins

    std::vector<std::pair<float, size_t>> nearestNeighbors = knnClassifier.predict(testData, k);

    // Spécifiez le chemin complet du fichier de log
    std::string logFilePath = "C:/Users/Jerome/Documents/Project_classifieur/doc/output/log.txt";

    // Ouvrir le fichier de log en mode écriture (et créer/tronquer le fichier s'il existe)
    std::ofstream logFile(logFilePath, std::ofstream::trunc);

    if (logFile.is_open()) {
        // Rediriger la sortie standard vers le fichier
        std::streambuf* originalStdout = std::cout.rdbuf();  // Sauvegarder le tampon de sortie standard
        std::cout.rdbuf(logFile.rdbuf());  // Rediriger la sortie standard vers le fichier

    // Écrire les valeurs dans le fichier de log
    for (const auto& neighbor : nearestNeighbors) {
        std::cout << "Tag prédit : " << neighbor.second << std::endl;
        std::cout << "Pourcentage de certitude : " << neighbor.first << "%" << std::endl;
    }

    // Restaurer la sortie standard
    std::cout.rdbuf(originalStdout);  // Restaurer le tampon de sortie standard

    // Fermer le fichier de log
    logFile.close();
    } else {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier de log." << std::endl;
        std::cerr << "Chemin du fichier de log : " << logFilePath << std::endl;
        return 1;  // Code d'erreur
    }
}
