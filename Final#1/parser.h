#ifndef _PARSER_H_
#define _PARSER_H_

#include "lexeur_d.h"
#include "blocs.h"
#include "and2.h"
#include "or2.h"
#include "xor2.h"
#include "input.h"
#include "output.h"
#include "objet.h"
#include "list.h"
#include "simulation.h"
#include "interp.h"
#include "lexeur_d.cpp"
#include "blocs.cpp"
#include "and2.cpp"
#include "or2.cpp"
#include "xor2.cpp"
#include "input.cpp"
#include "output.cpp"
#include "objet.cpp"
#include "list.cpp"
#include "simulation.cpp"
#include "interp.cpp"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <map>
#include <set>
#include <string>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

    int Verif_taille_dot(vector<string> &lChainDot);
    void Verif_synt_dot(vector<string> &lChainDot);
    void Verif_synt_json(vector<string> &lChainJson);
    void verif_list(clist mainlist[], int cpt_list, string nom);
    clist* Parse(string output_names[], int cpt_list, vector<string> &lChainDot, vector<string> &lChainJson, input x_in[], output x_out[], and2 x_and[],or2 x_or[], xor2 x_xor[]);
    void To_Upper(vector<string>& lChainDot);
    input creer_input(string name);
    output creer_output(string name);
    and2 creer_and(string name);
    or2 creer_or(string name);
    xor2 creer_xor(string name);
    //void compteurs();
    void compteurs(vector<string> &lChainDot, int &cpt_input, int &cpt_output, int &cpt_or2, int &cpt_and2, int &cpt_xor2);
    void add_byname(clist firstlist, clist mainlist[], string name, int rank);
    void set_byname(clist mainlist[], string nom, bool value, int longueur);
    bool get_byname(clist mainlist[], string nom, int longueur);
    //bool UselessLine(string line);
    //friend ostream& operator <<(ostream& out, const  Parseur &f);



#endif