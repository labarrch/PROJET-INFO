#include "and2.h"

using namespace std;


and2::and2(string nom){
  name = nom;
  in1 = false;
  in2 = false;
  type = "function";
  firstUse = false;
  alreadyDest=false;
}
and2::~and2(){
}
void and2::calculate(bool& out){
    out = in1&in2;
}
void and2::calculate(){
    *out = in1&in2;
}


void and2::setDest(bool* dest){
  alreadyDest=true;
  out = dest;
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