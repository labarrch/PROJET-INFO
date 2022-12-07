#include <string>
#include "output.h"
#include <iostream>

using namespace std;

output::output(string nom){
  name = nom;
  type = "output";
}
output::~output(){
}

bool* output::getAdr(){
  return &netValue;

}
