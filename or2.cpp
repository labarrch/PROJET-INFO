class or2 : public bloc {
  public :
    or2(string nom);
    ~or2();
    bool in1, in2;
    bool *out;
    void calculate(bool& out);
};



or2::or2(string nom){
  name = nom;
  type = "function";
}
or2::~or2(){
}

void or2::calculate(bool& out){
    out = in1|in2;
}
