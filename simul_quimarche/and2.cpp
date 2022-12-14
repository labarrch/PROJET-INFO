#include "and2.h"

using namespace std;

and2 & and2::operator = (const and2 & copie)
{
    // pour éviter l'autoaffectation : P = P
    if (this == & copie) return *this;

    name = copie.name;
    in1 = copie.in1;
    in2 = copie.in2;
    if (copie.alreadyDest)
    {
      out = copie.out;
    }
    return *this;
}

and2::and2(string nom){
  name = nom;
  in1 = false;
  in2 = false;
  type = "function";

}

int and2::calculate(){
  for(int i=0; i<point_number; i++){
      *out[i] = in1 & in2;
  }
        return 0;
}

void and2::setDest(bool* dest){
  out.push_back(dest);
  point_number++;
}
bool* and2::getAdr(){
  if(firstUse==false){
    firstUse=true;
    return &in1;
  }
  else{
    full = true;
    return &in2;
  }
}
