// KNN.cpp
#include "../include/Knn.h"
#include <utility> // pour pair
#include <algorithm> // pour sort

Knn::Knn(Data trainingdata) : _lazy_train(trainingdata) {} //constru avec les datas d'entrainement en param


void Knn::predict(const Data& test, int k) {

    int error = 0;
    vector<pair<float, size_t>> predictions; // Vecteur de paires de prédiction avec pourcentage et tag prédit

    _prediction.clear();
    _predictionConfiance.clear();

    for (int i = 0; i < test.getNbSample(); ++i) {
        FeatureVector featureTest = test[i].getFeatures();
        vector<pair<float, size_t>> cosineSimilarities = predictSingle(featureTest);
        // cout << "Le tag réél est " << test[i].getTag() << " : ";
        predictions = compare(chooseK(cosineSimilarities, k));
        _prediction.push_back(make_pair(predictions[0].second, test[i].getTag()));

        _predictionConfiance.push_back(make_pair(predictions[0].second, predictions[0].first));

        if(test[i].getTag() != predictions[0].second) error++;
    }
    // cout << "Nombre d'erreur : " << error << endl << endl;
}

void Knn::getKnn() const {
    // À implémenter
}

vector<pair<int, int>> Knn::getPrediction() const
{
    return _prediction;
}

void Knn::displayResult() const {
    int i=1;
    for(const auto& predicted : _predictionConfiance)
    {
        cout<<"Sample " << i << " est un "<<predicted.first<<" avec une probabilité de "<<predicted.second<< "% "<<endl;
        i++;
    }
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
    // cout << "Pour K = " << k << ", ";
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
	// cout << "la prédiction est un " << tag << ", avec une probilité est de " << proba << "%" << endl;

    vector<pair<float, size_t>> result;
    result.push_back(make_pair(proba, tag));
    return result;

}