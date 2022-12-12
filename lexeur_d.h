#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>


int lineProcess(string line, vector<string>& list);
int lineProcessJson(string line, vector<string>& list);
int characAlpha(string charac);
int characSymb(string charac);
int characAlphaJson(string charac);
int characSymbJson(string charac);
int lexeur(const char* fichierDot, const char* fichierJson,vector<string>& lChainDot, vector<string>& lChainJson);
