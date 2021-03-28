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
    ��Ŀ����������ĳǱ���һ�������Σ�ÿ�����䶼��ȷ���ķ���Ͳ��������еķ�������ͨ�ģ�����������ڵĻ���
    �������Ϊ�˷������̲��ԡ���Ϊ�����ǹ̶��ģ����Ե�����ͨ����ʮ�ּ򵥵ġ��Ǳ��Ĳ�����2 x 3 x 3(�� x �� x ��)
    ����ʽ��һ��18�����䣬ÿ�����䶼�ǲ�ͬ�ģ�������ҵ�������в�ͬ������ڵķ�����ǲ�ͬ�ģ��������͹���
    ������趨�ģ���Ҫ�û���һ�����ӣ�����ҵ���������ҵ�����������������lobby�����ڣ��������������Ϊ000
    ������죡
*/
using namespace std;
const int MAXDIR = 6;       // maximum direction number
const int HEIGHT = 2;       // castle height
const int LENGTH = 3;       // castle length
const int WIDTH  = 3;       // castle width
const int LOBBY  =  0;      // lobby room number
enum dirname { east, south, west, north, up, down };
auto room_num = [](int x, int y, int z) {return x * LENGTH * WIDTH + y * WIDTH + z; };

