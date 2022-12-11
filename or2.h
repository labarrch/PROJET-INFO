#ifndef _OR2_H_
#define _OR2_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "blocs.h"

using namespace std;

class or2 : public bloc {
  public :
    or2(string nom);
    ~or2();
    bool in1, in2;
    bool *out;
    bool firstUse, alreadyDest;
    void calculate();
    void calculate(bool& out);
    void setDest(bool *dest);
    bool* getAdr();
};
#endif