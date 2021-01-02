#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include "TollBooth.h"
#include "Exceptions.h"
#include "Workers.h"
#include "Vehicle.h"
#include "utils.h"
#include "intervention.h"


using namespace std;

///Class FileManager - handles the files
///@param filename - first file that needs to be read
///@param tollbooth - Tollbooth object
///@param worker - Worker object
class FileManager {
    string filename;
    Utils *utilities = new Utils();
    TollBooth tollbooth = TollBooth();
    Worker worker = Worker();
    Technician tec;
    //Intervention interve;
    //BST<Intervention> intervention_tree;
public:
    friend class ProgramLoop;
    FileManager();
    explicit FileManager(string file);
    string getfilename() const;
    vector<Intervention> inter_vec;
    vector<TollBooth> t_vec;
    vector<Worker> w_vec;
    vector<Vehicle*> v_vec;
    void read_file(basic_string<char> file, int dif);
    void file_handler(TollBooth d1, string &str1);
    void File_lane_handler(TollBooth &d1, int j, vector<string> &init_split);
    void file_handler(Intervention &int1, string &str);
    priority_queue<Technician> read_tec_file(string &file);
    Technician file_tec_handler(Technician &t1, string &str);
    void file_handler(Worker &w1, string &str1);
    void file_handler(string &str1);
    void save_workers_file();
    void save_tolls_file(TollBooth &t1);
    void save_vehicles_file();
    void vehicle_write_helper(const Vehicle* v, ofstream &os);
    ~FileManager();


};







