#include "KnnManhattan.h"

KnnManhattan::KnnManhattan(): Knn() {}
KnnManhattan::~KnnManhattan() {}


float KnnManhattan::similarity(Sample test, Sample data) {

    float somme = 0;
	if (test.getSize() == data.getSize()) {
		for (int i = 0; i<test.getSize(); i++) {
			somme += abs(data._vector[i] - test._vector[i]);
		}
	}

    return somme;
}

float KnnManhattan::predictSingle() {
	return 0;
}