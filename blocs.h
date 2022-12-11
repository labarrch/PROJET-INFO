#ifndef _BLOCS_H_
#define _BLOCS_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class bloc{
  public :
    string name;
    string type;

    bloc();
    ~bloc();

    virtual void setDest(bool* dest);
    virtual void setDestTest();
    virtual bool* getAdr();
    virtual void setVal(bool val);
};
#endif