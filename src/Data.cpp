#include "Data.h"
#include <fstream>

using namespace std;

/*-------Définittion des constructeurs et destructeur------*/
Data::Data() {}
Data::Data(string path, bool donneeApprentissage)
{
	ifstream file(path); //ouverture du fichier

    if(!file.is_open())
    {
        throw ifstream::failure("Failed to open file");
    }

	file >> _nb_sample;
	file >> _nb_features;

	for (int i = 0; i < _nb_sample; i++)
	{
		Sample line;
        int nb_tours=_nb_features;

        if(!donneeApprentissage)
        {
            line.tag(-1);
        }

		for (int j = 0; j < nb_tours; j++)
		{

			float temp;

			if (j == 0 && donneeApprentissage)
			{
				file >> temp;
				line.tag(temp);

				//il faut faire un tour en plus lorsque le tag de la ligne est present
				nb_tours++;
			}
			else {
				file >> temp;
				line.features(temp);

			}
			
		}
		_data.push_back(line);
	}
}
/*-------Définittion des constructeurs et destructeur------*/

void Data::displayData() const {

    cout<<"Nombre d'échantillon"<<_nb_sample<<"\n"<<endl;
    cout<<"Nombre de caratéristiques par échantillon"<<_nb_features<<"\n"<<endl;

    for(const Sample& element : _data)
    {
        cout<<"********************************************************"<<endl;
        element.displaySample();
    }

}

/*------------Définittion des opérateurs-------------*/

Sample Data::operator[](unsigned int index) const 
{

    if (index < _data.size())
    {
        return _data[index];
    }
    else
    {
        throw out_of_range("Index is too big for operator [] of class Data");
    }

}

/*
const std::vector<float>& Data::aspirelesdonnees() const {

    std::vector<float> featuresArray;

    for (const Sample& sample : _data) {
        const std::vector<float>& sampleFeatures = sample.getFeatures().getVector();
        featuresArray.insert(featuresArray.end(), sampleFeatures.begin(), sampleFeatures.end());
    }

    return featuresArray;
}
*/