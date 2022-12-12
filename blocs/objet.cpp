class objet
{
  friend class clist;
public :

  objet(input *o);
  objet(output *o);
  objet(and2 *o);
  objet(or2 *o);
  objet(ou *o);

  int type;

   input* pointi;
   output* pointo;
   and2* pointa;
   or2* pointor;
   ou* pointou;

   objet* next;        // L'adresse du suivant.

};

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
objet::objet(ou *o){
  pointou = o;
  type = 4;
}
