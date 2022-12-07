#include "blocs.h"
#include <iostream>
#include <string>
#include <string.h>
#include "and2.h"

and2::and2(string nom){
    name = nom;
  type = "function";
  firstUse = false;
}
and2::~and2(){
}
void and2::calculate(bool& out){
    out = in1&in2;
}

void and2::setDest(bool& dest){
  out = &dest;
}
bool* and2::getAdr(){
  if(firstUse==false){
    firstUse=true;
    return &in1;
  }
  else{
    return &in2;
  }
}
