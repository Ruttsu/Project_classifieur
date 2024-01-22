// Classifieur.cpp : définit le point d'entrée de l'application.

#include "Classifieur.h"
#include "Data.h"
#include "FeatureVector.h"
#include "KnnEuclidien.h"
#include "KnnManhattan.h"
#include "Knncosine.h"
#include "ClassificationReport.h"

using namespace std;

void afficherMenu()
{
    cout << "Commandes disponibles (entrer la numéro de la commande):" << endl;
    cout << "1. Définir les fichiers d'entrer" << endl;
    cout << "2. Choisir la valeur de k <valeur>" << endl;
    cout << "3. Afficher les résultats" << endl;
    cout << "0. Quitter" << endl;
}

int main() {


    string path;
    cout << "Donnez le chemin du fichiers d'entrainement :" << endl;
    cin >> path;
    Data dataApprentissage(path,1);

    dataApprentissage.displayData();

   /* Data file("D:/Cours/INSA/Cpp/ProjetClassifieur/doc/Digits/Digits/digits.svm", 1);
    file.displayData();
    */
/*
    int commande;
    //donner a mettre dans les bonnes class
    int k=1;
    string path;
    bool donneeApprentissage;

    do {
        afficherMenu();
        cout << "Entrez une commande : ";
        cin >> commande;

        switch (commande) {
            case 1 :
                cout << "Entrez le chemin vers le fihchier que vous voulez entrer" << endl;
                cin >> path;
                cout << "Entrez 1 si c'est un fichier d'apprenttissage 0 si c'est un fichier a tester" << endl;
                cin >> donneeApprentissage;
                //creation d'une class data
                //Data mettreUnNom(path, donneeApprentissage);
                break;

            case 2 :
                cout << "Entrez la valeur de k : ";
                cin >> k;
                cout << "La valeur de k est : " << k << endl;
                break;

            case 3 :

                break;

            default :
                cout << "Commande inconnue." << endl;
        }



    } while (commande != 0);

    cout << "Programme terminé." << endl;



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
	return 0;
}
