#include <boost/algorithm/string.hpp>
#include "parser.h"
using namespace std;

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

    //output o1("o1");

    //and2 a2("a2");
    //cout << a2.name << endl;

    //input i1("i1", a2.in1);
    //input i2("i2", a2.in2);

    //cout << a2.in1 << endl;
    //cout << a2.in2 << endl;

    //a2.calculate(o1.netValue);

    //cout << o1.netValue << endl;

    vector<bloc> maintab[2];
    maintab[0].push_back(i1);
    maintab[0].push_back(a2);
    maintab[0].push_back(o1);
    maintab[1].push_back(i2);
    maintab[1].push_back(a2);

    //int longueur = (sizeof(maintab)/sizeof(maintab[0]));



   for(int i=0; i<longueur; i++){
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
*/
