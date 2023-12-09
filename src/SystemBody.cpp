#include "SystemBody.hpp"

using namespace std;


//Construtor e Destrutor
SystemBody::SystemBody(string name, double value):
    name(name), value(value){}



SystemBody::~SystemBody(){}

SystemBody::SystemBody(const System& system){

    
    if(this == (SystemBody*) &system)
        return;

    name = system.getName();
    value = system.getValue();

}

// --------------------------------------------------
//Getters e Setters

const string SystemBody::getName() const{
    return name;
}

bool SystemBody::setName(string name){
    this->name = name;
    return true;
}

bool SystemBody::setValue(double value){
    this->value = value;
    return true;
}

const double SystemBody::getValue() const{
    return value;
}


// --------------------------------------------------

SystemBody& SystemBody::operator= (const SystemBody &system){

    name = system.getName();
    value = system.getValue();

    return *this;
}




