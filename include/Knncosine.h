#ifndef KNN_COSINE_H
#define KNN_COSINE_H
#pragma once

#include "Knn.h"

class KnnCosine : public Knn {
public:
    KnnCosine(const Data& trainingData);

    virtual vector<pair<float, size_t>> predictSingle(const FeatureVector& test) const override; // I : Feature and int | O : Vector of <double, unsigned int>
    virtual float similarity(const FeatureVector& test, const FeatureVector& data) const override; // Compare 2 featurevector, return float (value of similarity)
    
    vector<pair<float, size_t>> chooseK(const vector<pair<float, size_t>>& nearestNeighbors, int k); // Grâce au données récuperés pa predictSingle, retourne un tableau trié des k plus proche voisins
    void compare(vector<pair<float, size_t>> nearestNeighbors); // Grâce au tableau des K plus proches voisins retourné par chooseK, retourne le tag ainsi que la proba de cette prediction
};

#endif // KNN_COSINE_H

