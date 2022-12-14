#include "lexeur_d.h"

using namespace std;

int characAlpha(const string charac){
	string buf;
	ifstream alphabet;

	alphabet.open("lex_grammar/alphabet.txt",ios::in);

	while(getline(alphabet, buf)){
		if(buf==charac){
			alphabet.close();
			return 1;
			}
	}
	alphabet.close();
	return 0;
}
int characSymb(const string charac){
	string buf;
	ifstream symboles;

	symboles.open("lex_grammar/symboles.txt",ios::in);

	while(getline(symboles, buf)){
		if(buf==charac){
			symboles.close();
			return 1;
			}
	}
	symboles.close();
	return 0;
}
int characAlphaJson(const string charac){
	string buf;
	ifstream alphabet_json;

	alphabet_json.open("lex_grammar/alphabetj.txt",ios::in);

	while(getline(alphabet_json, buf)){
		if(buf==charac){
			alphabet_json.close();
			return 1;
			}
	}
	alphabet_json.close();
	return 0;
}
int characSymbJson(const string charac){
	string buf;
	ifstream symboles_json;

	symboles_json.open("lex_grammar/symbolesj.txt",ios::in);

	while(getline(symboles_json, buf)){
		if(buf==charac){
			return 1;
			}
	}

	return 0;
}
int characWaveJson(const string charac){
	string buf;
	ifstream wave_json;

	wave_json.open("lex_grammar/wavej.txt",ios::in);

	while(getline(wave_json, buf)){
		if(buf==charac){
			return 1;
			}
	}

	return 0;

}

int lineProcess(const string line, vector<string>& list){
		string buf;
		string car;

		int i=0;
		bool labelName=false;

		while (line[i]){
			car = line[i];
			if(labelName==true&&line[i]!='"'){
			 buf += line[i];
			}
			else if(characAlpha(car)){
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
			else if(line[i]=='"'){
				if(buf.length()){
					list.push_back(buf);
				}
				buf.erase();
				buf += line[i];
				list.push_back(buf);
				buf.erase();
				if(labelName==false){
					labelName=true;
				}
				else{
					labelName=false;
				}

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
int lineProcessJson(const string line, vector<string>& list, int lineCount){
		string buf;
		string car;

		int i=0;
		bool labelName=false;
		bool waveDefine=false;

		while (line[i]){
			car = line[i];
			if((labelName&&line[i]!='"')&&(labelName&&line[i]!=39)){
				cout<<"écriture entre guillemets"<<line[i]<<endl;
				if (list[list.size()-3]=="name"){
					buf += line[i];
				}
			}
			else if(waveDefine&&characWaveJson(car)){
				if (list[list.size()-3]=="wave"){
					buf += line[i];
				}
			}
			else if(characAlphaJson(car)){
				buf += line[i];
				if (i==line.length()-1){
					list.push_back(buf);
					buf.erase();
				}
			}
			else if(!waveDefine&&line[i]==' '){
				if(buf.length()){
					list.push_back(buf);
				}
				buf.erase();
			}
			else if(waveDefine&&line[i]==' '){
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

			else if(line[i]=='"'||line[i]==39){
				cout<<"ouverture guillemets"<<endl;
				if(buf.length()){
					list.push_back(buf);
				}
				else{
				}

				buf.erase();
				buf += line[i];
				list.push_back(buf);
				buf.erase();

				if(list[list.size()-3]=="name"||list[list.size()-5]=="name"){
						if(!labelName){
							labelName=true;
						}
						else{
							labelName=false;
						}
				}
				else if(list[list.size()-3]=="wave"||list[list.size()-5]=="wave"){
						if(!waveDefine){
							waveDefine=true;
						}
						else{
							waveDefine=false;
						}
				}
				else{
					return 0;
				}

			}
			else{
				return 0;
			}
			i++;
		}
	return 1;
}

int lexeur(const char* fichierDot, const char* fichierJson, vector<string>& lChainDot, vector<string>& lChainJson){

	string line;
	int i = 0, lineCount=0;

  ifstream dotFile;
  ifstream jsonFile;

  dotFile.open(fichierDot,ios::in);
  jsonFile.open(fichierJson,ios::in);

	if(dotFile){
		while (getline(dotFile, line)){
			lineCount++;
			if(lineProcess(line, lChainDot)){
				cout << "DOT/Lexage ligne "<<lineCount<<" terminé" << endl;
			}
			else{
				cout<<"DOT/Erreur de syntaxe à la ligne "<<lineCount<<endl<<"Fin de Lexage"<<endl;
				return 1;
			}
		}
	}

	else{
		cout << "Erreur : fichier dot illisible ou inexistant" << endl;
		return 1;
	}

	cout << "Lexage dot terminé"<<endl;

	lineCount = 0;

	if(jsonFile){
		while (getline(jsonFile, line)){
			lineCount++;
			if(lineProcessJson(line, lChainJson, lineCount)){
				cout << "JSON/Lexage ligne "<<lineCount<<" terminé" << endl;
			}
			else{
				cout<<"JSON/Erreur de syntaxe à la ligne "<<lineCount<<endl<<"Fin de lexage"<<endl;;
				return 1;
			}
		}
	}

	else{
		cout << "Erreur : fichier json illisible ou inexistant" << endl;
		return 1;
	}

cout << "Lexage json terminé"<<endl;

 dotFile.close();
 jsonFile.close();

cout<<"Lexage terminé"<<endl;
return 0;
}

void lectureChaine(vector<string>& chaine){
	for(int i=0; i<chaine.size();i++){  //lecture de lChainJson
	  cout << chaine[i] << endl;
	}
}
