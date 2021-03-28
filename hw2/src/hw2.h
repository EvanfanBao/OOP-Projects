#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<iomanip>


#ifndef FlAG
#define FLAG

using namespace std;

class CourseList {
public:
    string coursename;
    vector<int>ScoreList;
    float sum;
};
class course {
private:
    string coursename;
    int score;
public:
    int GetScore();
    string GetCourseName();
    void PutCourseName(string name);
    void PutScore(int score);
};

class student {
public:
    string studentname;
    vector<course> c;
    void PrintAverage();
};
int Find(vector<course>course, string coursename);
void AddCourse(vector<CourseList>& CList, string coursename, int score);
void Output(vector<CourseList>courselist, vector<student>stu);
#endif
