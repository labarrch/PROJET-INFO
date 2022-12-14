#ifndef _OBJET_H_
#define _OBJET_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class objet
{
  friend class clist;
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
