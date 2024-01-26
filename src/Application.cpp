//
// Created by lucas on 23/01/2024.
//

#include "../include/Application.h"
#include "Knncosine.h"
#include "KnnEuclidien.h"
#include "KnnManhattan.h"
#include "ClassificationReport.h"
#include <cstdlib>

using namespace std;

void Application::run(){

    int commande=0;

    string path;
    cout << "Donnez le chemin du fichiers d'entrainement :" << endl;
    cin >> path;
    Data trainingData(path,1);

    //dataApprentissage.displayData();

    int k;
    cout << "Attribuez la valeur de k :" << endl;
    cin >> k;

    //cout << "La valeur de k est :" << endl;

    bool donneeTest=false;
    path="";
    cout << "Donnez le chemin du fichiers a tester :" << endl;
    cin >> path;
    cout << "Connaissez vous ce que represent chaque ligne (0.NON 1.0UI)" << endl;
    cin >> donneeTest;
    Data testingData(path, donneeTest);

    //dataEntrainement.displayData();

    //Faire les calculs des Knn

    KnnCosine knnCosine(trainingData);
    KnnEuclidien knnEuclide(trainingData);
    KnnManhattan knnManhattan(trainingData);

    //Demander de display les prediction en selon quel Knn

    //afficher les donner de compréhension proposer les différent type de knn

    if(donneeTest)
    {
        ClassificationReport reportCosine;
        ClassificationReport reporEuclide;
        ClassificationReport reportManhattan;

        vector<pair<int, int>> predictedCosine;
        vector<pair<int, int>> predictedEuclide;
        vector<pair<int, int>> predictedManhattan;

        cout << "Menu :" << endl;
        cout << "1. Afficher le raport sur la methode knn cosine" << endl;
        cout << "1. Afficher le raport sur la methode knn euclidien" << endl;
        cout << "1. Afficher le raport sur la methode knn manhattan" << endl;
        cout << "0. Quitter" << endl;
        cin >> commande;

        switch (commande) {

            case 0:
                exit(0);

            case 1:
                predictedCosine = knnCosine.predict(testingData,k); // variable pour stocker les voisins
                cout << "Voici le raport pour knnCosine :" << endl;
                reportCosine.displayReport(predictedCosine);
                break;

            case 2:
                predictedEuclide = knnEuclide.predict(testingData,k); // variable pour stocker les voisins
                cout << "Voici le raport pour knnEuclide :" << endl;
                reporEuclide.displayReport(predictedCosine);
                break;

            case 3:

                predictedManhattan = knnManhattan.predict(testingData,k); // variable pour stocker les voisins
                cout << "Voici le raport pour knnManhattan :" << endl;
                reportManhattan.displayReport(predictedCosine);
                break;

            default :
                cout<<"Commande introubale"<<endl;

        }


    }


    //Veut tu changers k
}