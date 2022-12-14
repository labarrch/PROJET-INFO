#include "objet.h"

objet::objet(input *o){
  pointi = o;
  type = 0;
}
objet::objet(output *o){
  pointo = o;
  type = 1;
}
objet::objet(and2 *o){
  pointa = o;
  type = 2;
}
objet::objet(or2 *o){
  pointor = o;
  type = 3;
}
objet::objet(xor2 *o){
  pointxor = o;
  type = 4;
}
