#include "KnnEuclidien.h"

KnnEuclidien::KnnEuclidien(): Knn() {}
KnnEuclidien::~KnnEuclidien() {}


float KnnEuclidien::similarity(Sample test, Sample data) const {
	cout << "Size Euclide : " << data.getSize() <<endl;
    float somme = 0;
	if (test.getSize() == data.getSize()) {
		for (int i = 0; i<test.getSize(); i++) {
			somme += pow(data._vector[i] - test._vector[i],2);
		}
	}

    return sqrt(somme);
}

float  KnnEuclidien::predictSingle() const {
	return 0;
}