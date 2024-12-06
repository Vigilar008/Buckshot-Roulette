#include <iostream>
#include <fstream>
#include <sstream>
#include "save.h"
#include <unistd.h>
using namespace std;

string save_filename = "Save_Statue";

void save(bool flag, int round, bool turn,int DEFAULT_HEALTH, int DEFAULT_ITEMS, int MAX_LIVES, int MAX_BLANKS)
{
    ofstream fout;
    fout.open(save_filename);
    if (fout.fail())
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    fout << flag << " " << round << " " << turn << " " << DEFAULT_HEALTH << " " << DEFAULT_ITEMS << " " <<  MAX_LIVES << " " << MAX_BLANKS << endl;
    fout.close();
    return;
}

void load(bool &flag, int &round, bool &turn,int &DEFAULT_HEALTH, int &DEFAULT_ITEMS, int &MAX_LIVES, int &MAX_BLANKS)
{
    ifstream fin;
    fin.open(save_filename);
    if (fin.fail())
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    string input,temp1, temp2,dh,di,ml,mb;
    getline(fin,input);
    istringstream st(input);
    st >> flag >> temp1 >> temp2 >> dh >> di >> ml >> mb;
    round=stoi(temp1);
    turn=stoi(temp2);
    DEFAULT_HEALTH = stoi(dh);
    DEFAULT_ITEMS = stoi(di);
    MAX_LIVES = stoi(ml);
    MAX_BLANKS = stoi(mb);
    fin.close();
}
