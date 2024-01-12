// KNN.cpp
#include "KNN.h"
#include "Data.h"

// Implémentation des méthodes virtuelles pures de la classe de base KNN
double KNN::compare(const FeatureVector& a, const FeatureVector& b) const {
    // À implémenter dans les classes dérivées
    return 0.0;
}

std::vector<Sample> KNN::findKNearestNeighbors(const FeatureVector& query, int k) const {
    // À implémenter dans les classes dérivées
    return {};
}

void KNN::train(const Data& trainingData) {
    // À implémenter dans les classes dérivées
}

void KNN::getKnn() const {
    // À implémenter dans les classes dérivées
}

void KNN::predictSingle() const {
    // À implémenter dans les classes dérivées
}

void KNN::similarity() const {
    // À implémenter dans les classes dérivées
}
