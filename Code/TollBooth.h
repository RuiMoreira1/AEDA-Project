#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <queue>
#include "technician.h"
#include "Exceptions.h"

/**TollBooth Class
 * @param T_vector - tollbooth vector
 * @param location - tollbooth location
 * @param T_vector - tollbooth vector
 * @param location - tollbooth location
 * @param path_schedule - name of the file that contains schedule of workers of that tollbooth
 * @param lane_h - a struct that contains each lane specific information
 * @param lane_vec_handler - vector of lane__h structs
 * @param amount_of_workers - number of workers working in tht tollbooth
 * @param lanes - number of lanes
 * @param cash_flow - current tollbooth cash flow
 * @param entrance_exit - true if exit tollbooth, false otherwise
*/
class TollBooth {
    vector<TollBooth> T_vector;
    string location, path_schedule;
    priority_queue<Technician> tec_queue;
    struct lane_h {
        int lane_number = 0;
        int lane_daily_traffic = 0;
        double lane_cash_flow = 0;
        bool lane_type = false; //vverde == 1, normal == 0
        bool working_lane = false; //working == 1, not working == 0
        string current_worker = "None";
    }lane_handler;
    vector<lane_h> lane_vec_handler;
    int amount_of_workers, lanes;
    double cash_flow;
    bool entrance_exit; // type == 0, normal type == 1, scutt // entrance == 0 exit == 1;
public:
    friend class FileManager;
    friend class ProgramLoop;
    TollBooth() = default;
    explicit TollBooth(vector<TollBooth> &vec);
    priority_queue<Technician> get_pq_tec();
    void prio_teste();
    vector<TollBooth> get_Tvec();
    string get_location() const;
    string get_path() const;
    vector<lane_h> get_v_laneh() const;
    void set_cash_flow(double i);
    bool get_ent_exit() const;
    void tvec_sort();
    int search_t_vec(const vector<TollBooth> &t_vector, bool exit, basic_string<char> tollname);
    bool operator<  (TollBooth const &obj);
    friend ostream& operator<<(ostream &os, const TollBooth &obj);

};




