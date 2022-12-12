
class output : public bloc {

public :
  output();
  output(string nom);
  ~output();
  bool netValue;
  bool* getAdr();
  output &operator = (const output & copie);
};

output & output::operator = (const output & copie)
{
    // pour éviter l'autoaffectation : P = P
    if (this == & copie) return *this;
    name = copie.name;
    netValue = copie.netValue;
    return *this;
}

output::output(){
}
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
