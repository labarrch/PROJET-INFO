void afficherNoms(clist mainlist[], int longueur){
  for(int i=0; i<longueur; i++){
    cout<<"\nLigne n°"<<i+1<<endl;
    for(int j=0 ;j<mainlist[i].taille; j++){
      switch (mainlist[i].adresse_position_n(j)->type){
        case 0 :
          cout<<mainlist[i].adresse_position_n(j)->pointi->name<< endl;
          break;
        case 1:
          cout <<mainlist[i].adresse_position_n(j)->pointo->name<< endl;
          break;
        case 2 :
          cout <<mainlist[i].adresse_position_n(j)->pointa->name<< endl;
          break;
        case 3 :
          cout <<mainlist[i].adresse_position_n(j)->pointor->name<< endl;
          break;
        case 4 :
          cout <<mainlist[i].adresse_position_n(j)->pointxor->name<< endl;
          break;
      }
    }
  }
}

void afficherNoms_2(clist mainlist){
    for(int j=0 ;j<mainlist.taille; j++){
      switch (mainlist.adresse_position_n(j)->type){
        case 0 :
          cout << mainlist.adresse_position_n(j)->pointi->name<< endl;
          break;
        case 1:
          cout << mainlist.adresse_position_n(j)->pointo->name<< endl;
          break;
        case 2 :
          cout << mainlist.adresse_position_n(j)->pointa->name<< endl;
          break;
        case 3 :
          cout << mainlist.adresse_position_n(j)->pointor->name<< endl;
          break;
        case 4 :
          cout << mainlist.adresse_position_n(j)->pointxor->name<< endl;
          break;
    }
  }
}

void connecterBlocs(clist mainlist[], int longueur){
  bool* bufAdr = NULL;

  for(int i=0; i<longueur; i++){
    bufAdr = NULL;
    for(int j=mainlist[i].taille- 1 ;j>=0; j--){
      switch (mainlist[i].adresse_position_n(j)->type){
        case 1 :
          bufAdr = mainlist[i].adresse_position_n(j)->pointo->getAdr();
          break;
        case 2:
          if(bufAdr != 0){
            mainlist[i].adresse_position_n(j)->pointa->setDest(bufAdr);
        }
          bufAdr = mainlist[i].adresse_position_n(j)->pointa->getAdr();
          break;
        case 3 :
          if(bufAdr != 0){
              mainlist[i].adresse_position_n(j)->pointor->setDest(bufAdr);
          }
          bufAdr = mainlist[i].adresse_position_n(j)->pointor->getAdr();
          break;
          case 4 :
            if(bufAdr != 0){
                mainlist[i].adresse_position_n(j)->pointxor->setDest(bufAdr);
            }
            bufAdr = mainlist[i].adresse_position_n(j)->pointxor->getAdr();
            break;
        case 0 :
          mainlist[i].adresse_position_n(j)->pointi->setDest(bufAdr);
          break;
      }
    }

  }

}

void calculer(clist mainlist[], int longueur){
  int resultat;
  int iter_necess = 0;
  while (iter_necess< 5) {
    for(int i=0; i<longueur; i++){
      for(int j=0; j<mainlist[i].taille;j++){
        switch (mainlist[i].adresse_position_n(j)->type){
          case 2 :
          resultat = mainlist[i].adresse_position_n(j)->pointa->calculate();
            break;
          case 3 :
          resultat = mainlist[i].adresse_position_n(j)->pointor->calculate();
            break;
          case 4 :
          resultat = mainlist[i].adresse_position_n(j)->pointxor->calculate();
            break;

        }
      }

    }
    iter_necess++;
  }
}

int calcul_time(vector<string> &lChainJson){
  int i = 3;
  while(&lChainJson[i] && i < lChainJson.size()){
      if(lChainJson[i-3] == "WAVE"){
          return lChainJson[i].size()*2;
        }
    i++;
    }
}

void calculer_in(const vector<string> &lChainJson, vector<bool> tab[],string names[]){
  int tab_num = 0;
  int last_action =0;
  for (int i=3; i< lChainJson.size(); i++){
    if (lChainJson[i-3] == "WAVE"){
      names[tab_num] = lChainJson[i-6];
      for (int j = 0; j < lChainJson[i].size(); j++) {
        if (lChainJson[i][j]=='P'){
            tab[tab_num].push_back(true);
            tab[tab_num].push_back(false);
            last_action =1;
        }
        else if (lChainJson[i][j]=='N'){
            tab[tab_num].push_back(false);
            tab[tab_num].push_back(true);
            last_action =2;
        }
        else if (lChainJson[i][j]=='H'){
            tab[tab_num].push_back(true);
            tab[tab_num].push_back(true);
            last_action =3;
        }
        else if (lChainJson[i][j]=='L'){
            tab[tab_num].push_back(false);
            tab[tab_num].push_back(false);
            last_action =4;
        }
        else if (lChainJson[i][j]=='.'){
            switch(last_action){
              case 1 :
                tab[tab_num].push_back(true);
                tab[tab_num].push_back(false);
                last_action =1;
              break;
              case 2 :
                tab[tab_num].push_back(false);
                tab[tab_num].push_back(true);
                last_action =2;
              break;
              case 3 :
                tab[tab_num].push_back(true);
                tab[tab_num].push_back(true);
                last_action =3;
              break;
              case 4 :
                tab[tab_num].push_back(false);
                tab[tab_num].push_back(false);
                last_action =4;
              break;
            }
        }

      }
    tab_num++;
    }

  }
}

bool existe(clist first_list, int cpt_list, string nom){
  for (int j = 0; j < first_list.taille; j++){
    switch (first_list.adresse_position_n(j)->type){
      case 0 :
      if(first_list.adresse_position_n(j)->pointi->name == nom){
        cout<<"erreur syntaxe : labels avec memes noms"<<endl;
        return 0;
      }
        break;
      case 1 :

    case 2 :
      if(first_list.adresse_position_n(j)->pointa->name == nom){
        cout<<"erreur syntaxe : labels avec memes noms"<<endl;
        return 0;
      }
        break;
      case 3 :
      if(first_list.adresse_position_n(j)->pointor->name == nom){
        cout<<"erreur syntaxe : labels avec memes noms"<<endl;
        return 0;
      }
        break;
      case 4 :
      if(first_list.adresse_position_n(j)->pointxor->name == nom){
      cout<<"erreur syntaxe : labels avec memes noms"<<endl;
      return 0;
      }
        break;
    }
  }
  return 1;
}
