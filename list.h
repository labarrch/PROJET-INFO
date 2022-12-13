#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class clist

{
  friend class objet;
  public :
  objet* premier;   // Pointeur sur le premier maillon.
  objet* dernier;  // Pointeur sur le dernier maillon.
  int taille;   // Nombre de maillons de la liste.

    clist();
    ~clist();
   void add_end(input* o);
   void add_end(output* o);
   void add_end(and2* o);
   void add_end(or2* o);
   void add_end(xor2* o);
   objet* adresse_position_n(int position);



};
#endif
