#ifndef KNNMANHATTAN_H
#define KNNMANHATTAN_H
#pragma once

/*----------------------------------------------------
Classe qui permet de mesurer la similarité selon la méthode de Manhattan.
Il existe d'autre méthode (Euclidienne, Minkowski et Tchebichev) 

Pour l'instant à utiliser sur FeatureVector/Sample (et à la venir sur Data ? puisque Knn est abstraite)

-similiraty : calcul la distance entre deux vecteur -> retour un float
    -> à faire entre le teste et tout les datas puis le plus petit score = le plus proche voisin pour k=1
------------------------------------------------------*/

#include "Knn.h"

class KnnManhattan: public Knn {
public:
    KnnManhattan();
    ~KnnManhattan();
    KnnManhattan(const Data& trainingData);

    virtual vector<pair<float, size_t>> predictSingle(const FeatureVector& test) const override; // I : Feature and int | O : Vector of <double, unsigned int>
    virtual float similarity(const FeatureVector& test, const FeatureVector& data) const override; // Compare 2 featurevector, return float (value of similarity)    
};

#endif