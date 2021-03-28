#include"Date.h"
#include"pdentity.h"
#include<stdio.h>
#include<getopt.h>
extern int optind,opterr,optopt;
extern char *optargi;
using namespace::std;
static struct option long_options[] = 
{
    {"s",required_argument,NULL,'s'},
    {"e",required_argument,NULL,'e'},
    {"start",required_argument,NULL,'s'},
    {"end",required_argument,NULL,'e'}
};
extern bool LessSort(pdentity pd1,pdentity pd2);
typedef vector<pdentity> :: iterator PdIte;         //typedef for simlicity