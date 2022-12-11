#include "output.h"

using namespace std;

output::output(string nom){
  name = nom;
  netValue = false;
  type = "output";
}
output::~output(){
}

bool* output::getAdr(){
  return &netValue;

}