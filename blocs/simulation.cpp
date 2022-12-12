void afficherNoms(clist mainlist[], int longueur);
void afficherNoms_2(clist mainlist);
void connecterBlocs(clist mainlist[], int longueur);
void calculer(clist mainlist[], int longueur);



void afficherNoms(clist mainlist[], int longueur){
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
        case 4 :
          cout << mainlist[i].adresse_position_n(j)->pointou->name<< endl;
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
          cout << mainlist.adresse_position_n(j)->pointou->name<< endl;
          break;
    }
  }
}

void connecterBlocs(clist mainlist[], int longueur){
  bool* bufAdr;

  for(int i=0; i<longueur; i++){
    for(int j=mainlist[i].taille- 1 ;j>=0; j--){
      switch (mainlist[i].adresse_position_n(j)->type){
        case 1 :
          bufAdr = mainlist[i].adresse_position_n(j)->pointo->getAdr();
          break;
        case 2:
          if(mainlist[i].adresse_position_n(j)->pointa->alreadyDest == false){
            mainlist[i].adresse_position_n(j)->pointa->setDest(bufAdr);
        }
          bufAdr = mainlist[i].adresse_position_n(j)->pointa->getAdr();
          break;
        case 3 :
          if(mainlist[i].adresse_position_n(j)->pointor->alreadyDest == false){
              mainlist[i].adresse_position_n(j)->pointor->setDest(bufAdr);
          }
          bufAdr = mainlist[i].adresse_position_n(j)->pointor->getAdr();
          break;
          case 4 :
            if(mainlist[i].adresse_position_n(j)->pointou->alreadyDest == false){
                mainlist[i].adresse_position_n(j)->pointou->setDest(bufAdr);
            }
            bufAdr = mainlist[i].adresse_position_n(j)->pointou->getAdr();
            break;
        case 0 :
          mainlist[i].adresse_position_n(j)->pointi->setDest(bufAdr);
          break;
      }
    }
  }

}

void calculer(clist mainlist[], int longueur){
  bool total_flag = false;
  int partial_flag;
  int resultat;
  while (!total_flag) {
    partial_flag = 0;
    for(int i=0; i<longueur; i++){
      for(int j=0; j<mainlist[i].taille;j++){
        switch (mainlist[i].adresse_position_n(j)->type){
          case 2 :
          resultat = mainlist[i].adresse_position_n(j)->pointa->calculate();
          partial_flag+=resultat;
            break;
          case 4 :
          resultat = mainlist[i].adresse_position_n(j)->pointou->calculate();
          partial_flag+=resultat;
            break;
        }
      }
    }
    if (partial_flag==0){
      total_flag=true;
    }
  }

}
