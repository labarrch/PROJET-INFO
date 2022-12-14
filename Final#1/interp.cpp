#include <vector>

int copie_inputs(const char* fichierJsonIn, const char* fichierJsonOut, string output_names[], vector<bool> outputs[], int cpt_output, int time){

	string buf;
	ofstream sortie;
	ifstream entree;
  int last_action =0;

	sortie.open(fichierJsonOut,ios::out);
	entree.open(fichierJsonIn,ios::in);

	if(!sortie){
    return 1;
	}
	if(!entree){
    return 1;
	}

  while (getline(entree, buf)){
  	if (buf.find(']')!=(-1)){
    }
    else{
      sortie << buf << "\n";
    }
  }

sortie <<"  "<<"{},"<<endl;

  for (int i = 0; i < cpt_output; i++) {
    sortie << "  { name: "<<'"'<<output_names[i]<<'"'<<", "<<"wave: '";
    for (int j = 1; j < time+1; j+=2) {
      if (outputs[i][j]==true&&outputs[i][j+1]==true){
        if(last_action==1){
          sortie<<".";
        }
        else{
          sortie<<"h";
          last_action =1;
        }
      }
      else if (outputs[i][j]==false&&outputs[i][j+1]==false){
        if(last_action==2){
          sortie<<".";
        }
        else{
          sortie<<"l";
          last_action =2;
        }
      }
      else if (outputs[i][j]==true&&outputs[i][j+1]==false){
        if(last_action==3){
          sortie<<".";
        }
        else{
          sortie<<"p";
          last_action =3;
        }
      }
      else if (outputs[i][j]==false&&outputs[i][j+1]==true){
        if(last_action==4){
          sortie<<".";
        }
        else{
          sortie<<"n";
          last_action =4;
        }
      }
    }
    sortie <<"' },\n";
  }
sortie <<"\n]}"<<endl;
sortie.close();
entree.close();
}
