#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void ajouter(int chaine, vector<int> &test);

int main(){

  //vector<string> test {"tcharoul", "labarrch", "leconmat"};
  vector<int> test;

  test.push_back(1);
  test.push_back(2);
  test.push_back(3);
  ajouter(5, test);

  cout << test[3] << endl;

  return 0;
}

void ajouter(int chaine, vector<int> &test){

  test.push_back(chaine);

}
