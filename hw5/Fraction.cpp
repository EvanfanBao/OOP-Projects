#include"Fraction.h"
//constructors
void Fraction::StringToFraction(const string& decimal_string){
    int point_pos = decimal_string.find('.');                   //find the point
    int frac_len = decimal_string.length() - point_pos -1 ;     //fractional part 
    int zoom = 1;
    for(int i = 0;i < frac_len;i++)                            
        zoom *= 10;
    double decimal = stod(decimal_string);
    numerator = decimal*zoom;                                   //zoom to integer, for example, 1.44->144
    denominator = zoom;                                         //1.44 = 144/100
    reduce();                                                   //reduce the result
}
Fraction::Fraction(const string& decimal_string){
    StringToFraction(decimal_string);
}


//operators

Fraction::operator double() const{
    return numerator / (double)denominator;         //cast to double
}


Fraction Fraction::operator=(const char* s){
    string decimal_string = s;                  //convert cstring to string then do the same operation
    StringToFraction(decimal_string);
}


//output as fraction string like 1/2
ostream& operator<<(ostream& os,const Fraction& fra){
    if(fra.numerator == 0){
        os << 0;                 //if fraction is 0, simply print "0"
        
    }
    else os << fra.toString();           
    return os;
}

//input as fraction string like 1/2
istream& operator>>(istream& is,Fraction& fra){
    int num,den;
    char slash;
    try{
    is >> num >> slash >> den;
    if(is.fail())throw "wrong format";
    }catch(const char* msg){
        cerr << msg << endl;
    }
    fra.numerator = num;
    fra.denominator = den;
}

bool operator==(const Fraction& lhs,const Fraction& rhs){
    Fraction templ(lhs),tempr(rhs);
    templ.reduce();
    tempr.reduce();                         //reduce and compare 
    if(templ.denominator == tempr.denominator && templ.numerator == tempr.numerator)
        return true;
    else return false;
}

bool operator!=(const Fraction& lhs,const Fraction& rhs){
    return !(lhs == rhs);
}

bool operator<(const Fraction& lhs,const Fraction& rhs){
    Fraction left(lhs), right(rhs);                                 //通分比较大小
    left.numerator *= right.denominator;                            //左边分子*右边分母
    right.numerator *= left.denominator;                            //右边分子*左边分母
    if(left.numerator < right.numerator)
        return true;
    else return false;
}

bool operator>(const Fraction& lhs,const Fraction& rhs){
    return rhs < lhs;
}
bool operator<=(const Fraction& lhs,const Fraction& rhs){
    return !(lhs > rhs);
}
bool operator>=(const Fraction& lhs,const Fraction& rhs){
    return !(lhs < rhs);
}

const string Fraction::toString() const{
    string num,den;
    num = to_string(numerator);
    den = to_string(denominator);
    return num+"/"+den;                         //to string like "1/2"
}


const Fraction Fraction::reciprocal()const{
    Fraction temp;
    try{
        if(numerator == 0)throw "0 has no reciprocal";      //exception is thrown if 0 is encountered
        temp.denominator = numerator;
        temp.numerator = denominator;
    }catch(const char* msg){
        cerr << msg << endl;
    }
    return temp;
}

const Fraction Fraction::operator-() const
{   Fraction minus_fra;
    minus_fra.numerator = -numerator;
    minus_fra.denominator = denominator;
    return minus_fra;
}

//reduce to the simpliest form
void Fraction::reduce(){
    int great_common_divisor = gcd();
    numerator /= great_common_divisor;
    denominator /= great_common_divisor;
}

const Fraction operator+(const Fraction& lhs,const Fraction& rhs){
    Fraction left(lhs), right(rhs),res;
    res.denominator = left.denominator * right.denominator;         //通分
    left.numerator *= right.denominator;                            //左边分子*右边分母
    right.numerator *= left.denominator;                            //右边分子*左边分母
    res.numerator = left.numerator + right.numerator;               //求和
    return res;
}
const Fraction operator-(const Fraction& lhs,const Fraction& rhs){
    return lhs + (-rhs);
}
const Fraction operator*(const Fraction& lhs,const Fraction& rhs){
    Fraction temp;
    temp.denominator = lhs.denominator * rhs.denominator;   //分母为0 的异常-到时候在处理--所有运算都一样
    temp.numerator = lhs.numerator * rhs.numerator;
    return temp;
}

const Fraction operator/(const Fraction& lhs,const Fraction& rhs){
    return lhs * (rhs.reciprocal());
}

inline int Fraction::lcm(int x, int y){
    return x * y / gcd(x,y);
}

int Fraction::gcd(int x, int y){
    int temp;
    while(x % y != 0){
        temp = x % y;
        x = y;
        y = temp;
    }
    return y;
}

int Fraction::gcd(){
    int x = numerator;
    int y = denominator;
    return gcd(x,y);
}