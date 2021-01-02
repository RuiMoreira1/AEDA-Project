#pragma once
#include "string"
#include "vector"
using namespace std;

typedef int repair_tec;
typedef double efficiency;

/***
 * class Technician
 * @param name - Technician name
 * @param tec_id - Technician id
 * @param total_intervention - Technician total interventions
 * @param tec_type - Technician type ( 0-> Revision, 1 -> Electronics, 2 -> Informatics)
 * @param tec_efficiency - Technician performance
 * @param working - Working -> true
 * @param available - Technician available
 */
class Technician {
private:
    string name; int tec_id;
    repair_tec tec_type; //if 0->revisão, 1->repair/eletro, 2->repair/infor
    int total_interventions;
    efficiency tec_efficiency;
    bool working, available;
public:
    friend class FileManager;
    string get_name() const;
    int get_tec_id() const;
    repair_tec get_t_type() const;
    efficiency get_efficiency() const;
    int get_total_it() const;
    bool operator<(const Technician &tec) const;


};



