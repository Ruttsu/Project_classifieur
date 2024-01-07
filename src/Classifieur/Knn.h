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

#include "Data.h"
#include "Sample.h"

using namespace std;

class Knn: public Data {
public:
    Knn();
    virtual ~Knn() = default;

    int predict();

protected:
    int getKnn();
    virtual float predictSingle() = 0;
    virtual float similarity(Sample test, Sample data) = 0;

};

#endif