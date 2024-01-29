// Classifieur.cpp : définit le point d'entrée de l'application.

#include "../include/Classifieur.h"
#include "../include/Data.h"
#include "../include/FeatureVector.h"
#include "../include/KnnEuclidien.h"
#include "../include/KnnManhattan.h"
#include "../include/Knncosine.h"
#include "../include/ClassificationReport.h"
#include "../include/Application.h"


using namespace std;

int main() {

    Application app;
    app.run();

	return 0;
}
