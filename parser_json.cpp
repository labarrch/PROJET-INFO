#include <boost/algorithm/string.hpp>
#include "parser.cpp"
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
vector<string> lChainDot;
vector<string> lChainJson;

input creer_input(string name)
{
  input l_in(name);
  return l_in;
}


output creer_output(string name)
{
  output l_out(name);
  return l_out;
}

and2 creer_and(string name)
{
  and2 l_and(name);
  return l_and;
}

or2 creer_or(string name)
{
  or2 l_or(name);
  return l_or;
}
xor2 creer_xor(string name)
{
  xor2 l_xor(name);
  return l_xor;
}



void To_Upper(vector<string>& lChainDot)
{
  int i = 0;
  while(&lChainDot[i] && i < lChainDot.size())
  {
    string vect;
    vect = lChainDot[i];
    boost::to_upper(vect);
    lChainDot[i] = vect;
    i++;
  }
}



int Verif_taille()
{
  int i = 0;
  string line;
  int cpt = 0;
  int chain_size = lChainDot.size();

  while(&lChainDot[i] && i < chain_size)
  {
    int ffleche = -1;
    int fpv = -1;
    line = lChainDot[i];
    ffleche = int(line.find("->"));
    if(ffleche !=-1)
    {
      int j = i+2;
      line = lChainDot[j];
      fpv = int(line.find(";"));
      if(fpv !=-1){
        cpt++;
      }
    }
    i++;
  }
  return cpt;
}

const char * dot = "full_adder.dot";
const char * json = "full_adder.dot";

void Verif_synth()
{
    int chain_size = lChainDot.size();
    int last_string = chain_size-1;

    int cpt_guill=0;
    int cpt_croch_open=0;
    int cpt_croch_close=0;
    int guill=-1;
    int croch_open=-1;
    int croch_close=-1;
    int accol_open = -1;
    int accol_close = -1;
    int egal = -1;
    int cpt_egal = 0;
    int label = -1;
    int cpt_label = 0;
    int fpv = -1;
    int fpv_av = -1;
    int guill_lab = -1;
    int ffleche = -1;
    int ffleche_av = -1;
    int digraph = -1;

    string line;
    int i = 0;


    while(&lChainDot[i] && i < chain_size)
    {
      line = lChainDot[i];
      croch_open = (line.find('['));
      croch_close = (line.find(']'));
      guill = (line.find('"'));
      label = (line.find("LABEL"));
      egal = (line.find('='));
      ffleche = (line.find("->"));
      digraph = (line.find("DIGRAPH"));
      accol_open = (line.find('{'));
      accol_close = (line.find('}'));

      if(accol_close == -1 && i == last_string){
        cout<<"erreur syntaxe : accolade fermante manquante"<<endl;
        exit(1);
      }
      if(accol_open != -1 && i != 2)
      {
        cout<<"erreur syntaxe : accolade ouvrante mal placee"<<endl;
        exit(1);
      }
      accol_open = -1;

      if(accol_close != -1 && i != last_string)
      {
        cout<<"erreur syntaxe : accolade fermante mal placee"<<endl;
        exit(1);
      }
      accol_close = -1;

      if(digraph != -1 && i == 0)
      {
          digraph = 1;
          line = lChainDot[i+2];
          accol_open = (line.find('{'));
          if(accol_open == -1)
          {
            cout<<"erreur syntaxe : accolade ouvrante manquante"<<endl;
            exit(1);
          }
          accol_open = -1;
      }
      else if(digraph == -1 && i == 0)
      {
        cout<<"erreur syntaxe : le fichier ne commence pas par digraph"<<endl;
        exit(1);
      }
      if(label >= 0)
      {
        cpt_label += 1;
        label = -1;
        line = lChainDot[i+1];
        egal = (line.find('='));
        if(egal == -1){
          cout<<"erreur syntaxe : pas de = apres label"<<endl;
          exit(1);
        }
        line = lChainDot[i+2];
        guill_lab = (line.find('"'));

        if(guill_lab == -1)
        {
          cout<<"erreur syntaxe : guillemet ouvrant manquant"<<endl;
          exit(1);
        }
        else
        {
          guill_lab = -1;
          line = lChainDot[i+4];
          guill_lab = (line.find('"'));

          if(guill_lab == -1)
          {
            cout<<"erreur syntaxe : guillement fermant manquant"<<endl;
            exit(1);
          }
        }
        guill_lab = -1;
        egal = -1;
      }

      if(croch_open >= 0)
      {
        cpt_croch_open += 1;
        croch_open = -1;
        line = lChainDot[i+1];
        label = -1;
        label = (line.find("LABEL"));
        if(label == -1)
        {
          cout<<"erreur syntaxe : pas de label après ["<<endl;
          exit(1);
        }
        label = -1;
      }

      if(croch_close >= 0)
      {
        cpt_croch_close += 1;
        croch_close = -1;
        fpv = -1;
        line = lChainDot[i+1];
        fpv = (line.find(';'));

        if(fpv == -1)
        {
          cout<<"erreur syntaxe : point virgule manquant"<<endl;
          exit(1);
        }
        fpv = -1;
      }

      if(egal >= 0)
      {
        cpt_egal += 1;
        egal = -1;
        line = lChainDot[i-1];
        label = (line.find("LABEL"));

        if(label == -1)
        {
          cout<<"erreur syntaxe : pas de label avant ="<<endl;
          exit(1);
        }
        label = -1;
      }

      if(guill >= 0)
      {
        cpt_guill += 1;
        guill = -1;
      }

      if(ffleche != -1)
      {
        ffleche = -1;
        line = lChainDot[i-2];
        fpv_av = (line.find(';'));
        ffleche_av = (line.find("->"));

        if(fpv_av == -1 && ffleche_av == -1)
        {
          cout<<"erreur syntaxe : point virgule manquant"<<endl;
          exit(1);
        }
        ffleche_av = -1;
        fpv_av = -1;
      }
      i++;
    }

    if(cpt_croch_open != cpt_croch_close || cpt_croch_open != cpt_egal || cpt_croch_open != cpt_label || cpt_croch_close != cpt_egal || cpt_croch_close != cpt_label || cpt_egal != cpt_label)
    {
      cout<<"cpt_crocho"<<cpt_croch_open<<"cpt_crochf"<<cpt_croch_close<<"cpt_label"<<cpt_label<<"cpt_egal"<<cpt_egal<<endl;
      cout<<"erreur syntaxe"<<endl;
      exit(1);
    }

    if(cpt_croch_open != cpt_croch_close)
    {
      cout << "erreur syntaxe crochets<<"<<endl;
      exit(1);
    }
    if(cpt_guill % 2 != 0)
    {
      cout << "erreur syntaxe guillemets<<"<<endl;
      exit(1);
    }
}




