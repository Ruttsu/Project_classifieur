#ifndef KNN_COSINE_H
#define KNN_COSINE_H
#pragma once

#include "Knn.h"

class KnnCosine : public Knn {
public:
    KnnCosine();
    // virtual double compare(const FeatureVector& a, const FeatureVector& b) const override;
    // virtual vector<Sample> findKNearestNeighbors(const FeatureVector& carac, int k) const override;
    // virtual void predictSingle(const FeatureVector& carac) const override;
    // virtual double similarity(const FeatureVector& a, const FeatureVector& b) const;

    virtual float predictSingle() const override;
    virtual float similarity(Sample test, Sample data) const override;
};

#endif // KNN_COSINE_H

