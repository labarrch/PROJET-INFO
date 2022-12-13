#include "or2.h"

using namespace std;

// or2::or2(string nom){
//   name = nom;
//   in1 = false;
//   in2 = false;
//   type = "function";
//   firstUse = false;
//   alreadyDest=false;
// }
// or2::~or2(){
// }
//
// void or2::calculate(bool& out){
//     out = in1|in2;
// }
//
// void or2::calculate(){
//     *out = in1|in2;
// }
//
// void or2::setDest(bool* dest){
//   alreadyDest=true;
//   out = dest;
// }
//
// bool* or2::getAdr(){
//   if(firstUse==false){
//     firstUse=true;
//     return &in1;
//   }
//   else{
//     return &in2;
//   }
// }
//
// or2 & or2::operator = (const or2 & copie){
//   if(this == & copie) return *this;
//   name = copie.name;
//   in1 = copie.in1;
//   in2 = copie.in2;
//   return *this;
// }

or2 & or2::operator = (const or2 & copie)
{
    // pour éviter l'autoaffectation : P = P
    if (this == & copie) return *this;

    name = copie.name;
    in1 = copie.in1;
    in2 = copie.in2;
    if (out){
      out = copie.out;
    }
    return *this;
}


or2::or2(string nom){
  name = nom;
  in1 = false;
  in2 = false;
  type = "function";
  firstUse = false;
  alreadyDest=false;
  full = false;
}
or2::~or2(){
}

int or2::calculate(){
        *out = in1 | in2;
        return 0;
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
    full = true;
    return &in2;
  }
}
