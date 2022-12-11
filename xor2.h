#ifndef _XOR_H_
#define _XOR_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "blocs.h"

using namespace std;

class xor2 : public bloc {
  public :
    xor2(string nom);
    ~xor2();
    bool in1, in2;
    bool *out;
    bool firstUse, alreadyDest;
    void calculate();
    void calculate(bool& out);
    void setDest(bool *dest);
    bool* getAdr();
};
#endif
