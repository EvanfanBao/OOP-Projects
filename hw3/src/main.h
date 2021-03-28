#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>
#include"main.h"
/* HW3    : Adventure
   author : YiFan Bao
   ID     : 3180103499
   description: here,the castle is a **RECTANGULAR BUILDING** with specific directions and levels
   All the rooms are connected if they are adjacent for the simplicity of being understood and 
   tested( it can be easily set if you don't want all of them are connected. but it's not important.
   The calstle in this program is 2 x 3 x 3(height x length x width), having 18 rooms in total, all the
   rooms are different types( according to the task specification, rooms with differnt exits are different
   types ). Monster rooms and Princess rooms are randomly set. This needs a user_seed. Player is required 
   to avoid monster and find the princess and take her back to lobby(here is 000)
   Have fun!
*/
/*
    项目描述：这里的城堡是一个长方形，每个房间都有确定的方向和层数。所有的房间是联通的，如果他们相邻的话。
    这仅仅是为了方便助教测试。因为布局是固定的，所以调整连通性是十分简单的。城堡的布局是2 x 3 x 3(高 x 长 x 宽)
    的形式，一共18个房间，每个房间都是不同的（根据作业描述，有不同方向出口的房间就是不同的），公主和怪兽
    是随机设定的（需要用户给一个种子）。玩家的任务就是找到公主并将其带回入口lobby（出口），这里入口设置为000
    测试愉快！
*/
using namespace std;
const int MAXDIR = 6;       // maximum direction number
const int HEIGHT = 2;       // castle height
const int LENGTH = 3;       // castle length
const int WIDTH  = 3;       // castle width
const int LOBBY  =  0;      // lobby room number
enum dirname { east, south, west, north, up, down };
auto room_num = [](int x, int y, int z) {return x * LENGTH * WIDTH + y * WIDTH + z; };

