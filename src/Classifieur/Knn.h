#ifndef KNN_H
#define KNN_H
#pragma once

/*-------------------------------
Classe Virtuel qui sert à rien
donc j'ai eu la flemme pour l'instant
--------------------------------*/

#include <iostream>
#include <vector>
#include <cmath>

#include "FeatureVector.h"

using namespace std;

class Knn {
public:
    Knn();
    ~Knn();

    int predict();

protected:
    int getKnn();
    virtual float predictSingle() = 0;
    virtual float similarity(FeatureVector test, FeatureVector data) = 0;

};

#endif