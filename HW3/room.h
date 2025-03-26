#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

class Room {
    friend ostream &print(ostream&, const Room&);
public:
    Room() = default;
    Room(const string &str, Room *e, Room *w, Room *n, Room *s, Room *u, Room *d) : roomname(str), east(e), west(w), north(n), south(s), up(u), down(d) {}
    Room(const string &str) : roomname(str) {}
    string RoomName() const { return roomname; }
    Room* East() const { return east; }
    Room* West() const { return west; }
    Room* North() const { return north; }
    Room* South() const { return south; }
    Room* Up() const { return up; }
    Room* Down() const { return down; }
    void SetEast(Room* e) { east = e; }
    void SetWest(Room* w) { west = w; }
    void SetNorth(Room* n) { north = n; }
    void SetSouth(Room* s) { south = s; }
    void SetUp(Room* u) { up = u; }
    void SetDown(Room* d) { down = d; }
private:
    string roomname;
    Room* east = nullptr;
    Room* west = nullptr;
    Room* north = nullptr;
    Room* south = nullptr;
    Room* up = nullptr;
    Room* down = nullptr;
};

ostream &print(ostream &os, const Room &room)
{
    if(room.RoomName() == "lobby") {
        os << "Welcome to the lobby. There are 3 exits: east, west and up." << endl;
        os << "Enter your command:" << endl;
    }
    else if(room.RoomName() == "kitchen") {
        os << "Welcome to the kitchen. There are 3 exits: west, north and south." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "Find a chef here!!!" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "*****" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "role: Hello, do you know where the princess is?" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "chef: No, but I know there is a monster around here." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "role: Thanks. Bye!" << endl;
        os << "*****" << endl;
        os << "Enter your command:" << endl;
    }
    else if(room.RoomName() == "monster") {
        os << "Oh no!!! A monster!!!" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "You are dead!" << endl;
    }
    else if(room.RoomName() == "restroom") {
        os << "Welcome to the restroom. There are 1 exits: north." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "There is nothing." << endl;
        os << "Enter your command:" << endl;
    }
    else if(room.RoomName() == "diningroom") {
        os << "Welcome to the dining room. There are 2 exits: east and north." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "Find a maid here!!!." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "*****" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "role: Hello, do you know where the princess is?" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "maid: No, but I know princess always stays at the second floor." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "role: Thanks. Bye!" << endl;
        os << "*****" << endl;
        os << "Enter your command:" << endl;
    }
    else if(room.RoomName() == "bedroom") {
        os << "Welcome to the bedroom. There are 1 exits: south." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "It looks like the princess slept here, but she's not here now。" << endl;
        os << "Enter your command:" << endl;
    }
    else if(room.RoomName() == "livingroom") {
        os << "Welcome to the living room. There are 2 exits: west and down." << endl;
        os << "Enter your command:" << endl;
    }
    else if(room.RoomName() == "princess") {
        os << "Princess is here!!!" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "*****" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "role: Princess, are you okay?" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "princess: Yes, but I want to leave here." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "role: OK, I will take you to the exit. Let's go!" << endl;
        os << "*****" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        os << "Please retrace your steps and get the princess out of here" << endl;
        os << "Enter your command:" << endl;
    }
    else {
        os << "Invalid room name!" << endl;
    }

    return os;
}


#endif
