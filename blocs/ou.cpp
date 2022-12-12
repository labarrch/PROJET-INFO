class ou : public bloc {
  public :
    ou();
    ou(string nom);
    ~ou();
    bool in1, in2;
    bool *out;
    bool firstUse, alreadyDest, full;
    int calculate();
    void setDest(bool* dest);
    bool* getAdr();
    ou &operator = (const ou & copie);
};

ou & ou::operator = (const ou & copie)
{
    // pour éviter l'autoaffectation : P = P
    if (this == & copie) return *this;

    name = copie.name;
    in1 = copie.in1;
    in2 = copie.in2;
    if (out){
      out = copie.out;
    }
    return *this;
}

ou::ou(){}


ou::ou(string nom){
  name = nom;
  in1 = false;
  in2 = false;
  type = "function";
  firstUse = false;
  alreadyDest=false;
  full = false;
}
ou::~ou(){
}

int ou::calculate(){
  if (full){
      *out = in1|in2;
      return 0;
  }
  else {
      return 1;
  }

}


void ou::setDest(bool* dest){
  alreadyDest=true;
  out = dest;
}
bool* ou::getAdr(){
  if(firstUse==false){
    firstUse=true;
    return &in1;
  }
  else{
    full = true;
    return &in2;
  }
}
