#ifndef _OBJET_H_
#define _OBJET_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "list.h"
#include "input.h"
#include "output.h"
#include "and2.h"
#include "or2.h"
#include "xor2.h"

using namespace std;

class objet
{
public :

  objet(input *o);
  objet(output *o);
  objet(and2 *o);
  objet(or2 *o);
  objet(xor2 *o);

  int type;

   input* pointi;
   output* pointo;
   and2* pointa;
   or2* pointor;
   xor2* pointxor;
   objet* next;        // L'adresse du suivant.

};
#endif