void Parse(int cpt_list){
    set<string> Biblio {"INPUT","OUTPUT","NOT","AND","OR","NAND","NOR","XOR","XNOR","MUX", "FA"};
    int chain_size = lChainDot.size();
    int last_string = chain_size - 1;
    string line;
    int i = 0;
    int digraph = -1;
    int croch_open = -1;
    int croch_close = -1;
    int guill = -1;
    int label = -1;
    int egal = -1;
    int ffleche = -1;
    int accol_open = -1;
    int accol_close = -1;
    int fpv = -1;
    set<string>::iterator itr;
    clist mainlist[cpt_list];
    int cpt = 0;


    while(&lChainDot[i] && i < chain_size)
    {
      line = lChainDot[i];
      croch_open = (line.find('['));
      croch_close = (line.find(']'));
      guill = (line.find('"'));
      label = (line.find("LABEL"));
      egal = (line.find('='));
      ffleche = (line.find("->"));
      digraph = (line.find("DIGRAPH"));
      accol_open = (line.find('{'));
      accol_close = (line.find('}'));
      fpv = (line.find(';'));
      vector<string> buf;

      for (itr = Biblio.begin(); itr != Biblio.end(); itr++)
      {
        if(lChainDot[i] == *itr && *itr == "INPUT")
        {
          creer_input(lChainDot[i-5]);
          input (*in_1)(string);
          in_1 = &creer_input;
          mainlist[cpt].add_end(in_1);
        }
        else if(lChainDot[i] == *itr && *itr == "OUTPUT")
        {
          creer_output(lChainDot[i-5]);
          output (*out_1)(string);
          out_1 = &creer_output;
        }
        else if(lChainDot[i] == *itr && *itr == "AND2")
        {
          creer_and(lChainDot[i-5]);
          and2 (*and_1)(string);
          and_1 = &creer_and;
        }
        else if(lChainDot[i] == *itr && *itr == "OR2")
        {
          creer_or(lChainDot[i-5]);
          or2 (*or_1)(string);
          or_1 = &creer_or;
        }
        else if(lChainDot[i] == *itr && *itr == "XOR2")
        {
          creer_xor(lChainDot[i-5]);
          xor2 (*xor_1)(string);
          xor_1 = &creer_xor;
        }
      }

      if(ffleche != -1)
      {
        ffleche = -1;
        //mainlist[cpt].add_end(&in_1);
      }
      if(fpv != -1)
      {
        fpv = -1;
        line = lChainDot[i-2];
        ffleche = line.find(';');
        if(ffleche !=-1)
        {
          ffleche = -1;
          //mainlist[cpt].add_end(&lChainDot[i-1]);
          cpt++;
        }
      }






      i++;
    }
}

int main(){
  int resultat = lexeur(dot,json,lChainDot,lChainJson);
  To_Upper(lChainDot);
  lectureChaine(lChainDot);
  int cpt_list = Verif_taille();
  Verif_synth();
  cout <<"Compteur : " <<cpt_list<<endl;
  Parse(cpt_list);
  return 0;
}

/*
  cout << a2.in1 << endl;
  cout << a2.in2 << endl;

  a2.calculate(o1.netValue);

  cout << o1.netValue << endl;
  */

    //output o1("o1");

    //and2 a2("a2");

    //cout << o1.netValue << endl;

    /*vector<bloc> maintab[2];

    vector<bloc> maintab[2];
    maintab[0].push_back(i1);
    maintab[0].push_back(a2);
    maintab[0].push_back(o1);
    maintab[1].push_back(i2);
    maintab[1].push_back(a2);
    */

    //int longueur = (sizeof(maintab)/sizeof(maintab[0]));



  /*  for(int i=0; i<longueur; i++){
   for(int i=0; i<longueur; i++){
      for(int j=0 ;j< maintab[i].size(); j++){
        //cout << i << j << endl;
        //cout << maintab[i][j].name<<" -> "<< maintab[i][j].type<<endl;
      }
    }

    for(int i=0; i<longueur; i++){
      for(int j=maintab[i].size()-1; j>=0; j--){
        if (maintab[i][j].type == "output"){
@ -78,14 +453,13 @@ int main(){
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



    int longueur = (sizeof(mainlist)/sizeof(mainlist[0]));
    bool* bufAdr;
    cout << longueur<<endl;