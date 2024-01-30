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
    virtual ~Knn() = default;
    void predict(const Data& test, int k);

    //lucas
    void displayResult()const;
    vector<pair<int, int>> getPrediction() const;

//protected:
    virtual void getKnn() const ;    //= 0;
    virtual vector<pair<float, size_t>> predictSingle(const FeatureVector& test) const = 0;
    virtual float similarity(const FeatureVector& test, const FeatureVector& data) const = 0;

    //vector<pair<float, size_t>> chooseK(const vector<pair<float, size_t>>& nearestNeighbors, int k); // Grâce au données récuperés pa predictSingle, retourne un tableau trié des k plus proche voisins
    vector<pair<float, size_t>> compare(vector<pair<float, size_t>> nearestNeighbors, int k); // Grâce au tableau des K plus proches voisins retourné par chooseK, retourne le tag ainsi que la proba de cette prediction

    Data _lazy_train; //protected pour etre accessible par KnnAlgo

    //lucas
    vector<pair<int, int>> _prediction;
};

#endif