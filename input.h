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
  input(string nom, bool& adrSuiv, bool value);
  input(string nom, bool& adrSuiv);
  input(string nom);
  input(){};
  ~input(){};
  input &operator =(const input& copie);
  bool *netValue;
  void setDest(bool* dest);
  void setVal(bool val);
};

#endif
