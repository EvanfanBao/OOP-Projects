#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

float Ave(int *s,int n);
int Min(int *s,int n);
int Max(int *s,int n);

int main(){
    ifstream file1("D:\\hw1.txt");//file input stream

    int i,j;
    string name[10];         //student_name
    float score_ave[10],sum; //each student's average score
    float average[3];        //each course's average score
    int min[3],max[3];       //each course's maximum and minimum score
    int score[3][10];        //student score matrix

    //read data & calculate each student's average score
    for(i = 0; i < 10; i++){ 
        file1 >> name[i] >> score[0][i] >> score[1][i] >> score[2][i];
        sum = 0;
        for(j = 0;j < 3;j++){
            sum += score[j][i];
        }
        score_ave[i] = sum/3;
    }
    //calculate each course's average,maximum and minimum score 
    for(i = 0; i < 3; i++){
        average[i] = Ave(score[i],10);
        min[i] = Min(score[i],10);
        max[i] = Max(score[i],10);
    }
    //output the table
    cout<<left<<setw(8)<<"no"
        <<left<<setw(8)<<"name"
        <<left<<setw(8)<<"score1"
        <<left<<setw(8)<<"score2"
        <<left<<setw(8)<<"score3"<<"average"<<endl;
    for(i = 0; i < 10; i++){
        cout<<left<<setw(8)<<i+1
            <<left<<setw(8)<<name[i];
        for(j = 0; j < 3; j++){
        cout<<left<<setw(8)<<score[j][i];
        }
        cout<<left<<setw(8)<<score_ave[i]<<endl;
    }
    cout<<left<<setw(8)<<""
        <<left<<setw(8)<<"average"
        <<left<<setw(8)<<average[0]
        <<left<<setw(8)<<average[1]<<average[2]<<endl;
    cout<<left<<setw(8)<<""
        <<left<<setw(8)<<"min"
        <<left<<setw(8)<<min[0]
        <<left<<setw(8)<<min[1]<<min[2]<<endl;
    cout<<left<<setw(8)<<""
        <<left<<setw(8)<<"max"
        <<left<<setw(8)<<max[0]
        <<left<<setw(8)<<max[1]<<max[2]<<endl;
    //hold on the console
    getchar();
}

int Min(int *s,int n){
    int i, min;
    min = s[0];
    for(i = 1; i < n; i++){
        if(s[i] < min)min = s[i];
    }
    return min;
}
int Max(int *s,int n){
    int i, max;
    max = s[0];
    for(i = 1; i < n; i++){
        if(s[i] > max)max = s[i];
    }
    return max;
}
float Ave(int *s,int n){
    int i;
    float sum = 0;
    for(i = 0;i < n;i++){
        sum += s[i];
    }
    return sum/n;
}