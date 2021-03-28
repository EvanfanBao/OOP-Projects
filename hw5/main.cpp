#include"Fraction.h"

//test case
int main(){

    cout << "performing initialization" << endl;
    Fraction x1;                 //default constructor
    Fraction x2; 
    Fraction y(1,2);            //ctor takes two integers as parameters
    Fraction z(y);              //copy constructor
    Fraction u("1.414");        //constructor for a finite decimal string
    //inserter
    cout << "initialize result " << y << " " << z << " " << u << endl;  
    x1 = "1.713";               //conversion from a finite decimal cstring
    string dec_str = "1.618";   
    x2 = dec_str;               //converion from finite decimal string
    cout << "conversion from decimal string result "<< x1 << " " << x2 << endl;
    string tohere;
    tohere = y.toString();      //to string
    cout << "to string result " << tohere << endl;
    double castdb;
    castdb = (double)y;         //cast to double
    castdb = static_cast<double>(y);
    cout << "cast to double result " << castdb << endl;

    //arithmetic operations
    cout << "performing arithmetic operations" << endl;
    z = x1 + x2;cout << "z = x1 + x2 result:" << z << endl;
    z = x1 - x2;cout << "z = x1 - x2 result:" << z << endl;
    z = x1 * x2;cout << "z = x1 * x2 result:" << z << endl;
    z = x1 / x2;cout << "z = x1 / x2 result:" << z << endl;
    
    z = x1 / "0";               //divide zero error

    //relational operations
    cout << "performing relational operations" << endl;
    bool cmp;
    cmp = x1 < x2;cout << "x1 < x2 result:" << cmp << endl; 
    cmp = x1 > x2;cout << "x1 > x2 result:" << cmp << endl; 
    cmp = x1 <= x2;cout << "x1 <= x2 result:" << cmp << endl; 
    cmp = x1 >= x2;cout << "x1 >= x2 result:" << cmp << endl; 
    cmp = x1 != x2;cout << "x1 != x2 result:" << cmp << endl; 
    cmp = x1 == x2;cout << "x1 == x2 result:" << cmp << endl; 

    cout << "performing extractor" << " please enter your input with the format a/b" << endl;
    
    cin >> z;
    cout << "the result is: "<< z << endl;
    system("pause");
    
}