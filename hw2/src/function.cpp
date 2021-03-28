#include<hw2.h>

using namespace std;
void course::PutCourseName(string name) {
    this->coursename = name;
}
void course::PutScore(int score) {
    this->score = score;
}
string course::GetCourseName() {
    return this->coursename;
}
int course::GetScore() {
    return this->score;
}
void student::PrintAverage() {
    int i;
    int coursenumber = this->c.size();
    float sum = 0.0;
    for (i = 0; i < coursenumber; i++) {
        sum = sum + c[i].GetScore();
    }
    sum = sum / coursenumber;
    cout << left << setw(8) << sum;
}

void AddCourse(vector<CourseList>& CList, string coursename, int score) {
    vector<CourseList>::iterator i;
    CourseList c;
    for (i = CList.begin(); i != CList.end(); i++) {
        if (coursename == (*i).coursename) {
            (*i).ScoreList.push_back(score);
            return;
        }
    }
    c.coursename = coursename;
    c.ScoreList.push_back(score);
    CList.push_back(c);
}

int Find(vector<course>course,string coursename){
    int i;
    for(i = 0; i < course.size();i++){
        if(course[i].GetCourseName() == coursename)
        return i;
    }
    return -1;
}
void Output(vector<CourseList>courselist, vector<student>stu) {
    int i, number, k;
    cout << left << setw(8) << "no"
        << left << setw(8) << "name";
    for (i = 0; i < courselist.size(); i++)
    {
        cout << left << setw(8) << courselist[i].coursename;
    }
    cout << "average" << endl;
    for (i = 0; i < stu.size(); i++) {
        cout << left << setw(8) << i + 1
            << left << setw(8) << stu[i].studentname;

        for (k = 0; k < courselist.size(); k++) {
            number = Find(stu[i].c, courselist[k].coursename);
            if (number == -1)cout << left << setw(8) << "null";
            else cout << left << setw(8) << stu[i].c[number].GetScore();
        }

        stu[i].PrintAverage();
        cout << endl;
    }
    cout << left << setw(8) << ""
        << left << setw(8) << "average";
    for (i = 0; i < courselist.size(); i++) {
        cout << left << setw(8) << courselist[i].sum / courselist[i].ScoreList.size();
    }
    cout << endl;
    cout << left << setw(8) << ""
        << left << setw(8) << "min";
    for (i = 0; i < courselist.size(); i++) {
        cout << left << setw(8) << courselist[i].ScoreList[0];
    }
    cout << endl;
    cout << left << setw(8) << ""
        << left << setw(8) << "max";
    for (i = 0; i < courselist.size(); i++) {
        cout << left << setw(8) << courselist[i].ScoreList[courselist[i].ScoreList.size() - 1];
    }
}