
class input : public bloc {
  public :
  input(string nom, bool& adrSuiv, bool value);
  input(string nom, bool& adrSuiv);
  input(string nom);
  ~input();
  bool *netValue;
  void setDest(bool* dest);
  void setVal(bool val);
};


input::input(string nom){
  name = nom;
  type = "input";
}


void input::setVal(bool val){
  *netValue = val;
}


input::input(string nom, bool& adrSuiv, bool value){
    name = nom;
  type = "input";
  netValue = &adrSuiv;
  *netValue = value;
}

input::input(string nom, bool& adrSuiv){
    name = nom;
  type = "input";
  netValue = &adrSuiv;
}

input::~input(){
}

void input::setDest(bool* dest){
  netValue = dest;
}
