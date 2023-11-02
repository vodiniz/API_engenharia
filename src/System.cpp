#include "System.h"

using namespace std;


//Construtor e Destrutor
System::System(string name, double value):
    name(name), value(value){}

System::~System(){}

// --------------------------------------------------
//Getters e Setters

const string System::getName() const{
    return name;
}

bool System::setName(string name){
    this->name = name;
    return true;
}

bool System::setValue(double value){
    this->value = value;
    return true;
}

const double System::getValue() const{
    return value;
}


// --------------------------------------------------

System& System::operator= (const System &system){

    if(this == &system)
        return *this;

    name = system.getName();
    value = system.getValue();

    return *this;
}




