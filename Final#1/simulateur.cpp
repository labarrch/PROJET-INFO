using namespace std;


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "lexeur_d.cpp"


int main(){

  vector<string> lChainDot;
  vector<string> lChainJson;

  if(lexeur(lChainDot, lChainJson)){
    cout << "fin de pgm" << endl;
  }
}
