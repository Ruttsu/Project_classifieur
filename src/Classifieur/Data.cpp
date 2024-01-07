#include "Data.h"
#include <fstream>

using namespace std;

Data::Data() {}

Data::Data(string path)
{
	ifstream file(path); //ouverture du fichier

	//faire la v�rif de l'ouverture du fichier

	file >> _nb_sample;
	file >> _nb_features;

	for (int i = 0; i < _nb_sample; i++)
	{
		Sample line;

		for (int j = 0; j <= _nb_features; j++)
		{
			
			float temp;
			
			if (j == 0 /*&& echantillon connu*/)
			{
				file >> temp;
				line.tag(temp);
			}
			else {
				file >> temp;
				line.features(temp);

			}
			
		}
		_data.push_back(line);
	}
}