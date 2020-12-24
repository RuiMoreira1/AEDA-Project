#pragma once
using namespace std;
#include <string>
#include <vector>

///Class Client - Base class that has vehicle has derived class
///@param name - client name
///@param driver_license - client driver_license number
///@param id - client identification
class Client {
    string name;
    int driver_license, id;
    int age;
public:
    Client() = default;
    Client(string &n, int dl, int id, int age);
    string get_name() const;
    int get_drivel() const;
    int get_id() const;
    int get_Age() const;


};

