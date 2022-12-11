#ifndef _PARSER_H_
#define _PARSER_H_

#include"lexeur_d.cpp"
#include "blocs.cpp"
#include "and2.cpp"
#include "or2.cpp"
#include "xor2.cpp"
#include "input.cpp"
#include "output.cpp"
#include "objet.cpp"
#include "list.cpp"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <set>
#include <string>


using namespace std;

    int Verif_taille();
    void Verif_synth();
    void Parse(int cpt_list);
    void To_Upper(vector<string>& lChainDot);
    input creer_input(string name);
    output creer_output(string name);
    and2 creer_and(string name);
    or2 creer_or(string name);
    xor2 creer_xor(string name);
    //bool UselessLine(string line);
    //friend ostream& operator <<(ostream& out, const  Parseur &f);



#endif
