#include "xor2.h"

using namespace std;

xor2::xor2(string nom){
  name = nom;
  type = "function";
  firstUse = false;
  alreadyDest=false;
}
xor2::~xor2(){
}

int xor2::calculate(){
  for(int i=0; i<point_number; i++){
      *out[i] = in1 ^ in2;
  }
        return 0;
}

void xor2::setDest(bool* dest){
  out.push_back(dest);
  point_number++;
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

xor2 & xor2::operator = (const xor2 & copie){
  if(this == & copie) return *this;
  name = copie.name;
  in1 = copie.in1;
  in2 = copie.in2;
  return *this;
}
