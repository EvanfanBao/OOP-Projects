#include"pdentity.h"

using namespace std;

typedef vector<pdentity> :: iterator PdIte;
int main(){
    freopen("data.txt","r",stdin);                              // Redirection stdin
    freopen("out.txt","a+",stdout);                             // Redirection stdout
    ifstream file1("hw4.txt");                                  // Open read file
    string tempstring;                                          // Temporary string to store the text
    PdSet pds;                                                  // Personal diary set
    bool first = false;                                         // Helping flag
    pds.GetData(file1); file1.close();                          // Read data from file
    pdentity newpd;                                             // New diary entity
    PdIte ite;
    
    cout << "enter writing date, press 0 by default"<<endl;     // Date is automatically set according to the computer time
    cin >> tempstring;                                          // Set the date
    if(tempstring != "0") newpd.date.SetDate(tempstring);       // Exception may be thrown if the date argument is invalild
                                                                // Program will set the PC time for this data
    ite = find(pds.pdset.begin(),pds.pdset.end(),newpd);        // Check if there exists the same date
    //read from stdin
    int index;                                                  // Index of '.'
    while(getline(cin,tempstring)){
        if(first == false){first = true;continue;}              // Getline() will read my "enter"
        index = tempstring.find('.');
        if(index != string::npos){
            newpd.text.push_back(tempstring.substr(0,index+1)); // Meeting '.'
            break;   
        }
        else newpd.text.push_back(tempstring);                  // Push until EOF
    }
    
    if(ite == pds.pdset.end())pds.pdset.push_back(newpd);
    else *ite = newpd;                                          // Replace the same date

    ofstream file2("hw4.txt");                                  // Output to file                 
    vector<string> ::iterator line;
    //int size = pds.pdset.size();int count(0);
    for(ite = pds.pdset.begin();ite != pds.pdset.end();ite++){
        (*ite).PrintText(file2);
        //count++;if(count != size) file2 << endl;
    }
    file2.close();
    return 0;
}


