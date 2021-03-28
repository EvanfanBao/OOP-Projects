#include"Date.h"
#include"pdentity.h"

using namespace std;

int main(int argc, char** argv){
    freopen("out.txt","a+",stdout);
    if(argc == 1){cout << "please specify the date" << endl;return -1;}        // No date specified

    PdSet pds;                                                                 // Personal diary set
    ifstream file("hw4.txt");   
    pds.GetData(file);                                                         // Read dat
    pdentity deletedpd;                                                        // Diary to be deleted
    deletedpd.date.SetDate(argv[1]);                                           // Throw an exception if invalid input

    PdIte ite;
    ite = find(pds.pdset.begin(),pds.pdset.end(),deletedpd);                   // Find the diary with the specified date
    if(ite == pds.pdset.end())                                                 // Not find, fail
        return -1;
    pds.pdset.erase(ite);                                                      // Find, erase remove
    file.close();

    ofstream file2("hw4.txt");
    for(ite = pds.pdset.begin();ite != pds.pdset.end();ite++)                  // Write back to disk
        (*ite).PrintText(file2);   
    file2.close();
    return 0;
}