#ifndef KNN_H
#define KNN_H
#pragma once


#include <iostream>
#include <vector>
#include <cmath>

#include "Data.h"
#include "Sample.h"
#include "FeatureVector.h"


using namespace std;

class Knn {

    Data _lazy_train;

public:
    Knn();
    virtual ~Knn() = default;
    virtual void predict(const FeatureVector& carac) const;

protected:
    virtual void getKnn() const ;    //= 0;
    virtual std::vector<std::pair<double, size_t>> predictSingle(const FeatureVector& test, int k) const = 0;
    virtual float similarity(FeatureVector test, FeatureVector data) const = 0;
};

#endif