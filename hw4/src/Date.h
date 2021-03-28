//Date class -- 本作业 年月日即可表示日期
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<time.h>
#include<iomanip>
using namespace std;
#pragma once
class Date
{
private:
    int m_year;
    int m_month;
    int m_day;
public:
    Date();                       //当前时间构造
    Date(int year,int month, int day);  
    Date(const Date& date);         //赋值构造
    ~Date();
    bool operator==(const Date& date);  // is same
    bool operator>(const Date& date);   // compare date
    void SetDate(string date);    //标准输入字符串构造
    void Print_Date();                  //终端输出
    void Print_Date(ofstream& file);    //out stream here
    bool operator<(const Date& date);
};