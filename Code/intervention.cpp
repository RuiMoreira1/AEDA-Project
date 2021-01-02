#include "intervention.h"

///Get Intervention data
string Intervention::get_date() const {
    return this->date;
}

///Get Intervention type
intervention_type Intervention::get_it_type() const {
    return this->type;
}

///Get Intervention duration
string Intervention::get_duration() const {
    return this->inter_duration;
}

///Get Intervention tollbooth
TollBooth *Intervention::get_tbooth() const {
    return this->t_booth;
}

/**
 * Intervention operator for the BST
 * @param const Intervention &it - Intervention object
 */
bool Intervention::operator<(const Intervention &it) {
    if( date < it.get_date() ) return true;
    else if ( date > it.get_date() ) return false;
    else{
        if ( t_booth->get_location() < it.get_tbooth()->get_location() ) return true;
        else if ( t_booth->get_location() > it.get_tbooth()->get_location() ) return false;
        else{
            if( type < it.get_it_type() ) return true;
            else return false;
        }
    }
}

