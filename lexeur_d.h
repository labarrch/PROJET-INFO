#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int lineProcess(const string line, vector<string>& list); //Fonction qui traite le lexage d'une ligne de dot
int lineProcessJson(const string line, vector<string>& list);  //Fonction qui traite le lexage d'une ligne de json
int characAlpha(const string charac); //Fonction de vérifiction d'apartenance aux caractères alphanumériques autorisés en dot
int characSymb(const string charac);  //Fonction de vérifiction d'apartenance aux symboles/poncuations autorisés en dot
int characAlphaJson(const string charac);  //Fonction de vérifiction d'apartenance aux caractères alphanumériques autorisés en json
int characSymbJson(const string charac);   //Fonction de vérifiction d'apartenance aux symboles/poncuations autorisés en json
int characWaveJson(const string charac, int lineCount);   //Fonction de vérifiction d'apartenance aux symboles/poncuations autorisés en json
int lexeur(const char* fichierDot, const char* fichierJson,vector<string>& lChainDot, vector<string>& lChainJson);   //Fonction qui réalise le lexage des fichiers
void lectureChaine(vector<string>& chaine);
