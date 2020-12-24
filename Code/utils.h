#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Utils {
public:
    Utils() = default;
    pair<string,string> time_handler(string time);
    pair<string,string> time_splitter(string &str1);
    bool time_handler(string &str1, string str2);
    vector<string> split_string(string &str, char delim);
};



