#ifndef KNN_COSINE_H
#define KNN_COSINE_H
#pragma once

#include "Knn.h"

class KnnCosine : public Knn {
public:
    KnnCosine();

    virtual std::vector<std::pair<double, size_t>> predictSingle(const FeatureVector& test, int k) const;
    virtual float similarity(FeatureVector test, FeatureVector data) const override;
};

#endif // KNN_COSINE_H

