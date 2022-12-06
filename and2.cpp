class and2 : public bloc {
  public :
    and2(string nom);
    ~and2();
    bool in1, in2;
    bool *out;
    void calculate(bool& out);
};



and2::and2(string nom){
  name = nom;
  type = "function";
}
and2::~and2(){
}
void and2::calculate(bool& out){
    out = in1&in2;
}
