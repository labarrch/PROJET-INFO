#include "blocs.h"
#include <iostream>
#include <string>
#include <string.h>

class and2 : public bloc {
  public :
    and2(string nom);
    ~and2();
    bool in1, in2;
    bool *out;
    bool firstUse;
    void calculate(bool& out);
    void setDest(bool &dest);
    bool* getAdr();
};
