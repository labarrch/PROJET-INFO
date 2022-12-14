#include "parser.h"
#include "parser.cpp"

using namespace std;

int main() {
  vector<string> lChainDot;
  vector<string> lChainJson;

  const char * dot = "full_adder.dot";
  const char * json = "full_adder.json";
  int resultat = lexeur(dot,json,lChainDot,lChainJson);
  To_Upper(lChainDot);
  //lectureChaine(lChainJson);
  int cpt_list = Verif_taille(lChainDot);
  cout<<"test_2"<<endl;
  Verif_synt(lChainDot);
  clist *mainlist = Parse(cpt_list, lChainDot);
  cout<<"reussite2"<<endl;

  cout << mainlist[0].adresse_position_n(1)->pointxor->name<<endl;


  return 0;
}
