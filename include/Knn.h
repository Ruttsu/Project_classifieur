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
    vector<pair<int, int>> predict(const Data& test, int k);
    std::vector<std::pair<float, size_t>> predict(const Data& test, int k) const;
    //size_t selectMajorityTag(const std::vector<size_t>& neighborTags) const;
    //float calculatePrecision(const std::vector<std::pair<float, size_t>>& cosineSimilarities, size_t majorityTag) const;

protected:
    virtual vector<pair<float, size_t>> predictSingle(const FeatureVector& test) const = 0;
    virtual float similarity(const FeatureVector& test, const FeatureVector& data) const = 0;

    vector<pair<float, size_t>> chooseK(const vector<pair<float, size_t>>& nearestNeighbors, int k); // Grâce au données récuperés pa predictSingle, retourne un tableau trié des k plus proche voisins
    vector<pair<float, size_t>> compare(vector<pair<float, size_t>> nearestNeighbors); // Grâce au tableau des K plus proches voisins retourné par chooseK, retourne le tag ainsi que la proba de cette prediction

    Data _lazy_train; //protected pour etre accessible par KnnAlgo
};

#endif