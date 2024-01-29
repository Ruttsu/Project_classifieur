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

    gofichierTest:
    bool donneeTest=false;
    path="";
    cout << "Donnez le chemin du fichiers a tester :" << endl;
    cin >> path;
    cout << "Connaissez vous ce que represent chaque ligne (0.NON 1.0UI)" << endl;
    cin >> donneeTest;
    Data testingData(path, donneeTest);

    //dataEntrainement.displayData();

    KnnCosine knnCosine(trainingData);
    KnnEuclidien knnEuclide(trainingData);
    KnnManhattan knnManhattan(trainingData);

    govaleurk:
    int k;
    cout << "Attribuez la valeur de k :" << endl;
    cin >> k;

    //cout << "La valeur de k est :" << endl;

    //Faire les calculs des Knn

    goclalcul:

    vector<pair<int, int>> predictedCosine;
    vector<pair<int, int>> predictedEuclide;
    vector<pair<int, int>> predictedManhattan;

    knnCosine.predict(testingData,k); // variable pour stocker les voisins
    knnEuclide.predict(testingData,k); // variable pour stocker les voisins
    knnManhattan.predict(testingData,k); // variable pour stocker les voisins


    //Demander de display les prediction en selon quel Knn

    if(!donneeTest)
    {
        cout << "Menu :" << endl;
        cout << "1. Afficher les prediction de la methode knn cosine" << endl;
        cout << "2. Afficher les prediction de la methode knn euclidien" << endl;
        cout << "3. Afficher les prediction de la methode knn manhattan" << endl;
        cout << "0. Quitter" << endl;
        cin >> commande;

        switch (commande)
        {
            case 0:
                exit(0);

            case 1:
                cout << "Voici les resultats pour knnCosine :" << endl;
                knnCosine.displayResult();
                break;

            case 2:
                cout << "Voici les restultats pour knnEuclide :" << endl;
                knnEuclide.displayResult();
                break;

            case 3:

                cout << "Voici les resultats pour knnManhattan :" << endl;
                knnManhattan.displayResult();
                break;

            default :
                cout<<"Commande introubale"<<endl;

        }

    }

    //afficher les donner de compréhension proposer les différent type de knn

    if(donneeTest)
    {
        ClassificationReport reportCosine;
        ClassificationReport reporEuclide;
        ClassificationReport reportManhattan;

        cout << "Menu :" << endl;
        cout << "1. Afficher le raport sur la methode knn cosine" << endl;
        cout << "2. Afficher le raport sur la methode knn euclidien" << endl;
        cout << "3. Afficher le raport sur la methode knn manhattan" << endl;
        cout << "0. Quitter" << endl;
        cin >> commande;

        switch (commande)
        {

            case 0:
                exit(0);

            case 1:
                cout << "Voici le raport pour knnCosine :" << endl;
                reportCosine.setTabConfusion(knnCosine);
                reportCosine.displayReport();
                break;

            case 2:
                cout << "Voici le raport pour knnEuclide :" << endl;
                reporEuclide.setTabConfusion(knnEuclide);
                reporEuclide.displayReport();
                break;

            case 3:

                cout << "Voici le raport pour knnManhattan :" << endl;
                reportManhattan.setTabConfusion(knnManhattan);
                reportManhattan.displayReport();
                break;

            default :
                cout<<"Commande introubale"<<endl;

        }

    }


    //Veut tu changers k retourner a l'affcihage des donner, changer le fichier de test ou quittez

    cout << "Menu :" << endl;
    cout << "1. Changer le fichier de test" << endl;
    cout << "2. Changer la valeur de k" << endl;
    cout << "3. Afficher de nouveau les resltats" << endl;
    cout << "0. Quitter" << endl;
    cin >> commande;

    switch (commande)
    {

        case 0:
            exit(0);

        case 1:
            goto gofichierTest;

        case 2:
            goto govaleurk;

        case 3:
            goto goclalcul;

        default :
            cout<<"Commande introubale"<<endl;

    }

}
