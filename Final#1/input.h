#ifndef _INPUT_H_
#define _INPUT_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "blocs.h"

using namespace std;

class input : public bloc {
  public :
  input(string nom);
  input(){};
  ~input(){};
  input &operator =(const input& copie);
  int point_number =0;
  vector<bool *> netValue;
  void setDest(bool* dest);
  void setVal(bool val);
};

#endif
