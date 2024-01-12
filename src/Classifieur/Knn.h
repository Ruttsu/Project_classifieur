#pragma once
#ifndef KNN_H
#define KNN_H
#endif //KNN_H
#include <vector>
#include "Data.h"

using namespace std;

class KNN {
public:
    virtual double compare(const FeatureVector& a, const FeatureVector& b) const = 0;
    virtual vector<Sample> findKNearestNeighbors(const FeatureVector& query, int k) const = 0;
    virtual void train(const Data& trainingData) = 0;

protected:
    virtual void getKnn() const = 0;
    virtual void predictSingle() const = 0;
    virtual void similarity() const = 0;
};

#endif // KNN_H