#include "ClassificationReport.h"

/*-------Définittion des constructeurs et destructeur------*/

ClassificationReport::ClassificationReport(Data& d)
{
    _nbTags=d.getNbTags();
    _tab_confusion.resize(_nbTags, vector<int>(_nbTags, 0));

    _ok=0;
    _nok=0;
}

/*------------Définittion des méthodes---------------*/

void ClassificationReport::displayTabConfusion() const {
    cout<<"Prediction / Reality"<<endl;
    cout << "     ";
    for (int i = 0; i < _nbTags; i++) {
        cout << setw(4) << i;
    }
    cout << endl << endl;

    for(int i=0; i<_nbTags; i++)
    {
        cout<<i<<"    ";

        for(int j=0; j<_nbTags; j++)
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

    for(int k=1; k<maxk; k++)
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

    _tab_confusion.assign(_nbTags, vector<int>(_nbTags, 0)); //verifier que ca remet tout a 0
    _ok = 0;
    _nok = 0;
    _goodPrediction = 0.0;
}
