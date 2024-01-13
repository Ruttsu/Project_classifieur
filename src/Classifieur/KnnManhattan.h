#ifndef KNNMANHATTAN_H
#define KNNMANHATTAN_H
#pragma once

/*----------------------------------------------------
Classe qui permet de mesurer la similarité selon la méthode de Manhattan.
Il existe d'autre méthode (Euclidienne, Minkowski et Tchebichev) 

Pour l'instant à utiliser sur FeatureVector/Sample (et à la venir sur Data ? puisque Knn est abstraite)

-similiraty : calcul la distance entre deux vecteur -> retour un float
    -> à faire entre le teste et tout les datas puis le plus petit score = le plus proche voisin pour k=1
------------------------------------------------------*/

#include "Knn.h"

class KnnManhattan: protected Knn {
public:
    KnnManhattan();
    ~KnnManhattan();

    virtual float predictSingle() const override;
    virtual float similarity(Sample test, Sample data) const override;

};

#endif