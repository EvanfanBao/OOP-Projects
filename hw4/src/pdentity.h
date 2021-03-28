#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<time.h>
#include<iomanip>
#include<vector>
#include"Date.h"
#include<algorithm>
using namespace std;
#pragma once

class pdentity{
private: 
    string brief;
public:
    vector<string> text;
    Date date;
    void PrintText(ofstream& file);    
    void SetBrief(string brief);   
    string GetBrief(){return brief;};
    bool operator==(const pdentity&  pd);  
    void PrintText();

};
class PdSet{
public:
    vector<pdentity> pdset;
    void GetData(ifstream& file);
};

typedef vector<pdentity> :: iterator PdIte;     // typedef for simlicity
