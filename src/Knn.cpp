// KNN.cpp
#include "../include/Knn.h"
#include <algorithm>

Knn::Knn(Data trainingdata) : _lazy_train(trainingdata) {} //constru avec les datas d'entrainement en param


//vector<pair<float, size_t>> Knn::predict(const Data& test, int k) {
void Knn::predict(const Data& test, int k) {
    vector<pair<float, size_t>> predictions; // Vecteur de paires de prédiction avec pourcentage et tag prédit

    for (int i = 0; i < test.getNbSample(); ++i) {
        FeatureVector featureTest = test[i].getFeatures();
        vector<pair<float, size_t>> cosineSimilarities = predictSingle(featureTest);
        cout << "Le tag réél est " << test[i].getTag() << " : ";
        compare(chooseK(cosineSimilarities, k));
    }
    
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