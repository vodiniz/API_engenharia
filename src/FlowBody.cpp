#include "FlowBody.hpp"
#include <iostream>

using namespace std;


//Construtor e Destrutor
FlowBody::FlowBody(string name):
    name(name){
        source = NULL;
        target = NULL;
    }

FlowBody::FlowBody(string name, System* source, System* target):
    name(name), source(source), target(target){}

FlowBody::~FlowBody(){}

FlowBody::FlowBody(const Flow& flow){

    name = flow.getName();
    source = flow.getSource();
    target = flow.getTarget();
}

// --------------------------------------------------
//Getters e Setters

const string FlowBody::getName() const{
    return name;
}

bool FlowBody::setName(string name){
    this->name = name;
    return true;
}

System *FlowBody::getSource() const{
    return source;
}

bool FlowBody::setSource(System* system){
    source = system;
    return true;
}

System *FlowBody::getTarget() const{
    return target;
}

bool FlowBody::setTarget(System* system){
    target = system;
    return true;
}

// --------------------------------------------------
//Limpar source/target

bool FlowBody::clearTarget(){
    target = NULL;
    return true;
}
bool FlowBody::clearSource(){
    source = NULL;
    return true;
}

// --------------------------------------------------

FlowBody& FlowBody::operator= (const FlowBody& flow) {
    
    if(this == &flow)
        return *this;
        
    this->name = flow.getName();
    this->source = flow.getSource();
    this->target = flow.getTarget();


    return *this;
}
