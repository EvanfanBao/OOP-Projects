
#include"pdlist.h"

int main(int argc,char **argv){
    freopen("list.txt","a+",stdout);                      // Stdout redirect
    
    PdSet pds;                                               // Personal diary set
    ifstream file("hw4.txt");                           // Diary files
    Date start,end;                                          // Start and end date, corresponding with the cmd parameter
    int order = 1;                                           // List order
   
    pds.GetData(file);                                       // Read data;
   
    sort(pds.pdset.begin(),pds.pdset.end(),LessSort);        // Sort Date--acsending order
    PdIte ite;                                               // Person diary Iterator         
    PdIte ite_start;                                         // Start iterotor
    PdIte ite_end;                                           // End iterator
    ite_start = pds.pdset.begin();ite_end = pds.pdset.end(); // Initialize 
    int c; int index = 0;                                    // c and index for getopt_long_only return value

    //process the cmd parameter
    while(EOF != (c = getopt_long_only(argc,argv,"s:e:",long_options,&index))){
        switch(c)
        {
            case 's':start.SetDate(optarg);                  // Set start iterator
                    for(ite = pds.pdset.begin();ite != pds.pdset.end();ite++)
                        if((*ite).date > start || (*ite).date == start)break;
                    ite_start = ite;    
                    break;
            case 'e':end.SetDate(optarg);                 // Set end iterator
                    for(ite = pds.pdset.begin();ite != pds.pdset.end();ite++)
                        if( (*ite).date > end || (*ite).date == end)break;
                    ite_end = --ite;
                    break;
            case '?':cout << "unknow option:optopt\n";break;//unknow parameter
            default :
                break;
        }
    }
    
    // Output the specified data in order
    for(ite = ite_start;ite != ite_end;ite++){
        cout << order << ". ";
        (*ite).date.Print_Date(); 
        cout << "breif: "<< (*ite).GetBrief() << endl;    
        order++;            
    }
}

