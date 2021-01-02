#include "utils.h"

///Worker daily_schedule "00:00:00-08:00:00" splitted
///@param time - worker schedule
pair<string, string> Utils::time_handler(string time) {
    string t1,t2;
    for(int i = 0; i < 8; i++){
        t1 += time[i];
    }
    for(int i = 9; i < 17; i++){
        t2 += time[i];
    }
    return make_pair(t1,t2);
}

///Splits the time string "November 20 Monday 12:01:37" into two parts, the date/day and hours
///@param str1 - time string
pair<string, string> Utils::time_splitter(string &str1) {
    vector<string> split = split_string(str1,' ');
    return pair<string,string>(split[2],split[3]);
}

///Compares two time strings
///@param str1 - time string
///@param str2 - time string
bool Utils::time_handler(string &str1, string str2) {
    return str1 > str2;
}

///Splits a string by a specific delimiter character
///@param str - the string to be spliced
///@param delim - delimiter character
vector<string> Utils::split_string(string &str, char delim) {
    vector<string> vec;
    stringstream ss(str);
    string temp;
    while(getline(ss, temp, delim)){
        vec.push_back(temp);
    }
    return vec;
}
