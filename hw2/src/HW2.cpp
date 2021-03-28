/*实现功能：读入任意数量的学生与课程以及对应成绩，并计算相关数字特征，按标准输出。
 *输入格式：姓名 课程 成绩 课程 成绩 ... 换行 最后一行#结尾
 *存在不足：输出的时候的宽度有限制，所以学生姓名和课程名称不能太长，否则要更改相关参数
 *当然也可以在文件读入的时候增加约束改进，主要看需求如何。
 *还有我头文件命名之类的都不太好，应该一个类对应一个的，但我感觉太少了，就懒得弄
 *还有我很多class的字段都设的public，不太好。
 */

/*
--------------------------------------------------------------------------
 * implemented function: read in any number of students and courses and corresponding grades, 
 * calculate relevant digital characteristics, and output according to standards.
 * Input format: Name Course Grade Course Grade ... Newline Last line # End
 * There are shortcomings: the width of the output is limited, so the student name and course 
 * name cannot be too long, otherwise the relevant parameters must be changed
 * Of course, you can also add constraints and improve when reading the file, 
 * mainly depending on the needs
 * warnings: “<”: 有符号/无符号不匹配;“=”: 从“_Ty”转换到“float”，可能丢失数据
 */
#include<hw2.h>
using namespace std;

int main() {

    vector<student> stu;            //student records vector
    vector<CourseList>courselist;   //courselist. including coursename and its score list
    string name;                    //student name-read
    course crs;                     //one of one student's courses(coursename and score) 
    string course_name;             //course name-read
    int score;                      //score-read
    student stuobj;                 //one student's record.
    ifstream file1("D:\\hw2.txt");  //path may be changed   
    int i;
 
    //read data from file
    while (file1 >> name) {
        if (name == "#")break;                          //end of file symbol
        stuobj.studentname = name;                      //read and create records
        stuobj.c.clear();
        while (file1 >> course_name) {
            file1 >> score;
            AddCourse(courselist, course_name, score);  //if no duplicate, add course, if yes, update scorelist
            crs.PutCourseName(course_name);     
            crs.PutScore(score);
            stuobj.c.push_back(crs);
            if (file1.get() == '\n')break;
        }
        stu.push_back(stuobj);
    }

    //sort each course's scorelist and sum it
    for (i = 0; i < courselist.size(); i++) {
        sort(courselist[i].ScoreList.begin(), courselist[i].ScoreList.end());
        courselist[i].sum = accumulate(courselist[i].ScoreList.begin(), courselist[i].ScoreList.end(), 0);
    }
    //output table
    Output(courselist, stu);
    getchar();
}
