// KNN.cpp
#include "../include/Knn.h"
#include <utility> // pour pair
#include <algorithm> // pour sort

Knn::Knn(Data trainingdata) : _lazy_train(trainingdata) {} //constru avec les datas d'entrainement en param


//vector<pair<float, size_t>> Knn::predict(const Data& test, int k) {
void Knn::predict(const Data& test, int k) {
    vector<pair<float, size_t>> predictions; // Vecteur de paires de prédiction avec pourcentage et tag prédit

    int error = 0;
    for (int i = 0; i < test.getNbSample(); ++i) {
        FeatureVector featureTest = test[i].getFeatures();
        vector<pair<float, size_t>> cosineSimilarities = predictSingle(featureTest);
        cout << "Le tag réél est " << test[i].getTag() << " : ";
        predictions = compare(chooseK(cosineSimilarities, k));

        if(test[i].getTag() != predictions[0].first) error++;
    }
    cout << "Nombre d'erreur : " << error << endl << endl;
    
/*
        // Collecte des tags des voisins
        vector<size_t> neighborTags;
        for (const auto& neighbor : cosineSimilarities) {
            neighborTags.push_back(neighbor.second);
        }

        // Trouver le tag majoritaire
        sort(neighborTags.begin(), neighborTags.end()); // Trie par ordre croissant des tags des nearest neighbors
        size_t mostFrequentTag = neighborTags[0]; // Initialisation avec le premier tag
        size_t currentTag = mostFrequentTag;
        int currentCount = 1;
        int maxCount = 1;

        for (size_t i = 1; i < neighborTags.size(); ++i) {
            if (neighborTags[i] == currentTag) {
                currentCount++;
            } else {
                if (currentCount > maxCount) {
                    maxCount = currentCount;
                    mostFrequentTag = currentTag;
                }
                currentTag = neighborTags[i];
                currentCount = 1;
            }
        }

        // Vérifier le dernier groupe de tags
        if (currentCount > maxCount) {
            mostFrequentTag = currentTag;
        }

        // Calcul du tag prédit et du pourcentage de certitude
        float totalWeightedSimilarity = 0.0;
        float totalWeight = 0.0;
        size_t predictedTag = mostFrequentTag;

        for (const auto& neighbor : cosineSimilarities) { // Parcours des k voisins
            if (neighbor.second == mostFrequentTag) {
                float weightedSimilarity = neighbor.first; // Utilisation du tag comme coefficient
                totalWeightedSimilarity += weightedSimilarity;
            }
            totalWeight += neighbor.first; // Utilisation de la similarity comme coefficient
        }

        // Calcul du pourcentage en fonction du total pondéré des similarités
        float certaintyPercentage = (totalWeightedSimilarity / totalWeight) * 100.0;

        // Stockage des résultats dans le vecteur de prédictions
        predictions.push_back(make_pair(certaintyPercentage, predictedTag));
    }

    return predictions;
*/
}

void Knn::getKnn() const {
    // À implémenter
}


vector<pair<float, size_t>> Knn::predictSingle(const FeatureVector& test) const {
    // À implémenter 
    return vector<pair<float, size_t>>();
}

vector<pair<float, size_t>> Knn::chooseK(const vector<pair<float, size_t>>& nearestNeighbors, int k) {

    vector<pair<float, size_t>> nearestNeighborsPairs;
    for (int i = 0; i < k; ++i) {
        nearestNeighborsPairs.push_back(make_pair(nearestNeighbors[i].first, nearestNeighbors[i].second));
    }
    cout << "Pour K = " << k << ", ";
    return nearestNeighborsPairs;
}

vector<pair<float, size_t>> Knn::compare(vector<pair<float, size_t>> nearestNeighbors) {

	float figures[10] = {0};
	for (const auto &neighbor : nearestNeighbors) {
		double similarityValue = neighbor.first; // La première valeur est la similarité
		int tag = neighbor.second;

		figures[tag] += similarityValue;

		// cout << "Tag du sample : " << tag << endl;
		// cout << "Similarite : " << similarityValue << endl;
		// cout << endl;
	}

	int tag = -1;
	float total = 0;
	for (int i=0; i < 10; i++){
		//cout << figures[i] << " ";
		total += figures[i];
		if(i == 0) {
			tag = 0;
		} else {
			if(figures[i] > figures[tag]) tag = i;
		}
	}
	
	float proba = total != 0 ? figures[tag]*100 / total : -1;
	cout << "la prédiction est un " << tag << ", avec une probilité est de " << proba << "%" << endl;

    vector<pair<float, size_t>> result;
    result.push_back(make_pair(tag, proba));
    return result;

}