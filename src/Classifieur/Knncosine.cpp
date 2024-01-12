// KnnCosine.cpp
#include "KnnCosine.h"
#include "Sample.h"
#include "Data.h"
#include <cmath>
#include <iostream>

using namespace std;

KnnCosine::KnnCosine() { //constru vide ?
}

double KnnCosine::similarity(const FeatureVector& a, const FeatureVector& b) const {
    // Comparaison cosine entre les FeatureVectors a et b
    double dotProduct = 0.0;
    double normA = 0.0;
    double normB = 0.0;

    for (size_t i = 0; i < a.size(); ++i) {
        dotProduct += a[i] * b[i];
        normA += std::pow(a[i], 2);
        normB += std::pow(b[i], 2);
    }

    if (normA == 0.0 || normB == 0.0) {
        return 0.0;  // Éviter une division par zéro
    }

    return dotProduct / (sqrt(normA) * sqrt(normB));
} //OK similarité cosine

vector<Sample> KnnCosine::findKNearestNeighbors(const FeatureVector& carac, int k) const {
    std::vector<Sample> nearestNeighbors;

    // Utilisons une structure de données pour stocker la similarité cosine et l'indice original
    vector<std::pair<double, size_t>> cosineSimilarities;

    for (size_t i = 0; i < trainingData_.size(); ++i) {
        const FeatureVector& currentFeatures = trainingData_[i].getFeatures();
        double similarity = compare(query, currentFeatures);
        cosineSimilarities.push_back(std::make_pair(similarity, i));
    }

    // Tri des similarités dans l'ordre décroissant
    std::sort(cosineSimilarities.rbegin(), cosineSimilarities.rend());

    // Sélection des k plus proches voisins
    for (int i = 0; i < k; ++i) {
        size_t index = cosineSimilarities[i].second;
        nearestNeighbors.push_back(trainingData_[index]);
    }

    return nearestNeighbors;
}

void KnnCosine::predictSingle(const FeatureVector& query) const {
    std::vector<Sample> nearestNeighbors = findKNearestNeighbors(query, 1);

    if (!nearestNeighbors.empty()) {
        const Sample& nearestNeighbor = nearestNeighbors[0];
        // TODO: Utiliser nearestNeighbor pour effectuer la prédiction pour l'exemple unique
        std::cout << "Predicting for a single example using KnnCosine." << std::endl;
    } else {
        std::cerr << "No nearest neighbors found." << std::endl;
    }
}
