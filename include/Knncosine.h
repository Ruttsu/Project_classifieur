#ifndef KNN_COSINE_H
#define KNN_COSINE_H
#pragma once

#include "Knn.h"

class KnnCosine : public Knn {
public:
    KnnCosine(const Data& trainingData);

    virtual std::vector<std::pair<double, size_t>> predictSingle(const FeatureVector& test, int k) const;
    virtual float similarity(const FeatureVector& test, const FeatureVector& data) const override;
};

#endif // KNN_COSINE_H

