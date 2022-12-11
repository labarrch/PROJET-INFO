#ifndef _AND2_H_
#define _AND2_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "blocs.h"

using namespace std;

class and2 : public bloc {
  public :
    and2(string nom);
    ~and2();
    bool in1, in2;
    bool *out;
    bool firstUse, alreadyDest;
    void calculate(bool& out);
    void calculate();
    void setDest(bool* dest);
    bool* getAdr();
};
#endif