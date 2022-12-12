#include "lexeur_d.cpp"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
  vector<string> lChainDot;
  vector<string> lChainJson;
  const char* dot;
  const char* json;
  for(int i=1; i<=2*argc; i=i2){
    dot = argv[i];
    json = argv[i+1];
    cout<<"Test "<<i<<" :"<<endl;
    lexeur(dot,json,lChainDot, lChainJson);
    for(int i=0; i<lChainDot;i++){  //lecture lChainDot
      cout << lChainDot[i] << endl;
    }
    for(int i=0; i<lChainJson;i++){  //lecture de lChainJson
      cout << lChainJson[i] << endl;
    }
  }

}
