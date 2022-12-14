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
    ~and2(){};
    and2(){};
    bool in1, in2;
    vector<bool *>out;
    bool firstUse=false, alreadyDest=false, full=false;
    int point_number =0;
    and2 &operator =(const and2& copie);
    int calculate();
    void setDest(bool* dest);
    bool* getAdr();
};
#endif
