#pragma once
#include "string"
#include "vector"
#include "technician.h"
#include "TollBooth.h"
#include "BST.h"

using namespace std;

typedef int intervention_type;


/**
 * Intervention Class
 * @param date - Date of a specific intervention
 * @param type - Intervention type
 * @param inter_duration - Duration of the intervention
 * @param tec_worker - Technician accounted for the intervention
 * @param t_booth - Tollbooth where the intervention happened
 * @param ongoing - Intervention not finished yet
 */
class Intervention {
private:
    string date;
    intervention_type type; // 0->revisão , 1->reparação/eletronica, 2->reparação/informática
    string inter_duration;
    Technician* tec_worker;
    TollBooth* t_booth;
    //BST<int> ok = BST(2);
    //BST<Intervention> intervention_tree;
    bool ongoing; //If ongoing == true, then intervention still active
public:
    friend class FileManager;
    string get_date() const;
    intervention_type get_it_type() const;
    string get_duration() const;
    TollBooth* get_tbooth() const;
    bool operator<(const Intervention &it);
};



