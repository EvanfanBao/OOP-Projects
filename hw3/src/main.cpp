#include<iostream>
#include<string>
#include<stdlib.h>

#include"Play.h"
#include"room.h"
#include"main.h"

int main() {
    Play play;
    play.SetRoom();
    play.GetSeed();
    play.Create_Position();
    play.Interact();
    getchar(); getchar();                 //hold on the console
}