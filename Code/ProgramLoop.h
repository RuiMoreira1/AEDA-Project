#pragma once
#include <map>
#include "FileManager.h"

///Class ProgramLoop - where the loop is managed
///@param d1 - FileManager object
///@param bill - customer bill

class ProgramLoop {
    FileManager *d1 = new FileManager("tollbooth.txt");
    map<int,double> bill;
public:
    void ProgramLoop2();
    pair<int,int> lane_selector(bool via_Verde, TollBooth &toll);
    template <class T> void classe_handler(T &obj, TollBooth &t_obj, string time);
    template <class T> void handle_exit(T &obj, TollBooth &t_obj, int index, int index2, string time, Worker *w_obj);
    template <class T> void handle_entrance(T &obj, TollBooth &t_obj, int index, int index2);
};



