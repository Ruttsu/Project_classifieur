#include "Sample.h"

/*------------Définittion des méthodes---------------*/
void Sample::tag(int t) {
	_tag = t;
}

//utile pour lucas dans stockage des datas de learning
void Sample::features(float f) {
	_features.addFeatures(f);
}

void Sample::displaySample() const {
    cout << "Le tag est : " << _tag << endl;
    _features.displayFeatureVector();
}