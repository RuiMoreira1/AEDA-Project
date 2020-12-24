#pragma once
using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Client.h"

///Class Vehicle - that has classe 1,2,3,4 has derived classes
///@param license_plate - vehicle license_plate
///@param v_verde - true == has via verde, false otherwise
///@param year - vehicle year
///@param month - vehicle month
///@param current_kms - if exiting in tollbooth, the kilometers that the vehicle travelled
///@param n_axis - number of axis of the vehicle
///@param what_classe - the vehicle classe
///@param weight - vehicle weight
///@param height - vehicle height
///@param fuel_type - vehicle fuel type
///@param tollbooth - current tollbooth
///@param in_out - in == false, out == true, if the vehicle is entering or exiting the highway
///@param time - the time that he is coming through the tollbooth
///@param price_km - the tollbooth km_price


class Vehicle : public Client {
    string license_plate;
    bool v_verde; //true - has vverde, false otherwise
    int year,month;
    int current_kms;
    int n_axis;
    int what_classe;
    double weight;
    double height;
    string fuel_type; //Electrical/Diesel/Petrol
    string tollbooth; bool in_out;
    string time;
    double price_km;
    vector<Vehicle*> vehicle_vector;
public:
    friend class FileManager;
    Vehicle() = default;
    Vehicle( vector<Vehicle*> &v );
    Vehicle(int cl_n, string &n, int dl, int id, int age, string &lp, bool vv, int y, int m, int c_kms, int axis, double w, double h, string &f_type, string &tb, bool io, string &time);
    string get_lp() const;
    double get_currentkms() const;
    bool get_vverde() const;
    int get_year() const;
    int get_month() const;
    int get_naxis() const;
    double get_weight() const;
    double get_height() const;
    string get_ftype() const;
    string get_tollb() const;
    bool get_in_out() const;
    string get_time() const;
    int get_what_classe() const;
    vector<Vehicle*> get_v_vector() const;
    virtual double get_pricekm() const;
};

//Classe_1 - vehicles of classe 1
///@param price_km - classe 1 vehicles km price
class classe_1 : public Vehicle{
    double price_km = 0.07;
public:
    classe_1() =default;
    ///Vehicle constructor
///@param cl_n - classe number
///@param n - client name
///@param dl - drivers license
///@param id - client id
///@param age - client age
///@param lp - vehicle license plate
///@param vv - vehicle has via ver or not
///@param y - vehicle year
///@param m - vehicle month
///@param c_kms - vehicle current_kms
///@param axis - vehicle axis
///@param w - vehicle weight
///@param h - vehicle height
///@param f_type - vehicle fuel type
///@param tb - current tollbooth
///@param io - in or out
///@param time - current time when passing the tollbooth
    classe_1(int cl_n, string &n, int dl, int id, int age, string &lp, bool vv, int y, int m, int c_kms, int axis, double w, double h, string &f_type, string &tb, bool io, string &time): Vehicle(cl_n,n,dl,id,age,lp,vv,y,m,c_kms,axis,w,h,f_type,tb,io,time){};
    double get_pricekm() const;
    double get_bill() const;
    friend ostream& operator<<(ostream& os, const classe_1 &obj);
};

//Classe_2 - vehicles of classe 2
///@param price_km - classe 2 vehicles km price
class classe_2 : public Vehicle{
    double price_km = 0.13;
public:
    classe_2() =default;
    ///Vehicle constructor
///@param cl_n - classe number
///@param n - client name
///@param dl - drivers license
///@param id - client id
///@param age - client age
///@param lp - vehicle license plate
///@param vv - vehicle has via ver or not
///@param y - vehicle year
///@param m - vehicle month
///@param c_kms - vehicle current_kms
///@param axis - vehicle axis
///@param w - vehicle weight
///@param h - vehicle height
///@param f_type - vehicle fuel type
///@param tb - current tollbooth
///@param io - in or out
///@param time - current time when passing the tollbooth
    classe_2(int cl_n, string &n, int dl, int id, int age, string &lp, bool vv, int y, int m, int c_kms, int axis, double w, double h, string &f_type, string &tb, bool io, string &time): Vehicle(cl_n,n,dl,id,age,lp,vv,y,m,c_kms,axis,w,h,f_type,tb,io,time){}
    double get_pricekm() const;
    double get_bill() const;
    friend ostream& operator<<(ostream& os, const classe_2 &obj);
};

