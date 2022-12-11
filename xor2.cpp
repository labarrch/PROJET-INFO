#include "xor2.h"

using namespace std;

xor2::xor2(string nom){
  name = nom;
  in1 = false;
  in2 = false;
  type = "function";
  firstUse = false;
  alreadyDest=false;
}
xor2::~xor2(){
}

void xor2::calculate(bool& out){
    out = (in1|in2)&!(in1&in2);
}

void xor2::calculate(){
    *out = in1|in2;
}

void xor2::setDest(bool* dest){
  alreadyDest=true;
  out = dest;
}

bool* xor2::getAdr(){
  if(firstUse==false){
    firstUse=true;
    return &in1;
  }
  else{
    return &in2;
  }
}
