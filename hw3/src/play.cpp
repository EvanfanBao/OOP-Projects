
#include<iostream>
#include<string>
#include<stdlib.h>
#include"Play.h"
#include"main.h"

//randomly create position of monster and princess
void Play::Create_Position() {
    int mi(0), mj(0), mk(0), pi(0), pj(0), pk(0);
    srand(user_seed);
    while (mi == pi && mj == pj && mk == pk) {      //make sure monster and princess are not in the same place
        mi = (rand() % (HEIGHT- 0));                
        mj = (rand() % (LENGTH - 0));
        mk = (rand() % (LENGTH - 0));
        pi = (rand() % (HEIGHT - 0));
        pj = (rand() % (LENGTH - 0));
        pk = (rand() % (LENGTH - 0));
    }
    monroom  = room_num(mi, mj, mk);
    prinroom = room_num(pi,pj,pk);
}


// Set the rooms.here the castle is a **RECTANGULAR BUILDING** with specific directions and levels
// All the rooms are connected if they are adjacent for the simplicity of being understood and 
// tested( it can be easily set if you don't want all of them are connected. but it's not important)
void Play::SetRoom() {
    int i, j, k;                                //2 x 3 x 3 castle. 2 is height here
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < LENGTH; j++) {
            for (k = 0; k < WIDTH; k++) {
                rooms[i][j][k].SetName("room" + to_string(room_num(i,j,k)));
                rooms[i][j][k].dir_num = 6;
                // boundary case
                if (i == 0) {
                    rooms[i][j][k].dirList[5].IsOpen = 0; //down 0
                    rooms[i][j][k].dir_num--;
                }
                if (i == HEIGHT-1) {
                    rooms[i][j][k].dirList[4].IsOpen = 0; //up 0
                    rooms[i][j][k].dir_num--;
                }
                if (j == 0) {
                    rooms[i][j][k].dirList[1].IsOpen = 0; //south 0
                    rooms[i][j][k].dir_num--;
                }
                if (j == LENGTH-1) {
                    rooms[i][j][k].dirList[3].IsOpen = 0; //north 0
                    rooms[i][j][k].dir_num--;
                }
                if (k == 0) {
                    rooms[i][j][k].dirList[2].IsOpen = 0; //west 0
                    rooms[i][j][k].dir_num--;
                }
                if (k == WIDTH-1) {
                    rooms[i][j][k].dirList[0].IsOpen = 0; //east 0
                    rooms[i][j][k].dir_num--;
                }
            }
        }
    }
    rooms[0][0][0].SetName("lobby");        //set a lobby, here we set 0 0 0 as lobby
}

//welcome prompt
void Play::Welcome() {
    room ARoom = rooms[i][j][k];
    cout << "Welcome to the " << ARoom.GetName()
        << ". There are " << ARoom.dir_num << " exits:" ;
    ARoom.ListDir(); cout<< endl ;
}

//interact with player
void Play::Interact() {
    bool findPrin = false;          
    int cur_room;                                   //current room number
    while (1) {                                     //begin loop
        Welcome();                                        
        cur_room = room_num(i, j, k);     
        //catch the monster, game over
        if (cur_room != LOBBY && cur_room == monroom) {         
            cout << "you catch the monster! Game over"; break;
        }
        //find princess, take her away
        else if (cur_room != LOBBY && cur_room == prinroom) {
            if (findPrin == false) {
                cout << "you find a charming princess, go back to the lobby and take her away!" << endl;
                findPrin = true;
            }
        }
        //success(win)
        else if (cur_room == LOBBY && findPrin == true) {
            cout << "You have successfully rescured the princess" << endl;
            break;
        }
        cout << "Enter your command:";
        PosUpdate();                                    //update position
    }
}


//update position according to the instruction
void Play::PosUpdate() {
    string inst;
    cin >> inst;
    if (inst != "go") {                                 //wrong direction
        cout << "wrong instruction, try again" << endl;return;
    }
    cin >> inst;
    if (inst == "east" && k+1 != WIDTH)k++;
    else if (inst == "south" && j != 0)j--;
    else if (inst == "west" && k != 0)k--;
    else if (inst == "north" && j+1 != LENGTH)j++;
    else if (inst == "up" && i+1 != HEIGHT ) i++;
    else if (inst == "down" && i != 0)i--;
    else cout << "wrong direction, try again " << endl;
}

void Play::GetSeed() {
    int seed;
    cout << "Please Select a random routine from 1 to 10: " << endl;
    while (1) {
        cin >> seed;
        if (seed >= 1 && seed <= 10) {
            user_seed = seed; break;
        }
        else cout << "wrong seed, try again" << endl;
    }
}
