#include <fstream>
#include <iostream>

using namespace std;

int main(){

	string buf;
	ofstream sortie;
	ifstream entree;

	sortie.open("graphe.txt",ios::out);
	entree.open("f.txt",ios::in);

	if(!sortie){

	}

	if(!entree){

	}


while (getline(entree, buf)){
	cout << buf << endl;
	sortie << buf << "\n";
}

sortie.close();
entree.close();

return 0;

}
