
class input : public bloc {
  public :
  input(string nom, bool& adrSuiv, bool value);
  input(string nom, bool& adrSuiv);
  input(string nom);
  input();
  ~input();
  bool *netValue;
  void setDest(bool* dest);
  void setVal(bool val);
  input &operator = (const input & copie);
};

input &input::operator = (const input & copie)
{
    // pour éviter l'autoaffectation : P = P
    if (this == & copie) return *this;

    name = copie.name;
    if (netValue){
      netValue = copie.netValue;
    }
    return *this;
}

input::input(){}


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
