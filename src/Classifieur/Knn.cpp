// KNN.cpp
#include "Knn.h"
#include "Data.h"

// Implémentation des méthodes virtuelles pures de la classe de base KNN
double Knn::compare(const FeatureVector& a, const FeatureVector& b) const {
    // À implémenter
    return 0.0;
}

std::vector<Sample> Knn::findKNearestNeighbors(const FeatureVector& query, int k) const {
    // À implémenter 
    return {};
}

void Knn::getKnn() const {
    // À implémenter
}

void Knn::predictSingle() const {
    // À implémenter 
}
