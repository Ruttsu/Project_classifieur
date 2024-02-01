#ifndef KNN_H
#define KNN_H
#pragma once

/*---------------------------------------------------------------------------
*
* Cr�ation
*
*L�objet Knn est une classe abstraite qui appel les méthodes des Knn spécifique.
 C'est la classe qui est responsable de la prédiction des sample à analyser. Elle
 possèdent les fonction suivante :

 - predict() est la fonction principal de la classe. Elle permet de remplir le
 vecteur de prédiction. Elle associe avec le tag réel ou la probalité que ça soit
 une bonne prédiction en fonction du fichier testé

 - displayResults() permet d'afficher les prédictions pour un fichier dont on ne
 connaît pas les sample

 - getPrediction retourne le tableau de prédiction

 - predictSingle() est une méthode virtuel pur qui doit être redéfini dans les knn
 spécifique. Elle permet de trier dans l'ordre croissant les voisins les plus proches
 de l'échantillon testé

 - similarity() est une méthode virtuel pur qui doit être redéfini dans les knn
 spécifique. Elle permet de définir la distance entre deux featuresVector.

 - choosK() renvoie les K plus proches voisins

 - compare() grâce au k plus proche voisin elle détermine la moyenne pour génerer
 une prédiction stable ainsi que sa probabilité

*
*----------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cmath>
#include <utility> // pour pair
#include <algorithm> // pour sort

#include "Data.h"
#include "Sample.h"
#include "FeatureVector.h"


using namespace std;

class Knn {

public:
    Knn(Data trainingdata);
    virtual ~Knn() = default;
    void predict(const Data& test, int k);

    void displayResult()const;
    vector<pair<int, int>> getPrediction() const;

protected:
    virtual vector<pair<float, size_t>> predictSingle(const FeatureVector& test) const = 0;
    virtual float similarity(const FeatureVector& test, const FeatureVector& data) const = 0;

    vector<pair<float, size_t>> chooseK(const vector<pair<float, size_t>>& nearestNeighbors, int k); // Grâce au données récuperés pa predictSingle, retourne un tableau trié des k plus proche voisins
    vector<pair<float, size_t>> compare(vector<pair<float, size_t>> nearestNeighbors); // Grâce au tableau des K plus proches voisins retourné par chooseK, retourne le tag ainsi que la proba de cette prediction

    Data _lazy_train; //protected pour etre accessible par KnnAlgo

private:
    vector<pair<int, int>> _prediction;
    vector<pair<int, float>> _predictionConfiance;
};

#endif