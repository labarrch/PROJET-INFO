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
    or2(){};
    ~or2();
    bool in1, in2;
    vector<bool *>out;
    bool firstUse=false, alreadyDest=false, full=false;
    int point_number=0;
    or2 &operator =(const or2& copie);
    int calculate();
    void setDest(bool *dest);
    bool* getAdr();
};
#endif
