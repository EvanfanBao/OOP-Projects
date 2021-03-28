#include<iostream>
#include<string>
using namespace std;
#pragma once
class Fraction{
private:
    int numerator;      //分子
    int denominator;    //分母
    void StringToFraction(const string& s);  //Only used as helper for construtor and assignment operation
public:
    Fraction(){}                             //Default constructor
    Fraction(int num,int den);               //Constructor takes two integers as parameters
    Fraction(const Fraction& fra);           //Copy constructor
    Fraction(const string& decimal_string);  //Implicit conversion from a finite decimal string like 1.414
    Fraction(const char* s);                 //Implict conversion from a finite decimal cstring;
    int gcd();                               //Gcd of numerator and denominator   
    static int gcd( int x,  int y);          //Calculte gcd of x and y
    int lcm( int x,  int y);                 //Calculte lcm(least common multiple) of x and y
    int GetNum();                            //Get numerator for future use
    int GetDen();                            //Get numerator for future use
    void SetNum(int num);                    //Allowing user to set numerator
    bool SetDen(int Den);                    //Allowing user to set denominator.False returned if Den is zero;
    void reduce();                           //Reduce this fraction to its simplist form
    
    const string toString() const;           //Fraction to string
    const Fraction reciprocal()const;        //Return reciprocal of this fraction.Exception is thrown if this fraction is zero
    const Fraction operator-() const;        //Negate operation 
    Fraction operator=(const char* s);       //Assignment operation for cstring. For conversion fron string in assignment
    operator double()const;                  //Type cast to double
    operator string()const;
    
    friend const Fraction operator+(const Fraction& lhs,const Fraction& rhs);      //Add two fraction. No reduction
    friend const Fraction operator-(const Fraction& lhs,const Fraction& rhs);      //Minus two fraction. No reduction
    friend const Fraction operator*(const Fraction& lhs,const Fraction& rhs);      //Multiply two fraction. No reduction
    friend const Fraction operator/(const Fraction& lhs,const Fraction& rhs);      //Division between two fraction. No reduction
    friend bool operator==(const Fraction& lhs,const Fraction& rhs);               //Is equal
    friend bool operator<(const Fraction& lhs,const Fraction& rhs);                //Is less than
    friend bool operator<=(const Fraction& lhs,const Fraction& rhs);               //Is less than or equal to
    friend bool operator!=(const Fraction& lhs,const Fraction& rhs);               //Is nonequal to
    friend bool operator>=(const Fraction& lhs,const Fraction& rhs);               //Is greater than or equal to
    friend bool operator>(const Fraction& lhs,const Fraction& rhs);                //Is greater than
    friend ostream& operator<<(ostream& os,const Fraction& fra);                   //Inserter
    friend istream& operator>>(istream& is,Fraction& fra);                         //Extractor
};

//constructors
inline Fraction::Fraction(const char* s){*this = s;}

inline Fraction::Fraction(const Fraction& fra){
    numerator = fra.numerator;
    denominator = fra.denominator;
}
inline Fraction::Fraction(int num,int den):numerator(num),denominator(den){}