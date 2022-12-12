class clist

{
  friend class objet;
  public :
    clist();
    ~clist();
   void add_end(input* o);
   void add_end(output* o);
   void add_end(and2* o);
   void add_end(or2* o);
   void add_end(ou* o);
   objet* adresse_position_n(int position);

    objet* premier;   // Pointeur sur le premier maillon.
    objet* dernier;  // Pointeur sur le dernier maillon.
    int taille;   // Nombre de maillons de la liste.

};


clist::clist(){
  taille = 0;
  dernier = NULL;
  premier = NULL;
}
clist::~clist(){}

void clist::add_end(input* o){
  input* p = o;
  objet* ajout = new objet(p);
  if(taille==0){
    premier = ajout;
    dernier = ajout;
  }
  else{
  dernier->next = ajout;
  dernier = ajout;
  }
  taille++;

}

void clist::add_end(ou* o){
  ou* p = o;
  objet* ajout = new objet(p);
  if(taille==0){
    premier = ajout;
    dernier = ajout;
  }
  else{
  dernier->next = ajout;
  dernier = ajout;
  }
  taille++;

}
void clist::add_end(output* o){
  output* p = o;
  objet* ajout = new objet(p);
  if(taille==0){
    premier = ajout;
    dernier = ajout;
  }
  else{
  dernier->next = ajout;
  dernier = ajout;
  }
  taille++;

}
void clist::add_end(and2* o){
  and2* p = o;
  objet* ajout = new objet(p);
  if(taille==0){
    premier = ajout;
    dernier = ajout;
  }
  else{
  dernier->next = ajout;
  dernier = ajout;
  }
  taille++;

}
void clist::add_end(or2* o){
  or2* p = o;
  objet* ajout = new objet(p);
  if(taille==0){
    premier = ajout;
    dernier = ajout;
  }
  else{
  dernier->next = ajout;
  dernier = ajout;
  }
  taille++;

}

objet* clist::adresse_position_n(int position){
  objet* pointage;
  pointage = premier;
  for(int i =0; i<position; i++){
    pointage = pointage->next;
  }
  return pointage;
}
