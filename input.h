#include "blocs.h"
#include <iostream>
#include <string>
#include <string.h>

class input : public bloc {
  public :
  input(string nom, bool& adrSuiv, bool value);
  input(string nom, bool& adrSuiv);
  input(string nom);
  ~input();
  bool *netValue;
  void setDest(bool &dest);
};
