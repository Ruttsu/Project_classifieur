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

class Knn: public Data {
public:
    Knn();
    virtual ~Knn() = default;

    virtual void predict(const FeatureVector& carac) const;

protected:
    virtual void getKnn() const ;//= 0;
    virtual float predictSingle() const = 0;
    virtual float similarity(Sample test, Sample data) const = 0;

    virtual double compare(const FeatureVector& a, const FeatureVector& b) const ;//= 0;
    virtual vector<Sample> findKNearestNeighbors(const FeatureVector& query, int k) const ;// = 0;
    // virtual void predictSingle(const FeatureVector& carac) const ;//= 0;

};

#endif