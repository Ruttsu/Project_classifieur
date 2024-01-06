#include "KnnEuclidien.h"

KnnEuclidien::KnnEuclidien() {}
KnnEuclidien::~KnnEuclidien() {}


float KnnEuclidien::similarity(FeatureVector test, FeatureVector data) {

    float somme = 0;
	if (test.getSize() == data.getSize()) {
		for (int i = 0; i<test.getSize(); i++) {
			somme += pow(data._vector[i] - test._vector[i],2);
		}
	}

    return sqrt(somme);
}