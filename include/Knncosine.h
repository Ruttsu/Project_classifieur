#ifndef KNN_COSINE_H
#define KNN_COSINE_H
#pragma once

#include "Knn.h"

/*---------------------------------------------------------------------------
*
* Cr�ation
*
*L�objet KnnCosine est une classe fille de la classe Knn. ELle permet de calculer
les plus proches voisins en utilisant une similarité Cosine (calcul de distance).
*
*----------------------------------------------------------------------------*/

class KnnCosine : public Knn {
public:
    KnnCosine(const Data& trainingData);

    virtual vector<pair<float, size_t>> predictSingle(const FeatureVector& test) const override; // I : Feature and int | O : Vector of <double, unsigned int>
    virtual float similarity(const FeatureVector& test, const FeatureVector& data) const override; // Compare 2 featurevector, return float (value of similarity)    
};

#endif // KNN_COSINE_H

