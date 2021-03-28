//write the **bodies of the functions** and a main() to test all the facilities Vector provides
//authror: Bao Yifan
//ID	: 3180103499
//Date  : 2020.5.18
/*
Function: basically implement all the functions specified by the problem in analogy to std::vector(gcc)
Test	: test cases are in the main function. There's an extra .txt file for the input.
		  There is a macro TEST_SIZE for which TA could change to test the stability and performance
		  of Vector template.
Note	: inflate function will double the storage
		  capacity and size are initialized to 0 by default constructor
		  capacity and size will be 1 when first push an element
		  no extra features except for those specified by the problem--I would implement more feature for std::vector for practice 
*/
#include<iostream>
#include<string>
#include"Vector.h"
#include<fstream>
using namespace std;

//user-defined class for test
class Student{
public:                                                 //all the memebers are public for simplicity
    string name;
    string ID;
    short age;
    void Print(){cout << "name is " << name << " ID is "<<ID << " age is "<<age << endl;}
};

#define TEST_SIZE 10
int main(){

    //test case 1 built-in type
    Vector<int> x;                                      //default constructor
    Vector<int> y;                                      //default constructor
    for(int i = 0;i < TEST_SIZE;i++)                    //read data -- test Vector::push_back()
        x.push_back(i);
    
    cout << "current vector size is " <<x.size()<<endl; //test Vector::size()
    for(int i = 0;i < TEST_SIZE;i++)                    //test Vector::at() --- bound check test will be shown later
        cout << "at(i) element is " << x.at(i) << endl;
    for(int i = 0;i < TEST_SIZE;i++)
        cout << "x[i] element is " << x[i] << endl;     //test Vector::operator[]() -- no bound checking
    
    Vector<int> z = x;                                  //test copy constructor
    for(int i = 0;i < TEST_SIZE;i++)
        cout << "z[i] is "<< z[i] << " x[i] is " <<x[i] << endl;//compare the value of z[i] and x[i]
    
    if(!x.empty())
        cout << "x is not empty now" << endl;           //test Vector::empty()
    x.clear();
    cout << "after x.clear() Vector x size = " << x.size() << endl; //test Vector::clear()
    if(x.empty())
        cout << "after x.clear() Vector x is empty" << endl;
    Vector<int> u(TEST_SIZE);                           //holding size elements contructor -- initialized as 0
    cout << "size elements initialized Vector u's size is " << u.size()<<endl;
    for(int i = 0;i < TEST_SIZE;i++)
        cout << "u[i] are initialized as " << u[i] << endl;
    
    //test case 2 user-defined type
    //not so detailed like the former, because the correctness can be sufficiently proved by former.
    //just to test how template works, and help me have a deep insight into it
    Vector<Student> stu;
    Student s;
    ifstream file("hw6.txt");
    for(int i = 0;i < TEST_SIZE;i++){
        file >> s.age >> s.ID >> s.name;
        stu.push_back(s);
    }
    for(int i = 0;i < TEST_SIZE;i++)
        stu[i].Print();
    stu.at(100);                //test out of bound exception case
    system("pause");
}//~destructor
