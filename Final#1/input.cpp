#include "input.h"

using namespace std;


input &input::operator = (const input & copie)
{
    // pour éviter l'autoaffectation : P = P
    if (this == & copie) return *this;

    name = copie.name;
    point_number = copie.point_number;
    if (copie.point_number){
      for (int i = 0; i < point_number; i++) {
        netValue.push_back(copie.netValue[i]);
      }
    }
    return *this;
}

input::input(string nom){
  name = nom;
  type = "input";
}

void input::setVal(bool val){

  for(int i=0; i<point_number; i++){
      *netValue[i] = val;
  }
}


void input::setDest(bool* dest){
  netValue.push_back(dest);
  point_number++;
}
