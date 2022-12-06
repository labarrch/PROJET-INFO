class output : public bloc {
  public :
  output(string nom);
  ~output();
    bool netValue;
};




output::output(string nom){
  name = nom;
  type = "output";
}
output::~output(){
}
