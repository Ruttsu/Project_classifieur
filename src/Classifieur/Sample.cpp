#include "Sample.h"

void Sample::tag(int t) {
	_tag = t;
}

void Sample::features(float f) {
	_features.addFeatures(f);
}