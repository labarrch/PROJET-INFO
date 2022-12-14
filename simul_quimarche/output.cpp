#include "output.h"

using namespace std;

output & output::operator = (const output & copie)
{
    // pour éviter l'autoaffectation : P = P
    if (this == & copie) return *this;
    name = copie.name;
    netValue = copie.netValue;
    return *this;
}

output::output(string nom){
  name = nom;
  netValue = false;
  type = "output";
}

bool* output::getAdr(){
  return &netValue;

}
