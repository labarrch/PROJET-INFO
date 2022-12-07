#include <string>
#include <string.h>
#include <iostream>

class bloc{
  public :
    string name;
    string type;

    bloc();
    ~bloc();

    virtual void setDest(bool &dest);
    virtual bool* getAdr();
};
