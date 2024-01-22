#include "Sample.h"

Sample::Sample(): FeatureVector() {}

Sample::Sample(int tag, initializer_list<float> args) : FeatureVector(args), _tag(tag) {
    for (float a: args) {
        features(a);
    }
}

/*------------Définittion des méthodes---------------*/
void Sample::tag(int t) {
	_tag = t;
}

void Sample::features(float f) {
	_features.addFeatures(f);
}

void Sample::displaySample() const {
    cout << "Le tag est : " << _tag << endl;
    _features.displayFeatureVector();
}