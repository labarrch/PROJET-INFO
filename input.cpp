#include "input.h"

using namespace std;


input &input::operator = (const input & copie)
{
    // pour éviter l'autoaffectation : P = P
    if (this == & copie) return *this;

    name = copie.name;
    if (netValue){
      netValue = copie.netValue;
    }
    return *this;
}

input::input(string nom){
  name = nom;
  type = "input";
}


void input::setVal(bool val){
  *netValue = val;
}


input::input(string nom, bool& adrSuiv, bool value){
    name = nom;
  type = "input";
  netValue = &adrSuiv;
  *netValue = value;
}

input::input(string nom, bool& adrSuiv){
    name = nom;
  type = "input";
  netValue = &adrSuiv;
}

void input::setDest(bool* dest){
  netValue = dest;
}
