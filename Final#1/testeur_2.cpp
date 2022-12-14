#include "parser.h"
#include "parser.cpp"

using namespace std;

int main() {

  vector<string> lChainDot;
  vector<string> lChainJson;
  const char * dot = "full_adder.dot";
  const char * json = "full_adder.json";
  const char * json_out = "full_adder_out.json";
  int resultat = lexeur(dot,json,lChainDot,lChainJson);
  To_Upper(lChainDot);
  To_Upper(lChainJson);

  //lectureChaine(lChainJson);

  int cpt_list = Verif_taille_dot(lChainDot);
  Verif_synt_dot(lChainDot);
  Verif_synt_json(lChainJson);


  int time = calcul_time(lChainJson);

  int cpt_input = 0;
  int cpt_output = 0;
  int cpt_or2 = 0;
  int cpt_and2 = 0;
  int cpt_xor2 = 0;

  compteurs(lChainDot, cpt_input, cpt_output, cpt_or2, cpt_and2, cpt_xor2);


  string output_names[cpt_output];
  string input_names[cpt_input];
  vector<bool> inputs[cpt_input];
  vector<bool> outputs[cpt_output];

  cout<<"nbr out :"<<cpt_output<<endl;

  for (int k = 0; k < cpt_output; k++) {
    outputs[k].push_back(true);
  }


  calculer_in(lChainJson, inputs, input_names);

  input x_in[cpt_input];
  output x_out[cpt_output];
  and2 x_and[cpt_and2];
  or2 x_or[cpt_or2];
  xor2 x_xor[cpt_xor2];
  bool buff;



  clist *mainlist = Parse(output_names,cpt_list, lChainDot, lChainJson, x_in, x_out, x_and, x_or, x_xor);

  afficherNoms(mainlist, cpt_list);

  cout << "time = "<<calcul_time(lChainJson)<<endl;

    for (int j =0; j< time; j++) {
      for (int i = 0; i < cpt_input; i++) {
        set_byname(mainlist, input_names[i], inputs[i][j], cpt_list);
      }
      calculer (mainlist, cpt_list);
      for (int k = 0; k < cpt_output; k++) {
        buff = get_byname(mainlist, output_names[k], cpt_list);
        outputs[k].push_back(buff);
      }
    }

    for (size_t i = 1; i < time+1; i++) {
      for (size_t j = 0; j < cpt_output; j++) {
        cout << output_names[j] << " = " << outputs[j][i]<<"    ";
      }
      cout << endl;
    }

    copie_inputs(json, json_out, output_names, outputs, cpt_output, time);










    return 0;

  }



  //afficherNoms(mainlist, cpt_list);

  //set_byname(mainlist, "A", false, cpt_list);
  //set_byname(mainlist, "B", false, cpt_list);
  //set_byname(mainlist, "C", false, cpt_list);
