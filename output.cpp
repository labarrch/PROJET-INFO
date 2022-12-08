

class output : public bloc {

public :
  output(string nom);
  ~output();
  bool netValue;
  bool* getAdr();
};


output::output(string nom){
  name = nom;
  netValue = false;
  type = "output";
}
output::~output(){
}

bool* output::getAdr(){
  return &netValue;

}
