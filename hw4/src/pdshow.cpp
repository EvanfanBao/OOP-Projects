#include"Date.h"
#include"pdentity.h"

using namespace std;
typedef vector<pdentity> :: iterator PdIte;
extern bool LessSort(pdentity pd1,pdentity pd2);


int main(int argc, char** argv){
    
    freopen("show.txt","a+",stdout);                        // Stdout redirect
    PdSet pds;                                              // Personal diary set
    ifstream file("hw4.txt" );                              // Open file, read data 
    pdentity choosepd;                                      // Specifed data to show
    pds.GetData(file);                                      // Read diary 
    choosepd.date.SetDate(argv[1]);                         // Exception may throw if parameter is invalid
    sort(pds.pdset.begin(),pds.pdset.end(),LessSort);       // Sort
    PdIte ite;
    ite = find(pds.pdset.begin(),pds.pdset.end(),choosepd); // Find diary 
    if(ite == pds.pdset.end())return -1;                    // Not find, fail
    else
    {
        cout << "content: "<<endl;
        (*ite).PrintText();                                 // If find, print text
    }
    file.close();
    return 0;
}