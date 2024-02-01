// KnnCosine.cpp
#include "Knncosine.h"


using namespace std;

// Constructeur avec les datas en argument
KnnCosine::KnnCosine(const Data& trainingData) : Knn(trainingData) {} // Initialisation via constru de Knn

float KnnCosine::similarity(const FeatureVector& test, const FeatureVector& data) const {
    if (test.getSize() != data.getSize()) {
        // Les vecteurs doivent avoir la même taille
        throw invalid_argument("Les vecteurs doivent avoir la même taille."); //TODO a catch
    }

    float result = 0;
    float normTest = test.getNorme();
    float normData = data.getNorme();

    if (normTest != 0 && normData != 0) {
        for (int i = 0; i < test.getSize(); i++) {
            result += test[i] * data[i];
        }
        result /= normTest * normData;
    }

    return result;
}

bool comparePairsCosine(const pair<float, size_t>& left, const pair<float, size_t>& right) {
    return left.first > right.first;
}

//Function who find the nearestNeighbors of a SINGLE sample test
vector<pair<float, size_t>> KnnCosine::predictSingle(const FeatureVector& test) const {
    vector<pair<float, size_t>> cosineSimilarities; //tab of pair

    //Call similarity Nbsample (Size of Data test)
    for (int i = 0; i < _lazy_train.getNbSample(); ++i) {
        FeatureVector currentFeatures = _lazy_train[i].getFeatures();
        float similarityValue = similarity(test, currentFeatures);
        int tag = _lazy_train[i].getTag();
        cosineSimilarities.push_back(make_pair(similarityValue, tag));
    }

    // Tri des similarités dans l'ordre décroissant en utilisant la fonction de comparaison
    sort(cosineSimilarities.begin(), cosineSimilarities.end(), comparePairsCosine);

    return cosineSimilarities;
}