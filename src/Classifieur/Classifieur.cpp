// Classifieur.cpp : définit le point d'entrée de l'application.
//

#include "Classifieur.h"
#include "Data.h"

using namespace std;

int main()
{
    Data test("D:/Cours/INSA/Cpp/ProjetClassifieur/digits.svm", 1);

    test.displayData();

    cout << "fini" << endl;
	return 0;
}
