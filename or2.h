#include "blocs.h"
#include <iostream>
#include <string>
#include <string.h>

class or2 : public bloc {
  public :
    or2(string nom);
    ~or2();
    bool in1, in2;
    bool *out;
    bool firstUse;
    void calculate(bool& out);
    void setDest(bool &dest);
    bool* getAdr();
};
