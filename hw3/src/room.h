#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>

#include"main.h"
using namespace std;

class direction {
public:
    bool IsOpen;    //identify if the direction is open(accessible)
    string dir;     //direction name
    direction() :IsOpen(1) {};
};

class room {
    string name;                 //room name
public:
    direction dirList[MAXDIR];   //direction list. east\south\west\north\up\down 
    int dir_num;                 //total direction number for a room
    void SetName(string name) { this->name = name; };   //set room name
    string GetName() { return name; };            //get room name
    void ListDir();              //output the direction of exits
    room();
};