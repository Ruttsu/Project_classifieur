#ifndef KNN_COSINE_H
#define KNN_COSINE_H
#pragma once

#include "Knn.h"

class KnnCosine : public Knn {
public:
    KnnCosine(const Data& trainingData);

    virtual vector<pair<float, size_t>> predictSingle(const FeatureVector& test, int k) const override; // I : Feature and int | O : Vector of <double, unsigned int>
    virtual float similarity(const FeatureVector& test, const FeatureVector& data) const override; // Compare 2 featurevector, return float (value of similarity)
};

#endif // KNN_COSINE_H

