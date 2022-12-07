#include "input.h"

input::input(string nom){
    name = nom;
  type = "input";
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

input::~input(){
}

void input::setDest(bool &dest){
  this->netValue = &dest;
}
