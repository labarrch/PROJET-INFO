#include "parser.h"

using namespace std;

void compteurs(vector<string> &lChainDot, int &cpt_input, int &cpt_output, int &cpt_or2, int &cpt_and2, int &cpt_xor2)
{
  string line;
  int chain_size = lChainDot.size();
  int f_input = -1;
  int f_output = -1;
  int f_and2 = -1;
  int f_or2 = -1;
  int f_xor2 = -1;
  int i = 0;
  while(&lChainDot[i] && i < chain_size)
  {
    line = lChainDot[i];
    f_input = line.find("INPUT");
    f_output = line.find("OUTPUT");
    f_and2 = line.find("AND2");
    f_or2 = line.find("OR2");
    f_xor2 = line.find("XOR2");


    if(f_input != -1)
    {
      f_input = -1;
      cpt_input++;
    }
    if(f_output != -1)
    {
      f_output = -1;
      cpt_output++;
    }
    if(f_and2 != -1)
    {
      f_and2 = -1;
      cpt_and2++;
    }
    if(f_or2 != -1)
    {
      f_or2 = -1;
      cpt_or2++;
    }
    if(f_xor2 != -1)
    {
      f_xor2 = -1;
      cpt_xor2++;
    }
    i++;
  }
}

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
      case 3 :

        if (name == firstlist.adresse_position_n(j)->pointor->name){
          mainlist[rank].add_end(firstlist.adresse_position_n(j)->pointor);
        }
        break;
      case 4 :

        if (name == firstlist.adresse_position_n(j)->pointxor->name){
          mainlist[rank].add_end(firstlist.adresse_position_n(j)->pointxor);
        }
        break;
    }
  }
}

void To_Upper(vector<string>& lChainDot)
{
  for (int i = 0; i < lChainDot.size(); i++) {
    for (int j = 0; j < lChainDot[i].size(); j++) {
      lChainDot[i][j] = toupper(lChainDot[i][j]);
    }
  }
}

int Verif_taille(vector<string> &lChainDot)
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

void Verif_synt(vector<string> &lChainDot)
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
clist* Parse(int cpt_list, vector<string> &lChainDot)
{

    vector<string> Biblio;
    Biblio.push_back("INPUT");
    Biblio.push_back("OUTPUT");
    Biblio.push_back("NOT");
    Biblio.push_back("AND2");
    Biblio.push_back("OR2");
    Biblio.push_back("NAND");
    Biblio.push_back("NOR");
    Biblio.push_back("XOR2");
    Biblio.push_back("XNOR");
    Biblio.push_back("MUX");
    Biblio.push_back("FA");

    int chain_size = lChainDot.size();
    string line;
    int i = 0;
    set<string>::iterator itr;
    clist mainlist[cpt_list];
    clist first_list;
    int cpt = 0;
    int ffleche = -1;
    int fpv = -1;

    int cpt_input = 0;
    int cpt_output = 0;
    int cpt_or2 = 0;
    int cpt_and2 = 0;
    int cpt_xor2 = 0;
    compteurs(lChainDot, cpt_input, cpt_output, cpt_or2, cpt_and2, cpt_xor2);

    input x_in[cpt_input];
    output x_out[cpt_output];
    and2 x_and[cpt_and2];
    or2 x_or[cpt_or2];
    xor2 x_xor[cpt_xor2];
    int itr_in = 0, itr_out = 0, itr_and = 0, itr_or = 0, itr_xor = 0;

    vector<string> buf;

    while(&lChainDot[i] && i < chain_size)
    {
      line = lChainDot[i];
      ffleche = line.find("->");
      fpv = line.find(';');


      for (int b=0 ; b < Biblio.size() ; b++)
      {
        if(lChainDot[i] == Biblio[b] && lChainDot[i-3] == "LABEL")
        {
          if(Biblio[b] == "INPUT")
          {
            x_in[itr_in] = creer_input(lChainDot[i-5]);
            first_list.add_end(&x_in[itr_in]);
            itr_in++;

          }
          else if(Biblio[b] == "OUTPUT")
          {
            x_out[itr_out] = creer_output(lChainDot[i-5]);
            first_list.add_end(&x_out[itr_out]);
            itr_out++;

          }
          else if(Biblio[b] == "AND2")
          {
            x_and[itr_and] = creer_and(lChainDot[i-5]);
            first_list.add_end(&x_and[itr_and]);
            itr_and++;
          }
          else if(Biblio[b] == "OR2")
          {
            x_or[itr_or] = creer_or(lChainDot[i-5]);
            first_list.add_end(&x_or[itr_or]);
            itr_or++;
          }
          else if(Biblio[b] == "XOR2")
          {
            x_xor[itr_xor] = creer_xor(lChainDot[i-5]);
            first_list.add_end(&x_xor[itr_xor]);
            itr_xor++;
          }
        }
      }

      if(ffleche != -1)
      {
        ffleche = -1;
        add_byname(first_list, mainlist, lChainDot[i-1], cpt);
      }
        if(fpv != -1)
        {
          fpv = -1;
          line = lChainDot[i-2];
          ffleche = line.find("->");
          if(ffleche !=-1)
          {
            ffleche = -1;
            add_byname(first_list, mainlist, lChainDot[i-1], cpt);
            lChainDot[i-1];
            cpt++;
          }
        }
      i++;
      }
      //connecterBlocs(mainlist, cpt_list);
      //afficherNoms(mainlist, cpt_list);
      return mainlist;

    }

/*

int main(){
  int resultat = lexeur(dot,json,lChainDot,lChainJson);
  To_Upper(lChainDot);
  lectureChaine(lChainJson);
  int cpt_list = Verif_taille();
  clist mainlist[cpt_list];
  Verif_synt();
  //Parse(cpt_list, lChainDot, mainlist);
  return 0;
}*/

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
