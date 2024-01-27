#include "../include/ClassificationReport.h"


/*------------Définittion des méthodes---------------*/

void ClassificationReport::displayTabConfusion() const {
    cout<<"Prediction / Reality"<<endl;
    cout<<"     "<<setw(4)<<"0"<<setw(4)<<"1"<<setw(4)<<"2"<<setw(4)<<"3"<<setw(4)<<"4"<<setw(4)<<"5"<<setw(4)<<"6"<<setw(4)<<"7"<<setw(4)<<"8"<<setw(4)<<"9"<<endl<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<i;
        cout<<"    ";
        for(int j=0; j<10; j++)
        {
            cout<<setw(4)<<_tab_confusion[i][j]; //setw permet que les lignes restent alignées
        }
        cout<<endl;
    }
}

void ClassificationReport::setTabConfusion(Knn& knn) {

    _ok=0;
    _nok=0;

    for( const auto& predicted : knn.getPrediction())
    {
        _tab_confusion[predicted.first][predicted.second]++;

        if(predicted.first==predicted.second)
        {
            _ok++;
        }else
        {
            _nok++;
        }
    }
}

void ClassificationReport::displayReport() const {

    displayTabConfusion();

    cout<<endl;
    cout<<"Voici le nombre de bonne prediction : "<<_ok<<endl;
    cout<<"Voici le nombre de mauvaise prediction : "<<_nok<<endl;

    float pourcentage;
    pourcentage = static_cast<float>(static_cast<float>(_ok) / static_cast<float>(_nok + _ok)*100);


    cout<<"Voici le pourcentage de bonne prediction : " << pourcentage<<"%"<<endl;


}