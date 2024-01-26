#include "../include/KnnEuclidien.h"
#include <vector>
#include <utility> // pour pair
#include <algorithm> // pour sort

KnnEuclidien::KnnEuclidien(const Data& trainingData) : Knn(trainingData) {} // Initialisation via constru de Knn
KnnEuclidien::~KnnEuclidien() {}


float KnnEuclidien::similarity(const FeatureVector& test, const FeatureVector& data) const {

    float somme = 0;
	if (test.getSize() != data.getSize()) {
        throw invalid_argument("Les vecteurs doivent avoir la même taille."); //TODO a catch
	} else {
        for (int i = 0; i<test.getSize(); i++) {
			somme += pow(data._vector[i] - test._vector[i],2);
		}
    }

    return sqrt(somme);
}

bool comparePairsEuclide(const pair<float, size_t>& left, const pair<float, size_t>& right) {
    return left.first < right.first;
}

//Function who find the nearestNeighbors of a SINGLE sample test
vector<pair<float, size_t>> KnnEuclidien::predictSingle(const FeatureVector& test) const {
    vector<pair<float, size_t>> euclideSimilarities; //tab of pair

    //Call similarity Nbsample (Size of Data test)
    for (int i = 0; i < _lazy_train.getNbSample(); ++i) {
        FeatureVector currentFeatures = _lazy_train[i].getFeatures();
        float similarityValue = similarity(test, currentFeatures);
        int tag = _lazy_train[i].getTag();
        euclideSimilarities.push_back(make_pair(similarityValue, tag));
    }

    // Tri des similarités dans l'ordre décroissant en utilisant la fonction de comparaison
    sort(euclideSimilarities.begin(), euclideSimilarities.end(), comparePairsEuclide);

    return euclideSimilarities;
}