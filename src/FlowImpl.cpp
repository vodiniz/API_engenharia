#include "FlowImpl.hpp"
#include "SystemImpl.hpp"

using namespace std;


//Construtor e Destrutor
FlowImpl::FlowImpl(string name):
    name(name){}

FlowImpl::FlowImpl(string name, System* source, System* target):
    name(name), source(source), target(target){}

FlowImpl::~FlowImpl(){}

FlowImpl::FlowImpl(const FlowImpl& flow){
    if(this == &flow)
        return;

    name = flow.getName();
    source = flow.getSource();
    target = flow.getTarget();
}

// --------------------------------------------------
//Getters e Setters

const string FlowImpl::getName() const{
    return name;
}

bool FlowImpl::setName(string name){
    this->name = name;
    return true;
}

System *FlowImpl::getSource() const{
    return source;
}

bool FlowImpl::setSource(System* system){
    source = system;
    return true;
}

System *FlowImpl::getTarget() const{
    return target;
}

bool FlowImpl::setTarget(System* system){
    target = system;
    return true;
}

// --------------------------------------------------
//Limpar source/target

bool FlowImpl::clearTarget(){
    target = NULL;
    return true;
}
bool FlowImpl::clearSource(){
    source = NULL;
    return true;
}

// --------------------------------------------------



FlowImpl& FlowImpl::operator= (const FlowImpl& flow){

    if(this == &flow)
        return *this;

    name = flow.getName();
    source = flow.getSource();
    target = flow.getTarget();

    return *this;
}
