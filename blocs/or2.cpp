class or2 : public bloc {
  public :
    or2(string nom);
    ~or2();
    bool in1, in2;
    bool *out;
    bool firstUse, alreadyDest;
    void calculate();
    void setDest(bool* dest);
    bool* getAdr();
};


or2::or2(string nom){
  name = nom;
  in1 = false;
  in2 = false;
  type = "function";
  firstUse = false;
  alreadyDest=false;
}
or2::~or2(){
}

void or2::calculate(){
    *out = in1|in2;
}

void or2::setDest(bool* dest){
  alreadyDest=true;
  out = dest;
}

bool* or2::getAdr(){
  if(firstUse==false){
    firstUse=true;
    return &in1;
  }
  else{
    return &in2;
  }
}
