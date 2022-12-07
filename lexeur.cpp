#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int lineProcess(string line, vector<string>& list);
int lineProcessJson(string line, vector<string>& list);
int characAlpha(string charac);
int characSymb(string charac);
int characAlphaJson(string charac);
int characSymbJson(string charac);


int main (){

	string line;
	ifstream dotFile;
	ifstream jsonFile;
	int i = 0, lineCount=0;

	vector<string> lChainDot;
	vector<string> lChainJson;

	dotFile.open("dotFile.txt",ios::in);
	jsonFile.open("jsonFile.txt",ios::in);

	if(dotFile){
		while (getline(dotFile, line)){
			lineCount++;
			if(lineProcess(line, lChainDot)){
				cout << "Lexage ligne "<<lineCount<<" terminé" << endl;
			}
			else{
				cout<<"Erreur de syntaxe à la ligne "<<lineCount<<endl<<"Fin de Lexage"<<endl;;
				return 1;
			}
		}
	}

	else{
		cout << "Erreur fichier" << endl;
		return 1;
	}




	lineCount = 0;



	if(jsonFile){
		while (getline(jsonFile, line)){
			lineCount++;
			if(lineProcessJson(line, lChainJson)){
				cout << "Lexage ligne "<<lineCount<<" terminé" << endl;
			}
			else{
				cout<<"Erreur de syntaxe à la ligne "<<lineCount<<endl<<"Fin de lexage"<<endl;;
				return 1;
			}
		}
	}

	else{
		cout << "Erreur fichier" << endl;
		return 1;
	}

for (i=0; i<lChainDot.size(); i++){
	cout << lChainDot[i] << endl;
}

for (i=0; i<lChainJson.size(); i++){
	cout << lChainJson[i] << endl;
}

 dotFile.close();
 jsonFile.close();


return 0;
}

int lineProcess(string line, vector<string>& list){
		string buf;
		string car;

		int i=0;

		while (line[i]){
			car = line[i];
			if(characAlpha(car)){
				buf += line[i];
				if (i==line.length()-1){
					list.push_back(buf);
					buf.erase();
				}
			}
			else if(line[i]==' '){
				if(buf.length()){
					list.push_back(buf);
				}
				buf.erase();
			}
			else if(characSymb(car)){
				if(buf.length()){
					list.push_back(buf);
				}
				buf.erase();
				buf += line[i];
				list.push_back(buf);
				buf.erase();
			}
			else if(line[i]=='-'&&line[i+1]=='>'){
				if(buf.length()){
					list.push_back(buf);
				}
				buf.erase();
				buf = line[i];
				buf += line[i+1];
				list.push_back(buf);
				buf.erase();
				i++;
			}
			else{
				return 0;
			}
			i++;
		}
	return 1;
}
int lineProcessJson(string line, vector<string>& list){
		string buf;
		string car;
		int i=0;

		while (line[i]){
			car = line[i];
			if(characAlphaJson(car)){
				buf += line[i];
				if (i==line.length()-1){
					list.push_back(buf);
					buf.erase();
				}
			}
			else if(line[i]==' '){
				if(buf.length()){
					list.push_back(buf);
				}
				buf.erase();
			}
			else if(characSymbJson(car)){
				if(buf.length()){
					list.push_back(buf);
				}
				buf.erase();
				buf += line[i];
				list.push_back(buf);
				buf.erase();
			}
			else{
				return 0;
			}
			i++;
		}
	return 1;
}


int characAlpha(string charac){
	string buf;
	ifstream alphabet;

	alphabet.open("alphabet.txt",ios::in);

	while(getline(alphabet, buf)){
		if(buf==charac){
			alphabet.close();
			return 1;
			}
	}
	alphabet.close();
	return 0;
}

int characSymb(string charac){
	string buf;
	ifstream symboles;

	symboles.open("symboles.txt",ios::in);

	while(getline(symboles, buf)){
		if(buf==charac){
			symboles.close();
			return 1;
			}
	}
	symboles.close();
	return 0;
}
int characAlphaJson(string charac){
	string buf;
	ifstream alphabet_json;

	alphabet_json.open("alphabetj.txt",ios::in);

	while(getline(alphabet_json, buf)){
		if(buf==charac){
			alphabet_json.close();
			return 1;
			}
	}
	alphabet_json.close();
	return 0;
}

int characSymbJson(string charac){
	string buf;
	ifstream symboles_json;

	symboles_json.open("symbolesj.txt",ios::in);

	while(getline(symboles_json, buf)){
		if(buf==charac){
			return 1;
			}
	}

	return 0;
}
