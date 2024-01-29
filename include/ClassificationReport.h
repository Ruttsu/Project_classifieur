

#ifndef PROJETCLASSIFIEUR_CLASSIFICATIONREPORT_H
#define PROJETCLASSIFIEUR_CLASSIFICATIONREPORT_H

/*---------------------------------------------------------------------------
*
* Création L.GUYOT
* La class ClassificationReport est une classe permettant de comparer une liste
de prédictions avec une liste d’étiquettes connues pour évaluer la performance du
classifier, elle les compare et calcule le pourcentage de réussite ainsi que la
matrice de confusion.
*
*----------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class ClassificationReport{

private:
    int _tab_confusion[10][10]={};

public:

    /*------------Définittion des méthodes---------------*/
    void displayTabConfusion()const;
    void setTabConfusion(int index_prediction, int index_reality);
    int getTabConfusion(int index_prediction, int index_reality);
    void displayReport(vector<pair<int, int>> prediction);
    
};

inline int ClassificationReport::getTabConfusion(int index_prediction, int index_reality) {
    return _tab_confusion[index_prediction][index_reality];
}


#endif //PROJETCLASSIFIEUR_CLASSIFICATIONREPORT_H
