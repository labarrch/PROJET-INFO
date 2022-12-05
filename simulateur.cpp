#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

  vector<string> lChainDot;
  vector<string> lChainJson;

  if(lexer("dotFile.txt", "jsonFile.txt", lChainDot, lChainJson)){
    cout << "fin de pgm" << endl;
  }
}
