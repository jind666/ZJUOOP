#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "room.h"

using namespace std;

int main()
{
    Room lobby("lobby");
    Room kitchen("kitchen");
    Room monster("monster");
    Room rest_room("restroom");
    Room dining_room("diningroom");
    Room bed_room("bedroom");
    Room living_room("livingroom");
    Room princess("princess");

    lobby.SetEast(&kitchen);
    lobby.SetWest(&dining_room);
    lobby.SetSouth(nullptr);
    lobby.SetNorth(nullptr);
    lobby.SetUp(&living_room);
    lobby.SetDown(nullptr);

    kitchen.SetEast(nullptr);
    kitchen.SetWest(&lobby);
    kitchen.SetSouth(&rest_room);
    kitchen.SetNorth(&monster);
    kitchen.SetUp(nullptr);
    kitchen.SetDown(nullptr);

    monster.SetEast(nullptr);
    monster.SetWest(nullptr);
    monster.SetSouth(&kitchen);
    monster.SetNorth(nullptr);
    monster.SetUp(nullptr);
    monster.SetDown(nullptr);

    rest_room.SetEast(nullptr);
    rest_room.SetWest(nullptr);
    rest_room.SetSouth(nullptr);
    rest_room.SetNorth(&kitchen);
    rest_room.SetUp(nullptr);
    rest_room.SetDown(nullptr);

    dining_room.SetEast(&lobby);
    dining_room.SetWest(nullptr);
    dining_room.SetSouth(nullptr);
    dining_room.SetNorth(&bed_room);
    dining_room.SetUp(nullptr);
    dining_room.SetDown(nullptr);

    bed_room.SetEast(nullptr);
    bed_room.SetWest(nullptr);
    bed_room.SetSouth(&dining_room);
    bed_room.SetNorth(nullptr);
    bed_room.SetUp(nullptr);
    bed_room.SetDown(nullptr);

    living_room.SetEast(nullptr);
    living_room.SetWest(&princess);
    living_room.SetSouth(nullptr);
    living_room.SetNorth(nullptr);
    living_room.SetUp(nullptr);
    living_room.SetDown(&lobby);

    princess.SetEast(&living_room);
    princess.SetWest(nullptr);
    princess.SetSouth(nullptr);
    princess.SetNorth(nullptr);
    princess.SetUp(nullptr);
    princess.SetDown(nullptr);

    string command;
    bool IsPrincess = false;
    bool IsMonster = false;
    bool IsFinished = false;
    Room *current_room = &lobby;

    print(cout, lobby);
    while(true) {
        getline(cin, command);

        if(command == "go east") {
            if(current_room->East() == nullptr){
                cout << "There is no room!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Enter your command:" << endl;
            }
            else if(current_room->East()->RoomName() == "princess"){
                IsPrincess = true;
                print(cout, princess);
                current_room = current_room->East();
            }
            else if(current_room->East()->RoomName() == "monster"){
                IsMonster = true;
                print(cout, monster);
            }
            else if(IsPrincess && current_room->East()->RoomName() == "lobby"){
                cout << "You win!" << endl;
                IsFinished = true;
            }
            else{
                current_room = current_room->East();
                print(cout, *current_room);
            }
        }
        else if(command == "go west") {
            if(current_room->West() == nullptr){
                cout << "There is no room!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Enter your command:" << endl;
            }
            else if(current_room->West()->RoomName() == "princess"){
                IsPrincess = true;
                print(cout, princess);
                current_room = current_room->West();
            }
            else if(current_room->West()->RoomName() == "monster"){
                IsMonster = true;
                print(cout, monster);
            }
            else if(IsPrincess && current_room->West()->RoomName() == "lobby"){
                cout << "You win!" << endl;
                IsFinished = true;
            }
            else{
                current_room = current_room->West();
                print(cout, *current_room);
            }
        }
        else if(command == "go south") {
            if(current_room->South() == nullptr){
                cout << "There is no room!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Enter your command:" << endl;
            }
            else if(current_room->South()->RoomName() == "princess"){
                IsPrincess = true;
                print(cout, princess);
                current_room = current_room->South();
            }
            else if(current_room->South()->RoomName() == "monster"){
                IsMonster = true;
                print(cout, monster);
            }
            else if(IsPrincess && current_room->South()->RoomName() == "lobby"){
                cout << "You win!" << endl;
                IsFinished = true;
            }
            else{
                current_room = current_room->South();
                print(cout, *current_room);
            }
        }
        else if(command == "go north") {
            if(current_room->North() == nullptr){
                cout << "There is no room!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Enter your command:" << endl;
            }
            else if(current_room->North()->RoomName() == "princess"){
                IsPrincess = true;
                print(cout, princess);
                current_room = current_room->North();
            }
            else if(current_room->North()->RoomName() == "monster"){
                IsMonster = true;
                print(cout, monster);
            }
            else if(IsPrincess && current_room->North()->RoomName() == "lobby"){
                cout << "You win!" << endl;
                IsFinished = true;
            }
            else{
                current_room = current_room->North();
                print(cout, *current_room);
            }
        }
        else if(command == "go up") {
            if(current_room->Up() == nullptr){
                cout << "There is no room!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Enter your command:" << endl;
            }
            else if(current_room->Up()->RoomName() == "princess"){
                IsPrincess = true;
                print(cout, princess);
                current_room = current_room->Up();
            }
            else if(current_room->Up()->RoomName() == "monster"){
                IsMonster = true;
                print(cout, monster);
            }
            else if(IsPrincess && current_room->Up()->RoomName() == "lobby"){
                cout << "You win!" << endl;
                IsFinished = true;
            }
            else{
                current_room = current_room->Up();
                print(cout, *current_room);
            }
        }
        else if(command == "go down") {
            if(current_room->Down() == nullptr){
                cout << "There is no room!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Enter your command:" << endl;
            }
            else if(current_room->Down()->RoomName() == "princess"){
                IsPrincess = true;
                print(cout, princess);
                current_room = current_room->Down();
            }
            else if(current_room->Down()->RoomName() == "monster"){
                IsMonster = true;
                print(cout, monster);
            }
            else if(IsPrincess && current_room->Down()->RoomName() == "lobby"){
                cout << "You win!" << endl;
                IsFinished = true;
            }
            else{
                current_room = current_room->Down();
                print(cout, *current_room);
            }
        }
        else{
            cout << "Invalid command!" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "Enter your command:" << endl;
        }

        if(IsFinished || IsMonster){
            break;
        }
    }

    return 0;
}
