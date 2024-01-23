//
// Created by lucas on 23/01/2024.
//

#include "Application.h"

using namespace std;

void Application::run(){

    string path;
    cout << "Donnez le chemin du fichiers d'entrainement :" << endl;
    cin >> path;
    Data dataApprentissage(path,1);

    //dataApprentissage.displayData();

    int k;
    cout << "Attribuez la valeur de k :" << endl;
    cin >> k;

    //cout << "La valeur de k est :" << endl;

    path="";
    cout << "Donnez le chemin du fichiers a determiner :" << endl;
    cin >> path;
    Data dataEntrainement(path, 0);

    //dataEntrainement.displayData();

    //Faire les calculs des Knn

    //Demander de display les prediction en selon quel Knn

    //Veut tu changers k

    //afficher les donner de compréhension
}