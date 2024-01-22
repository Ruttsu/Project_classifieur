// KnnCosine.cpp
#include "Knncosine.h"
#include <vector>
#include <utility> // pour std::pair
#include <algorithm> // pour std::sort

using namespace std;

KnnCosine::KnnCosine(): Knn() {} //constru vide ?

float KnnCosine::similarity(FeatureVector test, FeatureVector data) const {

    float result = 0;
	if (test.getSize() == data.getSize() && test.getNorme() != 0 && data.getNorme() != 0) {
		for (int i = 0; i < test.getSize(); i++) {
			result += test._vector[i] * data._vector[i];
		}
        result /= test.getNorme() * data.getNorme();
	}

    return result;
}


std::vector<std::pair<double, size_t>> KnnCosine::predictSingle(const FeatureVector& test, int k) const {
    /*
    std::vector<Sample> nearestNeighbors;

    // Utilisons une structure de données pour stocker la similarité cosine et l'indice original
    std::vector<std::pair<double, size_t>> cosineSimilarities;

    for (size_t i = 0; i < trainingData_.size(); ++i) {
        const FeatureVector& currentFeatures = trainingData_[i].getFeatures();
        double similarity = compare(query, currentFeatures);
        cosineSimilarities.push_back(std::make_pair(similarity, i));
    }

    // Tri des similarités dans l'ordre décroissant
    std::sort(cosineSimilarities.rbegin(), cosineSimilarities.rend());

    // Sélection des k plus proches voisins
    std::vector<std::pair<double, size_t>> nearestNeighborsPairs;
    for (int i = 0; i < k; ++i) {
        nearestNeighborsPairs.push_back(cosineSimilarities[i]);
    }
   

    return nearestNeighborsPairs;
     */

    return std::vector<std::pair<double, size_t>>();
}

