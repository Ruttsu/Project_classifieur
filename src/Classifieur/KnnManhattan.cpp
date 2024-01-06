#include "KnnManhattan.h"

KnnManhattan::KnnManhattan() {}
KnnManhattan::~KnnManhattan() {}


float KnnManhattan::similarity(FeatureVector test, FeatureVector data) {

    float somme = 0;
	if (test.getSize() == data.getSize()) {
		for (int i = 0; i<test.getSize(); i++) {
			somme += abs(data._vector[i] - test._vector[i]);
		}
	}

    return somme;
}