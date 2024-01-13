#include "Sample.h"

Sample::Sample(): FeatureVector() {}

/*------------Définittion des méthodes---------------*/
void Sample::tag(int t) {
	_tag = t;
}

void Sample::features(float f) {
	_features.addFeatures(f);
}

void Sample::displaySample() const {
    cout << "Le tag est : " << _tag << "\n" << endl;
    _features.displayFeatureVector();
}