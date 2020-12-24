#include <ostream>
#include "Workers.h"

///return the worker name
string Worker::get_name() const {
    return this->name;
}

/// return the worker schedule
string Worker::get_schedule() const {
    return this->schedule;
}

/// return the day_off the worker
string Worker::get_day_off() const {
    return this->day_off;
}

/// return if the worker is working or not
bool Worker::get_working() const {
    return this->working;
}

/// return vector of workers
vector<Worker> Worker::get_workers(){
    return this->workers;
}

/// return the worker id
int Worker::get_id() const {
    return this->id;
}

Worker::Worker() {
    /*this->name = ""; this->workers.txt = {}; this->on_vacation = false; this->day_off = false; this->id = 0; this->schedule = "";
    this->d_schedule = {"","","","","","",""};
    this->working = false;*/

}

/// Constructor that accepts a worker vector and then assigns it to this->workers
Worker::Worker(vector<Worker> &workers) {
    this->workers = workers;
}

/// return the daily_schedule struct of the desired worker
Worker::daily_schedule Worker::get_d_schedule() const {
    return this->d_schedule;
}

/// sets worker to working
void Worker::set_working() {
    working = 1;
}
/// sets worker to not working
void Worker::set_not_working() {
    working = 0;
}

///ostream operator overloading to write to a file
ostream &operator<<(ostream &os, const Worker &obj) {
    os << obj.get_name() << "|" << obj.get_id() << "|" << obj.get_d_schedule().monday << "/" << obj.get_d_schedule().tuesday << "/";
    os << obj.get_d_schedule().wednesday << "/" << obj.get_d_schedule().friday << "/" << obj.get_d_schedule().saturday;
    os << "/" << obj.get_d_schedule().sunday << "|" << obj.get_day_off() << "|" << obj.get_working() << "|" << endl;
    return os;
}

///Replaces the worker
///@param time - current time
///@param day - day of the week
pair<int, string> Worker::replace_worker(string &time, string &day) {
    for(vector<Worker>::iterator it = workers.begin(); it != workers.end(); it++){
        if(day == "Monday") {
            pair <string, string> compare = utilities->time_handler((*it).get_d_schedule().monday);
            if( utilities->time_handler(time, compare.first) && !(utilities->time_handler(time, compare.second)) && !((*it).get_working())){
                return make_pair((*it).get_id(),(*it).get_name());
            }
        }
        else if(day == "Tuesday") {
            pair <string, string> compare = utilities->time_handler((*it).get_d_schedule().tuesday);
            if( utilities->time_handler(time, compare.first) && !(utilities->time_handler(time, compare.second)) && !((*it).get_working())){
                return make_pair((*it).get_id(),(*it).get_name());
            }
        }
        else if(day == "Wednesday") {
            pair <string, string> compare = utilities->time_handler((*it).get_d_schedule().wednesday);
            if( utilities->time_handler(time, compare.first) && !(utilities->time_handler(time, compare.second)) && !((*it).get_working())){
                return make_pair((*it).get_id(),(*it).get_name());
            }
        }
        else if(day == "Thursday") {
            pair <string, string> compare = utilities->time_handler((*it).get_d_schedule().thursday);
            if( utilities->time_handler(time, compare.first) && !(utilities->time_handler(time, compare.second)) && !((*it).get_working())){
                return make_pair((*it).get_id(),(*it).get_name());
            }
        }
        else if(day == "Friday") {
            pair <string, string> compare = utilities->time_handler((*it).get_d_schedule().friday);
            if( utilities->time_handler(time, compare.first) && !(utilities->time_handler(time, compare.second)) && !((*it).get_working())){
                return make_pair((*it).get_id(),(*it).get_name());
            }
        }
        else if(day == "Saturday") {
            pair <string, string> compare = utilities->time_handler((*it).get_d_schedule().saturday);
            if( utilities->time_handler(time, compare.first) && !(utilities->time_handler(time, compare.second)) && !((*it).get_working())){
                return make_pair((*it).get_id(),(*it).get_name());
            }
        }
        else if(day == "Sunday") {
            pair <string, string> compare = utilities->time_handler((*it).get_d_schedule().sunday);
            if( utilities->time_handler(time, compare.first) && !(utilities->time_handler(time, compare.second)) && !((*it).get_working())){
                return make_pair((*it).get_id(),(*it).get_name());
            }
        }
        else throw NotAValidDay();
    }
    throw NoWorkerAvailable();
}