//Classe_3 - vehicles of classe 3
///@param price_km - classe 3 vehicles km price
///@param additional_tax - if the vehicle has an explosive cargo or is a bus then has to pay an additional tax
///@param cargo_type - the type of cargo that he carries
class classe_3 : public Vehicle{
    double price_km = 0.30;
    double additional_tax = 1.55;
    string cargo_type;
public:
    classe_3() =default;
    ///Vehicle constructor
///@param cl_n - classe number
///@param n - client name
///@param dl - drivers license
///@param id - client id
///@param age - client age
///@param lp - vehicle license plate
///@param vv - vehicle has via ver or not
///@param y - vehicle year
///@param m - vehicle month
///@param c_kms - vehicle current_kms
///@param axis - vehicle axis
///@param w - vehicle weight
///@param h - vehicle height
///@param f_type - vehicle fuel type
///@param tb - current tollbooth
///@param io - in or out
///@param time - current time when passing the tollbooth
///@param c_type - cargo_type
    classe_3(int cl_n,string &n, int dl, int id, int age, string &lp, bool vv, int y, int m, int c_kms, int axis, double w, double h, string &f_type, string &tb, bool io, string &time, string &c_type): Vehicle(cl_n,n,dl,id,age,lp,vv,y,m,c_kms,axis,w,h,f_type,tb,io,time){
        std::transform(c_type.begin(), c_type.end(), c_type.begin(),[](unsigned char c){ return std::tolower(c); });
        this->cargo_type = c_type;
    }
    string get_ctype() const;
    virtual double get_pricekm() const;
    virtual double get_add_tax() const;
    virtual double get_bill() const;
    friend ostream& operator<<(ostream& os, const classe_3 &obj);
};

//Classe_4 - vehicles of classe 4
///@param price_km - classe 4 vehicles km price
///@param additional_tax - if the vehicle has an explosive cargo or is a bus then has to pay an additional tax
///@param n_of_trailers - number of trailers that the vehicles carries
class classe_4 : public classe_3{
    double price_km = 0.37;
    double additional_tax = 1.55;
    int n_of_trailers;
public:
    classe_4() =default;
    ///Vehicle constructor
///@param cl_n - classe number
///@param n - client name
///@param dl - drivers license
///@param id - client id
///@param age - client age
///@param lp - vehicle license plate
///@param vv - vehicle has via ver or not
///@param y - vehicle year
///@param m - vehicle month
///@param c_kms - vehicle current_kms
///@param axis - vehicle axis
///@param w - vehicle weight
///@param h - vehicle height
///@param f_type - vehicle fuel type
///@param tb - current tollbooth
///@param io - in or out
///@param time - current time when passing the tollbooth
///@param c_type - cargo_type
///@param n_trailer - number of trailers
    classe_4(int cl_n, string &n, int dl, int id, int age, string &lp, bool vv, int y, int m, int c_kms, int axis, double w, double h, string &f_type, string &tb, bool io, string &time, string &c_type, int n_trailer): classe_3(cl_n,n,dl,id,age,lp,vv,y,m,c_kms,axis,w,h,f_type,tb,io,time,c_type){
        this->n_of_trailers = n_trailer;
    }
    int get_trailers() const;
    double get_pricekm() const;
    double get_add_tax() const;
    double get_bill() const;
    friend ostream& operator<<(ostream& os, const classe_4 &obj);

};



