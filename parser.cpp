using namespace std;

#include "lexeur_d.cpp"
#include "blocs.cpp"
#include "and2.cpp"
#include "or2.cpp"
#include "input.cpp"
#include "output.cpp"
#include "objet.cpp"
#include "list.cpp"
#include <iostream>
#include <vector>
#include <typeinfo>

int main(){


/*
  cout << a2.in1 << endl;
  cout << a2.in2 << endl;

  a2.calculate(o1.netValue);

  cout << o1.netValue << endl;
  */
    //output o1("o1");

    //and2 a2("a2");
    //cout << a2.name << endl;

    //input i1("i1", a2.in1);
    //input i2("i2", a2.in2);

    //cout << a2.in1 << endl;
    //cout << a2.in2 << endl;

    //a2.calculate(o1.netValue);

    //cout << o1.netValue << endl;

    /*vector<bloc> maintab[2];

    maintab[0].push_back(i1);
    maintab[0].push_back(a2);
    maintab[0].push_back(o1);
    maintab[1].push_back(i2);
    maintab[1].push_back(a2);
    */
    //int longueur = (sizeof(maintab)/sizeof(maintab[0]));



  /*  for(int i=0; i<longueur; i++){
      for(int j=0 ;j< maintab[i].size(); j++){
        //cout << i << j << endl;
        //cout << maintab[i][j].name<<" -> "<< maintab[i][j].type<<endl;
      }
    }

    for(int i=0; i<longueur; i++){
      for(int j=maintab[i].size()-1; j>=0; j--){
        if (maintab[i][j].type == "output"){
          bufAdr = maintab[i][j].getAdr();
          cout << maintab[i][j].name<<" -> "<< maintab[i][j].type<<endl;
          cout << bufAdr <<endl;
        }
        else if (maintab[i][j].type == "function"){
          maintab[i][j].setDest(bufAdr);
          maintab[i][j].setDestTest();
          bufAdr = maintab[i][j].getAdr();
          cout << maintab[i][j].name<<" -> "<< maintab[i][j].type<<endl;
          cout << bufAdr <<endl;
        }
        else if (maintab[i][j].type == "input"){
              maintab[i][j].setDest(bufAdr);
              cout << maintab[i][j].name<<" -> "<< maintab[i][j].type<<endl;
              cout << bufAdr <<endl;
        }
        }
    }

    for(int i=0; i<longueur; i++){
      for(int j=maintab[i].size()-1; j>=0; j--){
        //cout << i << j << endl;
        //cout << maintab[i][j].name<<" -> "<< maintab[i][j].type<<endl;
      }
    }
    */
    //bufAdr = o1.getAdr();
    //a2.setDest(bufAdr);

    //bufAdr = a2.getAdr();
    //i1.setDest(bufAdr);
    //bufAdr = a2.getAdr();
    //i2.setDest(bufAdr);



    //i1.setVal(false);
    //i2.setVal(false);

    //a2.calculate();

    output o1("o1");
    output o2("o2");
    or2 or2("or2");
    and2 a2("a2");
    input i1("i1");
    input i2("i2");

    clist mainlist[4];

    mainlist[0].add_end(&i1);
    mainlist[0].add_end(&a2);
    mainlist[0].add_end(&o1);
    mainlist[1].add_end(&i2);
    mainlist[1].add_end(&a2);
    mainlist[2].add_end(&i1);
    mainlist[2].add_end(&or2);
    mainlist[2].add_end(&o2);
    mainlist[3].add_end(&i2);
    mainlist[3].add_end(&or2);




    int longueur = (sizeof(mainlist)/sizeof(mainlist[0]));
    bool* bufAdr;
    cout << longueur<<endl;
    for(int i=0; i<longueur; i++){
      for(int j=0 ;j<mainlist[i].taille; j++){
        switch (mainlist[i].adresse_position_n(j)->type){
          case 0 :
            cout << mainlist[i].adresse_position_n(j)->pointi->name<< endl;
            break;
          case 1:
            cout << mainlist[i].adresse_position_n(j)->pointo->name<< endl;
            break;
          case 2 :
            cout << mainlist[i].adresse_position_n(j)->pointa->name<< endl;
            break;
          case 3 :
            cout << mainlist[i].adresse_position_n(j)->pointor->name<< endl;
            break;
        }
      }
    }

    for(int i=0; i<longueur; i++){
      for(int j=mainlist[i].taille- 1 ;j>=0; j--){
        switch (mainlist[i].adresse_position_n(j)->type){
          case 1 :
            bufAdr = mainlist[i].adresse_position_n(j)->pointo->getAdr();
            cout << mainlist[i].adresse_position_n(j)->pointo->name<<" -> "<< mainlist[i].adresse_position_n(j)->pointo->type<<endl;
            cout << bufAdr <<endl;
            break;
          case 2:
            if(mainlist[i].adresse_position_n(j)->pointa->alreadyDest == false){
              mainlist[i].adresse_position_n(j)->pointa->setDest(bufAdr);
          }
            bufAdr = mainlist[i].adresse_position_n(j)->pointa->getAdr();
            cout << mainlist[i].adresse_position_n(j)->pointa->name<<" -> "<< mainlist[i].adresse_position_n(j)->pointa->type<<endl;
            cout << bufAdr <<endl;
            break;
          case 3 :
            if(mainlist[i].adresse_position_n(j)->pointor->alreadyDest == false){
                mainlist[i].adresse_position_n(j)->pointor->setDest(bufAdr);
            }
            bufAdr = mainlist[i].adresse_position_n(j)->pointor->getAdr();
            cout << mainlist[i].adresse_position_n(j)->pointor->name<<" -> "<< mainlist[i].adresse_position_n(j)->pointor->type<<endl;
            cout << bufAdr <<endl;
            break;
          case 0 :
            mainlist[i].adresse_position_n(j)->pointi->setDest(bufAdr);
            cout << mainlist[i].adresse_position_n(j)->pointi->name<<" -> "<< mainlist[i].adresse_position_n(j)->pointi->type<<endl;
            cout << bufAdr <<endl;
            break;
        }
      }
    }

    i1.setVal(true);
    i2.setVal(true);

  //  cout<<i1.netValue<<endl;
  //  cout<<&a2.in1<<endl;

    //cout<<*mainlist[0].adresse_position_n(0)->pointi->netValue<<endl;
    //cout<<*mainlist[1].adresse_position_n(0)->pointi->netValue<<endl;

    for(int i=0; i<longueur; i++){
      for(int j=0; j<mainlist[i].taille;j++){
        switch (mainlist[i].adresse_position_n(j)->type){
          case 2 :
          mainlist[i].adresse_position_n(j)->pointa->calculate();
            break;
          case 3 :
          mainlist[i].adresse_position_n(j)->pointor->calculate();
            break;
        }
      }
    }

    //cout<<*i1.netValue<<endl;
    //cout<<a2.in1<<endl;
    //cout<<a2.in2<<endl;
    //a2.calculate();

    cout <<o1.netValue<<endl;
    cout <<o2.netValue<<endl;




    //cout << mainlist.adresse_position_n(0)->pointo->netValue<< endl;
    //cout << o1.netValue<<endl;
    //cout << *mainlist.adresse_position_n(1)->pointor->out<<endl;
    //cout << *a2.out <<endl;

    //cout << a2.name<<endl;
    //cout << mainlist.taille<<endl;



    //cout << o1.netValue <<endl;
    //cout << *a2.out <<endl;

    //i1.setVal(true);
    //i2.setVal(true);

    //a2.calculate();

    //cout << o1.netValue << endl;



}
