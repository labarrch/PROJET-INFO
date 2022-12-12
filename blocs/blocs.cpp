class bloc{
  public :
    string name;
    string type;

    bloc();
    ~bloc();

    virtual void setDest(bool* dest);
    virtual void setDestTest();
    virtual bool* getAdr();
    virtual void setVal(bool val);
};


bloc::bloc(){}
bloc::~bloc(){}

void bloc::setDest(bool* dest){}
bool* bloc::getAdr(){}
void bloc::setVal(bool val){}
void bloc::setDestTest(){}
