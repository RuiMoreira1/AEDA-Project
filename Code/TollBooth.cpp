#include "TollBooth.h"


TollBooth::TollBooth(vector<TollBooth> &vec) {
    T_vector.assign(vec.begin(),vec.end());
}
/// return tollbooth current location
string TollBooth::get_location() const {
    return this->location;
}
/// return tollbooth schedule worker path
string TollBooth::get_path() const {
    return this->path_schedule;
}

/// return the amount of workers in the tollbooth
int TollBooth::get_a_workers() const {
    return this->amount_of_workers;
}

/// total cash flow in the tollbooth
double TollBooth::get_cash_flow() const {
    return this->cash_flow;
}

/// return the number of existing lanes in the tollbooth
int TollBooth::get_lanes() const {
    return this->lanes;
}

/// return if the are exiting or entering an highway
bool TollBooth::get_ent_exit() const {
    return this->entrance_exit;
}

/// return tollboth vector
vector <TollBooth> TollBooth::get_Tvec() {
    return this->T_vector;
}

/// return a struct that contains information about the lanes
TollBooth::lane_h TollBooth::get_laneh() const {
    return this->lane_handler;
}

/// return a vector of lane_h structs
vector<TollBooth::lane_h> TollBooth::get_v_laneh() const {
    return this->lane_vec_handler;
}

/// operator overloading to use in sort methods
bool TollBooth::operator<(TollBooth const &obj) {
    if(location < obj.location) return true;
    else if(location == obj.location) return false;
    return false;
}


/// increase the tollbooth cash flow everytime a payment is done
void TollBooth::set_cash_flow(double i) {
    this->cash_flow += i;
}

/// ostream operator overloading to write to file
ostream &operator<<(ostream &os, const TollBooth &obj) {
    os << obj.get_location() << "|";
    if(obj.get_ent_exit()) os << "Exit" << "|";
    else os << "In" << "|";
    for(int i = 0; i < obj.get_v_laneh().size(); i++){
        os << obj.get_v_laneh()[i].lane_number << "-" << obj.get_v_laneh()[i].lane_daily_traffic << "-" << obj.get_v_laneh()[i].lane_type << "-";
        os << obj.get_v_laneh()[i].working_lane << "-" << obj.get_v_laneh()[i].lane_cash_flow << "-" << obj.get_v_laneh()[i].current_worker;
        if(i != obj.get_v_laneh().size()-1) os << "/";
    }
    os << "|" << obj.cash_flow << "|" << obj.amount_of_workers << "|" << obj.path_schedule << "|" << endl;
    return os;
}

///Tollbooth vector sorter
void TollBooth::tvec_sort() {
    sort(T_vector.begin(),T_vector.end(),[](TollBooth &t1, TollBooth &t2)->bool {return t1 < t2;});
}

///Search if a specific tollbooth exister returns 1 if the tb doesn't exist
///@param t_vector - tollbooth vector
///@param exit - if the tollbooth is an exit == true, false otherwise
///@param tollname - the tollbooth name
int TollBooth::search_t_vec(const vector <TollBooth> &t_vector, bool exit, basic_string<char> tollname) {
    string n = "TollBooth not found";
    auto it = find_if(t_vector.begin(),t_vector.end(),[&tollname,exit](const TollBooth &obj) {return (obj.get_location() == tollname && obj.get_ent_exit() == exit);});
    try{
        if(it != t_vector.end()){
            return distance(t_vector.begin(),it);
        }
        else{
            throw ElementNotInVec(n);
        }
    }
    catch (ElementNotInVec &exc){
        cerr << "An exception has been raised: " << exc.get_error() << endl;
        return -1;
    }
}
