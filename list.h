#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "objet.h"
#include "input.h"
#include "output.h"
#include "and2.h"
#include "or2.h"
#include "xor2.h"

using namespace std;

class clist
{
  public :
    clist();
    ~clist();
    objet* adresse_position_n(int position);
    objet* premier; //Pointeur sur le premier maillon
    objet* dernier; //Pointeur sur le dernier maillon
    int taille; // Nombre de maillons de la liste
    void add_end(input* o);
    void add_end(output* o);
    void add_end(and2* o);
    void add_end(or2* o);
    void add_end(xor2* o);

};
#endif
