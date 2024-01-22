#include "Sample.h"

Sample::Sample(): FeatureVector() {}

/*------------Définittion des méthodes---------------*/
void Sample::setTag(int t) {
	_tag = t;
}

void Sample::setFeatures(float f) {
	_features.addFeatures(f);
}

void Sample::displaySample() const {
    cout << "Le tag est : " << _tag << "\n" << endl;
    _features.displayFeatureVector();
}