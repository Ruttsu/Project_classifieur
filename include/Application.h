/*---------------------------------------------------------------------------
*
* Cr�ation Lucas.G
*
*L�objet Application possèdent une seul fonction run qui permet de dérouler
séquentiellement les étapes pour la prédiction. Elle est adapté pour la prédiction
de sample non connu mais aussi pour des sample connu et alors on peut connaître
la performance de notre classifieur.
*
*----------------------------------------------------------------------------*/

#ifndef PROJETCLASSIFIEUR_APPLICATION_H
#define PROJETCLASSIFIEUR_APPLICATION_H


#include "Data.h"
#include "Knncosine.h"
#include "KnnEuclidien.h"
#include "KnnManhattan.h"
#include "ClassificationReport.h"
#include <cstdlib>

class Application
{
public:
    void run();
};



#endif //PROJETCLASSIFIEUR_APPLICATION_H
