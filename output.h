#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "blocs.h"

using namespace std;

class output : public bloc {

public :
  output(string nom);
  output(){};
  ~output(){};
  bool netValue;
  bool* getAdr();
  output &operator =(const output& copie);

};
#endif
