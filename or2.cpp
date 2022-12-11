#include "or2.h"

using namespace std;

or2::or2(string nom){
  name = nom;
  in1 = false;
  in2 = false;
  type = "function";
  firstUse = false;
  alreadyDest=false;
}
or2::~or2(){
}

void or2::calculate(bool& out){
    out = in1|in2;
}

void or2::calculate(){
    *out = in1|in2;
}

void or2::setDest(bool* dest){
  alreadyDest=true;
  out = dest;
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