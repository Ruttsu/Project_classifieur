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

public:
    Knn(Data trainingdata);
    ~Knn() = default;
    std::vector<std::pair<float, size_t>> predict(const Data& test, int k) const; // I : Data (si possible déja scale)  | O : Tag et pourcentage de précision

protected:
    virtual void getKnn() const ;    //= 0;
    virtual std::vector<std::pair<float, size_t>> predictSingle(const FeatureVector& test, int k) const = 0;
    virtual float similarity(const FeatureVector& test, const FeatureVector& data) const = 0;

    Data _lazy_train; //protected pour etre accessible par KnnAlgo
};

#endif