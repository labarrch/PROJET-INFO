#include "or2.h"

using namespace std;

or2 & or2::operator = (const or2 & copie)
{
    // pour éviter l'autoaffectation : P = P
    if (this == & copie) return *this;

    name = copie.name;
    in1 = copie.in1;
    in2 = copie.in2;
    if (copie.alreadyDest){
      out = copie.out;
    }
    return *this;
}


or2::or2(string nom){
  name = nom;
  in1 = false;
  in2 = false;
  type = "function";
}
or2::~or2(){
}

int or2::calculate(){
  for(int i=0; i<point_number; i++){
      *out[i] = in1 | in2;
  }
        return 0;
}

void or2::setDest(bool* dest){
  out.push_back(dest);
  point_number++;
}
bool* or2::getAdr(){
  if(firstUse==false){
    firstUse=true;
    return &in1;
  }
  else{
    full = true;
    return &in2;
  }
}
