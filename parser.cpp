using namespace std;

#include "lexeur_d.cpp"
#include "blocs.cpp"
#include "and2.cpp"
#include "or2.cpp"
#include "input.cpp"
#include "output.cpp"
#include <iostream>
#include <vector>

int main(){

    output o1("o1");

    and2 a2("a2");
    //cout << a2.name << endl;

    input i1("i1", a2.in1);
    input i2("i2", a2.in2);

    //cout << a2.in1 << endl;
    //cout << a2.in2 << endl;

    //a2.calculate(o1.netValue);

    //cout << o1.netValue << endl;

    vector<bloc> maintab[2];

    maintab[0].push_back(i1);
    maintab[0].push_back(a2);
    maintab[0].push_back(o1);
    maintab[1].push_back(i2);
    maintab[1].push_back(o1);

    int longueur = (sizeof(maintab)/sizeof(maintab[0]));
    bool *bufAdr;



    for(int i=0; i<longueur; i++){
      for(int j=0 ;j< maintab[i].size(); j++){
        cout << maintab[i][j].name<<" -> "<< maintab[i][j].type<<endl;
      }
    }

    /*for(int i=0; i<longueur; i++){
      for(int j=maintab[i].size()-1; j>0; j--){
        if (maintab[i][j].type == "output"){
          bufAdr = &maintab[i][j].netValue;
        }
        else if (maintab[i][j].type == "function"){
          maintab[i][j].out = bufAdr;
          if (maintab[i][j].in1 == NULL){
              bufAdr = &maintab[i][j].in1;
          }
          else {
              bufAdr = &maintab[i][j].in1;
          }
        }
        else if (maintab[i][j].type == "input"){
              maintab[i][j].netValue = bufAdr
        }
        }
      }
    }


/*output o1("o1");

or2 a2("a2");
cout << a2.name << endl;

input i1("i1", a2.in1, true);
input i2("i2", a2.in2, false);

cout << a2.in1 << endl;
cout << a2.in2 << endl;

a2.calculate(o1.netValue);

cout << o1.netValue << endl;
*/
}
