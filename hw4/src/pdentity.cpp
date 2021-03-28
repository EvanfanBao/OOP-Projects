#include "pdentity.h"
using namespace std;

// Print one diary to stdout without date
void pdentity::PrintText(){
    vector<string> ::iterator ite;
    for(ite = text.begin();ite != text.end();ite++)
        cout << (*ite) << endl;
}

// Print one diary to file with date -- write back to disk
void pdentity::PrintText(ofstream& file){
    vector<string> :: iterator line;
    this->date.Print_Date(file);
    for(line = text.begin();line != text.end();line++){
        file << *line << endl;
    }
    file << endl;
}

// Operator==
bool pdentity :: operator==(const pdentity&  pd){
    return date == pd.date;
}
// Set brief for pdlist
void pdentity::SetBrief(string brief){
    this->brief = brief;
}

// LessSort for comparision
bool LessSort(pdentity pd1,pdentity pd2){
    return pd2.date > pd1.date;
}

// Read data from file
void PdSet:: GetData(ifstream& file)
{   
    bool flag = false;
    pdentity Apd;string tempstring;
    while(getline(file,tempstring)){
        if(tempstring == ""){
            flag = false ;
            Apd.SetBrief(Apd.text.front());
            pdset.push_back(Apd);
            Apd.text.clear();       
        }
        else if(flag == false) {Apd.date.SetDate(tempstring);flag = true;}
        else Apd.text.push_back(tempstring);         // read each line of one diary
    }
}