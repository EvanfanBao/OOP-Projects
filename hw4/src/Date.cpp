
#include"Date.h"
using namespace std;
/* Date class definition */

// Default constructor
Date::Date(){       
    time_t timep;  struct tm *p;
    time (&timep);
    p=gmtime(&timep);  
    m_day = p->tm_mday;
    m_month = 1+p->tm_mon;
    m_year = 1900+p->tm_year;
}

// Construct by input date -- for extension(not used here) -- overload
Date::Date(int year,int month, int day):
m_year(year),m_month(month),m_day(day){}

// Assignment construt -- for extension(not used here) -- overload
Date::Date(const Date& date)
{
    m_year = date.m_year;
    m_month = date.m_month;
    m_day = date.m_day;
}
// Destructor
Date::~Date(){};

// SetDate by string date
void Date::SetDate(string date)
{   
    // Exception throw
    try{
        m_year = stoi(date.substr(0,4));
        m_month = stoi(date.substr(5,2));
        m_day = stoi(date.substr(8,2));
    }
    catch(invalid_argument){
        cout << "Invalid_argument" << endl;
    }
    catch(out_of_range){
        cout << "out_of_range" << endl;
    }
}

// Output Date (format yyyy.mm.dd) to the stdout -- overload
void Date::Print_Date()
{
    cout << m_year << "." << setw(2) << setfill('0') <<m_month << "." << setw(2) << setfill('0') << m_day << endl;
}
// Output Date (format yyyy.mm.dd) to file -- overload
void Date::Print_Date(ofstream& file)        //注意是追加 到时候ios::app 对于ofstream--ios::out而言 到时候测试下
{
    file << m_year << "." << setw(2) << setfill('0') <<m_month << "." << setw(2) << setfill('0') << m_day << endl;
}

// Operator==
bool Date::operator==(const Date& date)
{
    if(m_year==date.m_year 
        && m_month==date.m_month
        && m_day==date.m_day)return true;
    else return false;
}
// Operator>
bool Date::operator>(const Date& date) //当前日期是否大于输入日期
{   //
    if(m_year > date.m_year) 
        return true;
    else if(m_year == date.m_year)
        if(m_month > date.m_month)
            return true;
        else if(m_month == date.m_month)
            if(m_day > date.m_day)
                return true;
    return false;
}
bool Date::operator<(const Date& date)
{
   if(m_year < date.m_year)
        return true;
    else if(m_year == date.m_year)
        if(m_month < date.m_month)
            return true;
        else if(m_month == date.m_month)
            if(m_day < date.m_day)
                return true;
    return false;
}