///If the workers need to be replaced, then this function will handle it
///@param t - current time
///@param element - pair containing "November 20 Monday 12:01:37" splitted
///@param obj - Worker object
pair<int, string> Worker::schedule_handler(string &t, pair<string, string> &element, Worker obj) {
    vector<string> split = utilities->split_string(t, '-');
    if (utilities->time_handler(element.second, split[0]) && !(utilities->time_handler(element.second, split[1]))) {
        return make_pair( obj.get_id(), obj.get_name() );
    }
    else {
        obj.set_not_working();
        cout << "Replacing..." << endl;
        try{
            replace_worker(element.second, element.first);
        }
        catch (NotAValidDay & exc){
            cerr << "An exception has been throw: " << exc.get_error() << endl;
            exit(EXIT_FAILURE);
        }
        catch (NoWorkerAvailable & exc){
            cerr << "An exception has been throw: " << exc.get_error() << endl;
            exit(EXIT_FAILURE);
        }
        pair<int,string> rep = replace_worker(element.second, element.first);
        return rep;
    }
}

///Search if the worker exists
///@param w_vector - worker vector
///@param id_number - worker id
void Worker::search_worker(vector<Worker> &w_vector, int id_number) {
    string n = "Worker not found";
    auto it = find_if(w_vector.begin(),w_vector.end(),[id_number](const Worker &obj) { return (obj.get_id() == id_number);} );
    try{
        if(it != w_vector.end()){
            (*it).set_working(); //set the worker status "working" to 1
        }
        else throw ElementNotInVec(n);
    }
    catch (ElementNotInVec &exc){
        cerr << "An exception has been throw: " << exc.get_error() << endl;
    }
}

///Handles the schedule of workers, seaking if the worker needs replacement
///@param w_vector - worker vector
///@param id_number - worker id
///@param time - current time
pair<int, string> Worker::booth_W_handler(vector<Worker> &w_vector, int id_number, string &time) {
    string n = "Worker not found";
    auto it = find_if(w_vector.begin(), w_vector.end(),
                      [id_number](const Worker &obj) { return (obj.get_id() == id_number); });
    try {
        if (!(it != w_vector.end())) throw ElementNotInVec(n);
    }
    catch (ElementNotInVec &exc) {
        cerr << "An exception has been throw: " << exc.get_error() << endl;
        exit(EXIT_FAILURE);
    }
    pair<string, string> element = utilities->time_splitter(time);
    if (element.first == "Monday") {
        return schedule_handler((string& ) (*it).get_d_schedule().monday,element, (*it));
    }
    else if (element.first == "Tuesday") {
        return schedule_handler((string& ) (*it).get_d_schedule().tuesday,element, (*it));
    }
    else if ( element.first == "Wednesday" ){
        return schedule_handler((string& ) (*it).get_d_schedule().wednesday,element, (*it));
    }
    else if ( element.first == "Friday" ) {
        return schedule_handler((string& ) (*it).get_d_schedule().friday,element, (*it));
    }
    else if ( element.first == "Saturday"){
        return schedule_handler((string& ) (*it).get_d_schedule().saturday,element, (*it));
    }
    else if ( element.first == "Sunday"){
        return schedule_handler((string& ) (*it).get_d_schedule().sunday,element, (*it));
    }
    else return make_pair(0,"");
}


