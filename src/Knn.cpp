// KNN.cpp
#include "Knn.h"

Knn::Knn(Data trainingdata) : _lazy_train(trainingdata) { //constru avec les datas d'entrainement en param
}


void Knn::predict(const FeatureVector& carac) const {
    // À implémenter
}

void Knn::getKnn() const {
    // À implémenter
}

std::vector<std::pair<double, size_t>> Knn::predictSingle(const FeatureVector& test, int k) const {
    // À implémenter 
    return std::vector<std::pair<double, size_t>>();
}