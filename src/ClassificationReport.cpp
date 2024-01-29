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

    _goodPrediction = static_cast<float>(static_cast<float>(_ok) / static_cast<float>(_nok + _ok)*100);

}

void ClassificationReport::displayReport() const {

    displayTabConfusion();

    cout<<endl;
    cout<<"Voici le nombre de bonne prediction : "<<_ok<<endl;
    cout<<"Voici le nombre de mauvaise prediction : "<<_nok<<endl;

    cout<<"Voici le pourcentage de bonne prediction : " << _goodPrediction<<"%"<<endl;


}

void ClassificationReport::generationExcel(Knn& train, const Data& test,const int maxk) {

    ofstream csvFile("resultCSV");

    if (!csvFile.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier CSV." << endl;
        return;
    }

    csvFile << "K,Good Prediction\n";

    vector<float> result;

    for(int k=0; k<maxk; k++)
    {
        train.predict(test, k);
        setTabConfusion(train);
        result.push_back(_goodPrediction);


        // Écrire les résultats dans le fichier CSV
        csvFile << k << "," << result.back() << "\n";
    }

    csvFile.close();
}

void ClassificationReport::resetVariable() {

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            _tab_confusion[i][j] = 0;
        }
    }

    _nbTags = 0;
    _ok = 0;
    _nok = 0;
    _goodPrediction = 0.0;
}
