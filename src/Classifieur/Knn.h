#pragma once
#ifndef KNN_H
#define KNN_H
#endif //KNN_H
#include <vector>
#include "Data.h"

using namespace std;

class KNN {
public:
    knn();
    virtual void predict(const FeatureVector& carac) const override;

protected:
    virtual void getKnn() const = 0;
    virtual double compare(const FeatureVector& a, const FeatureVector& b) const = 0;
    virtual void predictSingle(const FeatureVector& carac) const = 0;
    virtual vector<Sample> findKNearestNeighbors(const FeatureVector& query, int k) const = 0;
};

#endif // KNN_H