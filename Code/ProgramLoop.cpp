#include "ProgramLoop.h"
#include <iostream>

///The program main loop where files are read and written
void ProgramLoop::ProgramLoop2() {
    d1->read_file(d1->getfilename(),1); //Read the tollbooth.txt file
    d1->read_file("vehicles.txt",2);
    TollBooth t1(d1->t_vec);
    Vehicle *v1 = new Vehicle(d1->v_vec);
    t1.tvec_sort();
    //d1->read_file("interventions.txt",3);
    t1.prio_teste();
    int classe = 0;
    for(int i = 0; i < v1->get_v_vector().size(); i++){
        classe = v1->get_v_vector()[i]->get_what_classe();;
        if( classe == 1 ){
            classe_1* x = dynamic_cast<classe_1*>(v1->get_v_vector()[i]);
            classe_handler(x,t1,x->get_time());
            cout << endl; cout << endl;
        }
        else if ( classe == 2 ){
            classe_2* x = dynamic_cast<classe_2*>(v1->get_v_vector()[i]);
            classe_handler(x,t1,x->get_time());
            cout << endl; cout << endl;
        }
        else if ( classe == 3 ){
            classe_3* x = dynamic_cast<classe_3*>(v1->get_v_vector()[i]);
            classe_handler(x,t1,x->get_time());
            cout << endl; cout << endl;
        }
        else if ( classe == 4 ){
            classe_4* x = dynamic_cast<classe_4*>(v1->get_v_vector()[i]);
            classe_handler(x,t1,x->get_time());
            cout << endl; cout << endl;
        }
    }
    d1->save_workers_file();
    d1->save_tolls_file(t1);
    d1->save_vehicles_file();
    delete v1;
}


///Choose the lane where the traffic is lower, considering via verde options
///@param via_Verde - true vehicle has via verde, false otherwise
///@param toll - TollBooth object
pair<int,int> ProgramLoop::lane_selector(bool via_Verde, TollBooth &toll) {
    string n = "Tollbooth closed";
    int lane = 0, traffic = INT_MAX, v_lane = 0;
    for( int k = 0; k < toll.get_v_laneh().size();  k++){
        if(toll.get_v_laneh()[k].working_lane) {
            if(via_Verde && toll.get_v_laneh()[k].lane_type && toll.get_v_laneh()[k].lane_daily_traffic < traffic) {
                traffic = toll.get_v_laneh()[k].lane_daily_traffic;
                lane = toll.get_v_laneh()[k].lane_number;
                v_lane = k;
            }
            else if(!(via_Verde) && !(toll.get_v_laneh()[k].lane_type) && toll.get_v_laneh()[k].lane_daily_traffic < traffic){
                traffic = toll.get_v_laneh()[k].lane_daily_traffic;
                lane = toll.get_v_laneh()[k].lane_number;
                v_lane = k;
            }
        }
    }
    if(lane == 0) throw NoLanesAvailable(n);
    return pair<int,int>(lane,v_lane);
}

///Handles the exit of the highway, increasing the tollbooth cash flow and handles the worker replacing process
///@param obj - Template obj
///@param ob2 - FileManager object
///@param index - tollbooth vector current index
///@param index2 - current lane of that tollbooth, index of the vector of lane_h
///@param time - current time
template <class T>
void ProgramLoop::handle_exit(T &obj, TollBooth &t_obj, int index, int index2, string time, Worker *w_obj) {
    if(!(obj->get_vverde())){
        pair<int,string> schedule_handler = w_obj->booth_W_handler(w_obj->workers, stoi(t_obj.get_Tvec()[index].get_v_laneh()[index2].current_worker), time);
        w_obj->search_worker(w_obj->workers,schedule_handler.first); //change the worker status to working
        t_obj.get_Tvec()[index].get_v_laneh()[index2].current_worker = schedule_handler.second;
        cout << "Hello sir, my name is " << schedule_handler.second << endl;
        cout << *obj;
        if( bill.count(obj->get_id()) > 0 ) bill[obj->get_id()] += obj->get_bill();
        else bill.insert(pair<int,double>(obj->get_id(),obj->get_bill()));
        t_obj.T_vector[index].lane_vec_handler[index2].lane_cash_flow += obj->get_bill();
        t_obj.T_vector[index].set_cash_flow(obj->get_bill());
        t_obj.T_vector[index].lane_vec_handler[index2].lane_daily_traffic++;
    }
    else{
        cout << "##########################MACHINE SCREEN##########################" << endl;
        cout << *obj;
        if( bill.count(obj->get_id()) > 0 ) bill[obj->get_id()] += obj->get_bill();
        else bill.insert(pair<int,double>(obj->get_id(),obj->get_bill()));
        t_obj.T_vector[index].lane_vec_handler[index2].lane_cash_flow += obj->get_bill();
        t_obj.T_vector[index].set_cash_flow(obj->get_bill());
        t_obj.T_vector[index].lane_vec_handler[index2].lane_daily_traffic++;
    }
}

///Handles the entrance in the highway
///@param obj - Template object
///@param ob2- FileManager object
///@param index - tollbooth vector index
///@param index2 - current lane of that tollbooth, index of the vector of lane_h
template<class T>
void ProgramLoop::handle_entrance(T &obj, TollBooth &t_obj, int index, int index2) {
    if(obj->get_vverde()){
        cout << "Welcome to " << obj->get_tollb() << " drive safe!" << endl;
        t_obj.T_vector[index].get_v_laneh()[index2].lane_daily_traffic++;
    }
    else{
        cout << "Welcome to " << obj->get_tollb() << ", please take a ticket, drive safe!" << endl;
        t_obj.T_vector[index].get_v_laneh()[index2].lane_daily_traffic++;
    }
}

///Functions that manages the entrance or exit of a vehicle
///@param obj - Template object
///@param ob2- FileManager object
///@param time - current time
template<class T>
void ProgramLoop::classe_handler(T &obj, TollBooth &t_obj, string time) {
    pair<int,int> selected_lane;
    string error = "Not in tollboth vector";
    int index = t_obj.search_t_vec(t_obj.get_Tvec(), obj->get_in_out(), obj->get_tollb());
    try { if(index == -1) throw ElementNotInVec (error); }
    catch (ElementNotInVec &exc){
        cerr << "An exception has been throw: " << exc.get_error() << endl;
        exit(EXIT_FAILURE);
    }
    d1->read_file(t_obj.get_Tvec()[index].get_path(),0); //worker vector created;
    Worker *w1 = new Worker(d1->w_vec);
    try{selected_lane = lane_selector(obj->get_vverde(), t_obj.get_Tvec()[index]);}
    catch (NoLanesAvailable & exc){
        cerr << "An error was raised: " << exc.get_error() << endl;
        exit(EXIT_FAILURE);
    }
    if(obj->get_in_out()){
        //Exiting needs to pay;
        handle_exit(obj,t_obj,index,selected_lane.second,time,w1);
    }
    else{
        //Entering the highway;
        handle_entrance(obj,t_obj,index,selected_lane.second);
    }
}
