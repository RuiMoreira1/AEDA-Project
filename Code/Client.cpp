#include "Client.h"

///Client constructor
///@param n - client name
///@param dl - client drivers license
///@param id - client id
///@param age - client age
Client::Client(string &n, int dl, int id, int age) {
   this->name = n;
   this->driver_license = dl;
   this->id = id;
   this->age = age;
}

/// return the current client name
string Client::get_name() const {
    return this->name;
}

/// returns the client id
int Client::get_id() const {
    return this->id;
}


/// returns the client age
int Client::get_Age() const {
    return this->age;
}

/// return the client drivers license
int Client::get_drivel() const {
    return this->driver_license;
}
