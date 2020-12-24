#include "FileManager.h"


///Constructor
FileManager::FileManager(string file) {
    this->filename = file;
}
///Default constructor
FileManager::FileManager() = default;

///Returns the filename
string FileManager::getfilename() const {
    return this->filename;
}

///Reads the file we want to, throws an exception if the file can't be opened
///@param file - file to be read
///@param dif - 0 - read worker file 1 - read tollbooth file 2 - vehicle file
void FileManager::read_file(string file, const int dif) { //dif == true, read workers.txt file else read toll file
    ifstream infile(file.c_str(), ios::in);
    string error = "Can't open the desired file";
    try{
        if(infile.is_open()){
            string str;
            getline(infile,str); //We don´t want the first line
            if (dif == 0){
                w_vec = {};
                while(getline(infile,str)){
                    if(str == "") continue; //Ignoring empty lines
                    try {
                        file_handler(worker, str);
                    }
                    catch (NotAMemberOf &exc){
                        cerr << "An exception has been thrown: Not member of " << exc.get_error() << endl;
                        exit(EXIT_FAILURE);
                    }
                }
            }
            else if (dif == 1){
                while (getline(infile, str)) {
                    if (str == "") continue;
                    try {
                        file_handler(tollbooth, str);
                    }
                    catch (NotAMemberOf &exc){
                        cerr << "An exception has been thrown: Not member of " << exc.get_error() << endl;
                        exit(EXIT_FAILURE);
                    }
                }
            }
            else if (dif == 2){
                while (getline(infile, str)){
                    if(str == "") continue;
                    file_handler(str);
                }
            }
        }
        else throw CantOpenFile(error);
    }
    catch(CantOpenFile& e ){
        cerr << "An exception has been thrown: " << e.get_error() << endl;
        exit(EXIT_FAILURE);
    }
}

///Handles a tollbooth file, and creates the tollbooth object with the file specifications
///@param d1- Tollbooth object
///@param str1 - line received from the file
void FileManager::file_handler(TollBooth d1, string &str1) {
    string n = "TollBooth";
    vector<string> init_split = utilities->split_string(str1,'|');
    for(int i = 0; i < init_split.size(); i++){
        if (i == 0) d1.location = init_split[i];
        else if (i == 1)d1.entrance_exit = (init_split[i] == "Exit");
        else if (i == 2) d1.lanes = stoi(init_split[i]);
        else if (i == 3) {
            vector<string> split = utilities->split_string(init_split[i], '/');
            for (int j = 0; j < split.size(); j++) File_lane_handler(d1,j,split);
        }
        else if (i == 4) d1.cash_flow = stod(init_split[i]);
        else if (i == 5) d1.amount_of_workers = stoi(init_split[i]);
        else if (i == 6) d1.path_schedule = init_split[i];
        else throw NotAMemberOf(n);
    }
    t_vec.push_back(d1);
}

void FileManager::File_lane_handler(TollBooth &d1, int j,vector<string> &init_split){
    vector<string> split = utilities->split_string(init_split[j], '-');
    d1.lane_handler.lane_number = stoi(split[0]);
    d1.lane_handler.lane_daily_traffic = stoi(split[1]);
    d1.lane_handler.lane_type = !(split[2] == "0");
    d1.lane_handler.working_lane = !(split[3] == "0");
    d1.lane_handler.lane_cash_flow = stod(split[4]);
    d1.lane_handler.current_worker = split[5];
    d1.lane_vec_handler.push_back(d1.lane_handler);
}

///Handles a worker file, and creates the worker object with the file specifications
///@param d1- worker object
///@param str1 - line received from the file
void FileManager::file_handler(Worker &w1, string &str1) {
    string n = "Worker";
    vector<string> split_res = utilities->split_string(str1,'|');
    for(int i = 0; i < split_res.size(); i++){
        if( i == 0 ) w1.name = split_res[i];
        else if( i == 1 ) w1.id = stoi(split_res[i]);
        else if( i == 2 ){
            vector<string> split_res2 = utilities->split_string(split_res[i], '/');
            for(int j = 0; j < split_res2.size(); j++){
                switch (j){
                    case 0:
                        w1.d_schedule.monday = split_res2[j];
                        break;
                    case 1:
                        w1.d_schedule.tuesday = split_res2[j];
                        break;
                    case 2:
                        w1.d_schedule.wednesday = split_res2[j];
                        break;
                    case 3:
                        w1.d_schedule.thursday = split_res2[j];
                        break;
                    case 4:
                        w1.d_schedule.friday = split_res2[j];
                        break;
                    case 5:
                        w1.d_schedule.saturday = split_res2[j];
                        break;
                    case 6:
                        w1.d_schedule.sunday = split_res2[j];
                        break;
                }
            }
        }
        else if( i == 3 ) w1.day_off = split_res[i];
        else if( i == 4 ) w1.working = !(split_res[i] == "No");
        else throw NotAMemberOf(n);
    }
    w_vec.push_back(worker);
}

