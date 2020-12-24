#pragma once
using namespace std;
#include <string>
#include <vector>
#include "Exceptions.h"
#include "utils.h"



///Class Worker - defines a worker
///@param name - worker name
///@param schedule - worker schedule
///@param daily_schedule - struct of the worker schedule organized by days of the week
///@param id - worker identification
///@param day_off - day of the week that this worker is not working
///@param working - true == working, false == !working

class Worker{
    string name;
    string schedule;
    struct daily_schedule{
        string monday, tuesday, wednesday, thursday, friday, saturday, sunday;
    } d_schedule;
    int id;
    string day_off;
    bool working;
    vector<Worker> workers;
    Utils *utilities = new Utils();
public:
    friend class ProgramLoop;
    friend class FileManager;
    Worker();
    Worker(vector<Worker> &workers);
    string get_name() const;
    string get_schedule() const;
    daily_schedule get_d_schedule() const;
    int get_id() const;
    string get_day_off() const;
    bool get_working() const;
    void set_working();
    void set_not_working();
    vector<Worker> get_workers();
    pair<int,string> replace_worker(string &time, string &day);
    pair<int,string> schedule_handler(string &t, pair<string,string> &element, Worker obj);
    static void search_worker(vector<Worker> &w_vector, int id_number);
    pair<int,string> booth_W_handler(vector<Worker> &w_vector, int id_number, string &time);
    friend ostream& operator<<(ostream &os, const Worker &obj);
};



