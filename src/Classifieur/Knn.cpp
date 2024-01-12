// KNN.cpp
#include "KNN.h"
#include "Data.h"

// Implémentation des méthodes virtuelles pures de la classe de base KNN
double KNN::compare(const FeatureVector& a, const FeatureVector& b) const {
    // À implémenter
    return 0.0;
}

std::vector<Sample> KNN::findKNearestNeighbors(const FeatureVector& query, int k) const {
    // À implémenter 
    return {};
}

void KNN::getKnn() const {
    // À implémenter
}

void KNN::predictSingle() const {
    // À implémenter 
}
