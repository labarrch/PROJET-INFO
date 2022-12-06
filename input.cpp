class input : public bloc {
  public :
  input(string nom, bool& adrSuiv, bool value);
  input(string nom, bool& adrSuiv);
  ~input();
    bool *netValue;
};





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