///Handles a vehicle file, and creates the classe_* object with the file specifications
///@param str1 - line received from the file
void FileManager::file_handler(string &str1) {
   vector<string> split = utilities->split_string(str1,'|');
   try{
       if( stod(split[10]) <= 3500  && stod(split[11]) < 1.1){
           classe_1 *c = new classe_1(1,split[0],stoi(split[1]),stoi(split[2]),stoi(split[3]),split[4],(split[5] == "YES"),stoi(split[6]),stoi(split[7]),stoi(split[8]),stoi(split[9]),stod(split[10]),stod(split[11]),split[12],split[13],(split[14]== "Exit"),split[15]);
           v_vec.push_back(c);
       }
       else if( stod(split[10]) <= 3500 && stod(split[11]) >= 1.1){
           classe_2 *c = new classe_2(2,split[0],stoi(split[1]),stoi(split[2]),stoi(split[3]),split[4],(split[5] == "YES"),stoi(split[6]),stoi(split[7]),stoi(split[8]),stoi(split[9]),stod(split[10]),stod(split[11]),split[12],split[13],(split[14]== "Exit"),split[15]);
           v_vec.push_back(c);
       }
       else if( stod(split[10]) > 3500 && stoi(split[9]) <= 3 && stod(split[11]) > 1.1 ){
           classe_3 *c = new classe_3(3,split[0],stoi(split[1]),stoi(split[2]),stoi(split[3]),split[4],(split[5] == "YES"),stoi(split[6]),stoi(split[7]),stoi(split[8]),stoi(split[9]),stod(split[10]),stod(split[11]),split[12],split[13],(split[14]== "Exit"),split[15],split[16]);
           v_vec.push_back(c);
       }
       else if( stod(split[10]) > 3500 && stoi(split[9]) > 3 && stod(split[11]) > 1.1){
           classe_4 *c = new classe_4(4,split[0],stoi(split[1]),stoi(split[2]),stoi(split[3]),split[4],(split[5] == "YES"),stoi(split[6]),stoi(split[7]),stoi(split[8]),stoi(split[9]),stod(split[10]),stod(split[11]),split[12],split[13],(split[14]== "Exit"),split[15],split[16],stoi(split[17]));
           v_vec.push_back(c);
       }
       else throw NotVehicleClasse();
   }
   catch (NotVehicleClasse &exp){
       cerr << "An error has been raised: " << exp.get_error() << endl;
   }
}


///Updating the workers file
void FileManager::save_workers_file() {
    string message = "Can't open file to write";
    ofstream file;
    file.open("Worker_Update.txt");
    try {
        if( file.is_open() ){
            for (vector<Worker>::const_iterator it = w_vec.begin(); it != w_vec.end(); it++) {
                file << (*it);
            }
            file.close();
        }
        else throw CantOpenFile(message);
    }
    catch (CantOpenFile &exc){
        cerr << "An exception has been thrown: " << exc.get_error() << endl;
        exit(EXIT_FAILURE);
    }
}

///Updating the tollbooth file
void FileManager::save_tolls_file(TollBooth &t1) {
    string message = "Can't open file to write";
    ofstream file;
    file.open("TollBooth_Update.txt");
    try {
        if( file.is_open() ){
            for (vector<TollBooth>::iterator it = t1.T_vector.begin(); it != t1.T_vector.end(); it++) {
                file << (*it);
            }
            file.close();
        }
        else throw CantOpenFile(message);
    }
    catch (CantOpenFile &exc){
        cerr << "An exception has been thrown: " << exc.get_error() << endl;
        exit(EXIT_FAILURE);
    }
}

void FileManager::vehicle_write_helper(const Vehicle* v, ofstream &os){
    os << v->get_name() << "|" << v->get_drivel() << "|" << v->get_id() << "|" << v->get_Age() << "|" << v->get_lp();
    os << "|" << v->get_vverde() << "|" << v->get_year() << "|" << v->get_month() << "|" << v->get_currentkms();
    os << "|" << v->get_naxis() << "|" << v->get_weight() << "|" << v->get_height() << "|" << v->get_ftype();
    os << "|" << v->get_tollb() << "|" << v->get_in_out() << "|" << v->get_time() << "|";
}

///Updating the vehicles file
void FileManager::save_vehicles_file() {
    string message = "Can't open file to write";
    ofstream file;
    file.open("Vehicles_Update.txt");
    try {
        if( file.is_open() ){
            for (vector<Vehicle*>::const_iterator it = v_vec.begin(); it != v_vec.end(); it++) {
                vehicle_write_helper(*it,file);
                if((*it)->get_what_classe() == 1){
                    classe_1* x = dynamic_cast<classe_1*>(*it);
                    file << x->get_bill() << "|\n";
                }
                else if((*it)->get_what_classe() == 2){
                    classe_2* x = dynamic_cast<classe_2*>(*it);
                    file << x->get_bill() << "|" << endl;

                }
                else if((*it)->get_what_classe() == 3){
                    classe_3* x = dynamic_cast<classe_3*>(*it);
                    file << x->get_ctype() << "|" << x->get_bill() << "|\n";

                }
                else if((*it)->get_what_classe() == 4){
                    classe_4* x = dynamic_cast<classe_4*>(*it);
                    file <<  x->get_ctype() << "|" << x->get_trailers();
                    file << "|" << x->get_bill() << "|\n";
                }
            }
            file.close();
        }
        else throw CantOpenFile(message);
    }
    catch (CantOpenFile &exc){
        cerr << "An exception has been thrown: " << exc.get_error() << endl;
        exit(EXIT_FAILURE);
    }
}

///FileManager destructor
FileManager::~FileManager() {
    vector<Vehicle*>::const_iterator it = v_vec.begin();
    vector<Vehicle*>::const_iterator ite = v_vec.end();
    while(it != ite){
        delete *it;
    }
}

