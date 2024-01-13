// KNN.cpp
#include "Knn.h"

Knn::Knn() {}

// Implémentation des méthodes virtuelles pures de la classe de base KNN
double Knn::compare(const FeatureVector& a, const FeatureVector& b) const {
    // À implémenter
    return 0.0;
}

vector<Sample> Knn::findKNearestNeighbors(const FeatureVector& query, int k) const {
    // À implémenter 
    return {};
}

void Knn::predict(const FeatureVector& carac) const {
    // À implémenter
}

void Knn::getKnn() const {
    // À implémenter
}

float Knn::predictSingle() const {
    // À implémenter 
    return 0;
}
