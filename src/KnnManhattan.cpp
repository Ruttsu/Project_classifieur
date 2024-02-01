#include "KnnManhattan.h"

KnnManhattan::KnnManhattan(const Data& trainingData) : Knn(trainingData) {} // Initialisation via constru de Knn
KnnManhattan::~KnnManhattan() {}


float KnnManhattan::similarity(const FeatureVector& test, const FeatureVector& data) const {
    
    float somme = 0;
	if (test.getSize() != data.getSize()) {
        throw invalid_argument("Les vecteurs doivent avoir la même taille."); //TODO a catch
	} else {
        for (int i = 0; i<test.getSize(); i++) {
			somme += abs(data.getVector()[i] - test.getVector()[i]);
		}
    }

    return somme;
}

bool comparePairsManhattan(const pair<float, size_t>& left, const pair<float, size_t>& right) {
    return left.first < right.first;
}


vector<pair<float, size_t>> KnnManhattan::predictSingle(const FeatureVector& test) const {
    vector<pair<float, size_t>> manhattanSimilarities;


    for (int i = 0; i < _lazy_train.getNbSample(); ++i) {
        FeatureVector currentFeatures = _lazy_train[i].getFeatures();
        float similarityValue = similarity(test, currentFeatures);
        int tag = _lazy_train[i].getTag();
        manhattanSimilarities.push_back(make_pair(similarityValue, tag));
    }

    sort(manhattanSimilarities.begin(), manhattanSimilarities.end(), comparePairsManhattan);

    return manhattanSimilarities;
}