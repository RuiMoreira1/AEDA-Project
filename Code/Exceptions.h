#pragma once

#include <string>
using namespace std;

///Exception can't open file, used if the file can't be opened
///@param error_raised - the exception thrown
class CantOpenFile {
    string error_raised;
public:
    CantOpenFile(string &exc){
        this->error_raised = exc;
    }
    string get_error() const{ return this->error_raised; }
};

///Exception that is thrown, if the current vehicle doesn't belong to any of the previously defined car classes
///@param error_raised - the exception thrown
class NotVehicleClasse {
    string error_raised = "Bad file input, there is no existing class for this vehicle";
public:
    NotVehicleClasse() =default;
    string get_error() const{ return this->error_raised; }
};

///@param error_raised - the exception thrown
class NotAMemberOf {
    string error_raised;
public:
    NotAMemberOf(string &n){
        error_raised = n;
    }
    string get_error() const{ return error_raised; }
};

///Exception thrown if the element being read from the file isn't correctly formatted
///@param error_raised - the exception thrown
class ElementNotInVec {
    string error_raised;
public:
    ElementNotInVec(string &n): error_raised(n){}
    string get_error() const { return error_raised; }
};

///Exception thrown if there are no lanes working
///@param error_raised - the exception thrown
class NoLanesAvailable {
    string error_raised;
public:
    NoLanesAvailable(string &n): error_raised(n){}
    string get_error() const { return error_raised; }
};

///Exception thrown if there are no workers available to replace another one
///@param error_raised - the exception thrown
class NoWorkerAvailable {
    string error_raised = "No workers available at the moment";
public:
    NoWorkerAvailable() = default;
    string get_error() const { return error_raised; }
};

///Exception thrown if the input isn't correct
///@param error_raised - the exception thrown
class NotAValidDay {
    string error_raised = "Not a valid day";
public:
    NotAValidDay() = default;
    string get_error() const { return error_raised; }
};


