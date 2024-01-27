#include "../include/ClassificationReport.h"


/*------------Définittion des méthodes---------------*/

void ClassificationReport::displayTabConfusion() const {
    cout<<"Prediction / Reality"<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<"             ";
        for(int j=0; j<10; j++)
        {
            cout<<setw(4)<<_tab_confusion[i][j]; //setw permet que les lignes restent alignées
        }
        cout<<endl;
    }
}

void ClassificationReport::setTabConfusion(vector<pair<int, int>> prediction) {

    for( const auto& predicted : prediction)
    {
        _tab_confusion[predicted.first][predicted.second]++;
    }


}

void ClassificationReport::displayReport() {

    displayTabConfusion();
}