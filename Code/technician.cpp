#include "technician.h"

///Get Technician name
string Technician::get_name() const {
    return this->name;
}

///Get Technician id
int Technician::get_tec_id() const {
    return this->tec_id;
}

///Get Technician type
repair_tec Technician::get_t_type() const {
    return this->tec_type;
}

///Get Technician performance
efficiency Technician::get_efficiency() const {
    return this->tec_efficiency;
}

///Get the total number of interventions done by the Technician
int Technician::get_total_it() const {
    return this->total_interventions;
}

///Bool operator for the Technician priority queue
bool Technician::operator<(const Technician &tec) const {
    return (tec_efficiency > tec.get_efficiency());
}
