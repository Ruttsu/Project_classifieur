#pragma once
#ifndef KNN_COSINE_H
#define KNN_COSINE_H

#include "Knn.h"
#include "Sample.h"
#include "Data.h"
#include "FeatureVector"

using namespace std;

class KnnCosine : public Knn {
public:
    KnnCosine();
    virtual double compare(const FeatureVector& a, const FeatureVector& b) const override;
    virtual vector<Sample> findKNearestNeighbors(const FeatureVector& carac, int k) const override;
    virtual void predictSingle(const FeatureVector& carac) const override;

private:
    // Autres membres et méthodes spécifiques à KnnCosine si nécessaire
};

#endif // KNN_COSINE_H

