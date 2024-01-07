#ifndef KNNEUCLIDIEN_H
#define KNNEUCLIDIEN_H
#pragma once

/*----------------------------------------------------
Classe qui permet de mesurer la similarité selon la méthode Euclidienne.
Il existe d'autre méthode (Manhattan, Minkowski et Tchebichev) 

Pour l'instant à utiliser sur FeatureVector/Sample (et à la venir sur Data ? puisque Knn est abstraite)

-similiraty : calcul la distance entre deux vecteur -> retour un float
    -> à faire entre le teste et tout les datas puis le plus petit score = le plus proche voisin pour k=1
------------------------------------------------------*/

#include "Knn.h"

class KnnEuclidien: protected Knn {
public:
    KnnEuclidien();
    ~KnnEuclidien();

    virtual float predictSingle() override;
    virtual float similarity(Sample test, Sample data) override;

};

#endif