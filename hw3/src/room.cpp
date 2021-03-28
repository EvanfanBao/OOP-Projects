#include<iostream>
#include<string>
#include<stdlib.h>

#include"room.h"
#include"main.h"

//in format of task description, output direction 
void room::ListDir() {
    int count = 0;
    for (int i = 0; i < MAXDIR; i++)
        if (dirList[i].IsOpen) {
            if (count == dir_num - 1)
                cout << " and " << dirList[i].dir << '.';
            else if (count == dir_num - 2)cout << " " << dirList[i].dir;
            else cout << " " << dirList[i].dir << ',';
            count++;
        }
}
//construtor -- set direction
room::room() {
    dirList[0].dir = "east";
    dirList[1].dir = "south";
    dirList[2].dir = "west";
    dirList[3].dir = "north";
    dirList[4].dir = "up";
    dirList[5].dir = "down";
}

