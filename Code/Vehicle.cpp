#include "Vehicle.h"

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

Vehicle::Vehicle(int cl_n, string &n, int dl, int id, int age, string &lp, bool vv, int y, int m, int c_kms, int axis, double w, double h, string &f_type, string &tb, bool io, string &time) : Client(n,dl,id,age) {
    this->license_plate = lp;
    this->time = time;
    fuel_type = f_type;
    tollbooth = tb;
    current_kms = c_kms;
    year = y; month = m; n_axis = axis; weight = w;
    v_verde = vv;
    in_out = io;
    height = h;
    what_classe = cl_n;
}

Vehicle::Vehicle(vector<Vehicle *> &v) {
    vehicle_vector = v;
}


double Vehicle::get_pricekm() const {
    return this->price_km;
}

string Vehicle::get_lp() const {
    return this->license_plate;
}

bool Vehicle::get_vverde() const {
    return this->v_verde;
}

int Vehicle::get_year() const {
    return this->year;
}

int Vehicle::get_month() const {
    return this->month;
}

int Vehicle::get_naxis() const {
    return this->n_axis;
}

double Vehicle::get_weight() const {
    return this->weight;
}

string Vehicle::get_ftype() const {
    return this->fuel_type;
}

double Vehicle::get_currentkms() const {
    return this->current_kms;
}

string Vehicle::get_tollb() const {
    return this->tollbooth;
}

bool Vehicle::get_in_out() const {
    return this->in_out;
}

string Vehicle::get_time() const {
    return this->time;
}

double Vehicle::get_height() const {
    return this->height;
}

int Vehicle::get_what_classe() const {
    return this->what_classe;
}

vector<Vehicle *> Vehicle::get_v_vector() const {
    return vehicle_vector;
}

double classe_1::get_pricekm() const {
    return this->price_km;
}

double classe_1::get_bill() const {
    return this->get_currentkms()*price_km;
}

ostream& operator<<(ostream &os, const classe_1 &obj) {
    os << "You travelled a distance equivalent to " << obj.get_currentkms() << " kilometers" << endl;
    os << "The price per kilometer for a vehicle of your classe (" << obj.get_what_classe() << ") is " << obj.get_pricekm() << " euros" << endl;
    os << "Which gives a total value of " << obj.get_bill() << " euros";
    return os;
}


double classe_2::get_pricekm() const {
    return this->price_km;
}

double classe_2::get_bill() const {
    return this->get_currentkms()*price_km;
}

ostream &operator<<(ostream &os, const classe_2 &obj) {
    os << "You travelled a distance equivalent to " << obj.get_currentkms() << " kilometers" << endl;
    os << "The price per kilometer for a vehicle of your classe (" << obj.get_what_classe() << ") is " << obj.get_pricekm() << " euros" << endl;
    os << "Which gives a total value of " << obj.get_bill() << " euros";
    return os;
}

string classe_3::get_ctype() const {
    return this->cargo_type;
}

double classe_3::get_pricekm() const {
    return this->price_km;
}

double classe_3::get_add_tax() const {
    return this->additional_tax;
}

double classe_3::get_bill() const {
    if(this->get_ctype() == "explosive" || this->get_ctype() == "bus"){
        return (this->get_currentkms()*price_km)+additional_tax;
    }
    return this->get_currentkms()*price_km;
}

ostream &operator<<(ostream &os, const classe_3 &obj) {
    os << "You travelled a distance equivalent to " << obj.get_currentkms() << " kilometers" << endl;
    os << "The price per kilometer for a vehicle of your classe (" << obj.get_what_classe() << ") is " << obj.get_pricekm() << " euros" << endl;
    if(obj.get_ctype() == "explosive" || obj.get_ctype() == "bus") {
        os << "You are carrying a taxable payload so are going to have to pay an additional tax " << obj.get_add_tax() << endl;
    }
    os << "Which gives a total value of " << obj.get_bill() << " euros";
    return os;
}

double classe_4::get_pricekm() const {
    return this->price_km;
}

double classe_4::get_add_tax() const {
    return this->additional_tax;
}

double classe_4::get_bill() const {
    if(this->get_ctype() == "explosive" || this->get_ctype() == "bus"){
        return (this->get_currentkms()*price_km)+additional_tax;
    }
    return this->get_currentkms()*price_km;
}

int classe_4::get_trailers() const {
    return this->n_of_trailers;
}

ostream &operator<<(ostream &os, const classe_4 &obj) {
    os << "You travelled a distance equivalent to " << obj.get_currentkms() << " kilometers" << endl;
    os << "The price per kilometer for a vehicle of your classe (" << obj.get_what_classe() << ") is " << obj.get_pricekm() << " euros" << endl;
    if(obj.get_ctype() == "explosive" || obj.get_ctype() == "bus") {
        os << "You are carrying a taxable payload so are going to have to pay an additional tax " << obj.get_add_tax() << endl;
    }
    os << "Which gives a total value of " << obj.get_bill() << " euros";
    return os;
}
