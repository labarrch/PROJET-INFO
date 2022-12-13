using namespace std;


#include "lexeur_d.cpp"
#include "blocs/blocs.cpp"
#include "blocs/and2.cpp"
#include "blocs/or2.cpp"
#include "blocs/ou.cpp"
#include "blocs/input.cpp"
#include "blocs/output.cpp"
#include "blocs/objet.cpp"
#include "blocs/list.cpp"
#include "blocs/simulation.cpp"
#include <iostream>
#include <vector>
#include <typeinfo>

ou creer_ou (string nom);
and2 creer_and2 (string nom);
output creer_output (string nom);
void add_byname(clist firstlist, clist mainlist[], string name, int rank);
void set_byname(clist mainlist[], string nom, bool value, int longueur);
bool get_byname(clist mainlist[], string nom, int longueur);

void to_upper(vector<string> &chaine);
void to_upper(vector<string> &chaine){
  for (int i = 0; i < chaine.size(); i++) {
    for (int j = 0; j < chaine[i].size(); j++) {
      chaine[i][j] = toupper(chaine[i][j]);
    }
  }
}

void set_byname(clist mainlist[], string nom, bool value, int longueur){
  for(int i=0; i<longueur; i++){
    for(int j=0 ;j<mainlist[i].taille; j++){
      if (mainlist[i].adresse_position_n(j)->type == 0 && mainlist[i].adresse_position_n(j)->pointi->name==nom){
        mainlist[i].adresse_position_n(j)->pointi->setVal(value);
      }
    }
  }
}

bool get_byname(clist mainlist[], string nom, int longueur){
  for(int i=0; i<longueur; i++){
    for(int j=0 ;j<mainlist[i].taille; j++){
      if (mainlist[i].adresse_position_n(j)->type == 1 && mainlist[i].adresse_position_n(j)->pointo->name==nom){
        return mainlist[i].adresse_position_n(j)->pointo->netValue;
      }
    }
  }
}

void add_byname(clist firstlist, clist mainlist[], string name, int rank){

  output xout;
  input xin;
  and2 xand;
  ou xou;

  for (int j = 0; j < firstlist.taille; j++) {
    switch (firstlist.adresse_position_n(j)->type){
      case 0 :
        if (name == firstlist.adresse_position_n(j)->pointi->name){
          mainlist[rank].add_end(firstlist.adresse_position_n(j)->pointi);
        }
        break;
      case 1:
        if (name == firstlist.adresse_position_n(j)->pointo->name){
          mainlist[rank].add_end(firstlist.adresse_position_n(j)->pointo);
        }
        break;
      case 2 :
        if (name == firstlist.adresse_position_n(j)->pointa->name){
          mainlist[rank].add_end(firstlist.adresse_position_n(j)->pointa);
        }
        break;
      case 4 :

        if (name == firstlist.adresse_position_n(j)->pointou->name){
          mainlist[rank].add_end(firstlist.adresse_position_n(j)->pointou);
        }
        break;
    }
  }
}

input creer_input (string nom){
  input input(nom);
  return input;
}
output creer_output (string nom){
  output output(nom);
  return output;
}
ou creer_ou (string nom){
  ou or21(nom);
  return or21;
}
and2 creer_and2 (string nom){
  and2 a2(nom);
  return a2;
}




int main(int argc, char* argv[]){

vector<string> lChainDot;
vector<string> lChainJson;


    clist firstlist;
    int i=0;

    output xout[10];
    input xin[10];
    and2 xand[10];
    ou xou[10];

    ///toupper(test)

    xout[i] = creer_output("o1");
    firstlist.add_end(&xout[i]);
    i++;
    xout[i] = creer_output("o2");
    firstlist.add_end(&xout[i]);
    i++;

    //output o2("o2");
    /*xou = creer_ou("or21");*/

    //firstlist.add_end(&o2);
    ou or21("or21");
    /*xand = creer_and2("a2");*/
    firstlist.add_end(&or21);
    and2 a2("a2");
    /*xou = creer_ou("or22");*/
    firstlist.add_end(&a2);
    ou or22("or22");
    /*xin = creer_input("i1");*/
    firstlist.add_end(&or22);
    /*xin = creer_input("i1");
    firstlist.add_end(&xin);*/
    input i1("i1");
    firstlist.add_end(&i1);
    input i2("i2");
    firstlist.add_end(&i2);




    clist mainlist[4];

    add_byname(firstlist, mainlist, "i1", 0);
    add_byname(firstlist, mainlist, "a2", 0);
    add_byname(firstlist, mainlist, "or21", 0);
    add_byname(firstlist, mainlist, "o1", 0);

    add_byname(firstlist, mainlist, "i2", 1);
    add_byname(firstlist, mainlist, "a2", 1);

    add_byname(firstlist, mainlist, "i1", 2);
    add_byname(firstlist, mainlist, "or22", 2);
    add_byname(firstlist, mainlist, "or21", 2);
    add_byname(firstlist, mainlist, "o1", 2);

    add_byname(firstlist, mainlist, "i2", 3);
    add_byname(firstlist, mainlist, "or22", 3);

    int longueur = (sizeof(mainlist)/sizeof(mainlist[0]));

    cout << longueur << endl;

    cout << mainlist[2].adresse_position_n(0)->pointi->name<< endl;

    connecterBlocs(mainlist, longueur);

    set_byname(mainlist, "i1", true, longueur);
    set_byname(mainlist, "i2", false, longueur);

    calculer(mainlist, longueur);

    cout<<get_byname(mainlist,"o1",longueur)<<endl;
    //cout<<get_byname(mainlist,"o2",longueur)<<endl;



}
