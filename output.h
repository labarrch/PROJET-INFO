#include "blocs.h"
#include <iostream>

using namespace std;

class output : public bloc {

public :
  output(string nom);
  ~output();
  bool netValue;
  bool* getAdr();
};
