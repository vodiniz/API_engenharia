#include "Flow.h"
#include "System.h"

using namespace std;


//Construtor e Destrutor
Flow::Flow(string name):
    name(name){}

Flow::Flow(string name, System* source, System* target):
    name(name), source(source), target(target){}

Flow::~Flow(){}

Flow::Flow(const Flow& flow){
    if(this == &flow)
        return;

    name = flow.getName();
    source = flow.getSource();
    target = flow.getTarget();
}

// --------------------------------------------------
//Getters e Setters

const string Flow::getName() const{
    return name;
}

bool Flow::setName(string name){
    this->name = name;
    return true;
}

System *Flow::getSource() const{
    return source;
}

bool Flow::setSource(System* system){
    source = system;
    return true;
}

System *Flow::getTarget() const{
    return target;
}

bool Flow::setTarget(System* system){
    target = system;
    return true;
}

// --------------------------------------------------
//Limpar source/target

bool Flow::clearTarget(){
    target = NULL;
    return true;
}
bool Flow::clearSource(){
    source = NULL;
    return true;
}

// --------------------------------------------------



Flow& Flow::operator= (const Flow &flow){

    if(this == &flow)
        return *this;

    name = flow.getName();
    source = flow.getSource();
    target = flow.getTarget();

    return *this;
}
