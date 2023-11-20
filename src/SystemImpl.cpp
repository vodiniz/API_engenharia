#include "SystemImpl.hpp"

using namespace std;


//Construtor e Destrutor
SystemImpl::SystemImpl(string name, double value):
    name(name), value(value){}



SystemImpl::~SystemImpl(){}

SystemImpl::SystemImpl(const System& system){

    
    if(this == &system)
        return;

    name = system.getName();
    value = system.getValue();

}

// --------------------------------------------------
//Getters e Setters

const string SystemImpl::getName() const{
    return name;
}

bool SystemImpl::setName(string name){
    this->name = name;
    return true;
}

bool SystemImpl::setValue(double value){
    this->value = value;
    return true;
}

const double SystemImpl::getValue() const{
    return value;
}


// --------------------------------------------------

System& SystemImpl::operator= (const System &system){

    if(this == &system)
        return *this;

    name = system.getName();
    value = system.getValue();

    return *this;
}




