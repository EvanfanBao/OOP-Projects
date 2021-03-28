#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>
#include"room.h"
#include"main.h"
using namespace std;
class Play {
    int i, j, k;  // current position
    int user_seed;
    int monroom, prinroom;
    room rooms[HEIGHT][LENGTH][WIDTH];
public:
    Play():i(0),j(0),k(0),user_seed(2) {};
    void Create_Position();
    void SetRoom();
    void Welcome();
    void Interact(); 
    void PosUpdate();
    void GetSeed();
};
