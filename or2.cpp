#include "blocs.h"
#include <iostream>
#include <string>
#include <string.h>
#include "or2.h"

or2::or2(string nom){
  name = nom;
  type = "function";
  firstUse = false;
}
or2::~or2(){
}

void or2::calculate(bool& out){
    out = in1|in2;
}

void or2::setDest(bool& dest){
  out = &dest;
}

bool* or2::getAdr(){
  if(firstUse==false){
    firstUse=true;
    return &in1;
  }
  else{
    return &in2;
  }
}
