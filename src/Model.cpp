#include "Model.h"
#include "Flow.h"

using namespace std;

//Construtor e Destrutor
Model::Model(string name):
    name(name){}

Model::~Model(){}

// ---------------------------------
//Getters e Setters
bool::Model::setName(string name){
    this->name = name;
    return true;
}

const string Model::getName() const{
    return name;
}

// ---------------------------------
//Iterator
Model::SystemIterator Model::systemsBegin(){
    return systems.begin();
}

Model::SystemIterator Model::systemsEnd(){
    return systems.end();
}

Model::FlowIterator Model::flowsBegin(){
    return flows.begin();
}

Model::FlowIterator Model::flowsEnd(){
    return flows.end();
}


// ---------------------------------
//Métodos CRUD
//tenho que checar se já existe o elemento no Vetor antes de adicionar????

//SYSTEM

bool Model::add(System *system){
    int vectorSize = systems.size();
    systems.push_back(system);

    if(systems.size() > vectorSize)
        return true;
    
    return false;
}

bool Model::remove(System *system){

    SystemIterator systemIterator = systemsBegin();

    while(systemIterator < systemsEnd()){

        if(*systemIterator == system){
            systems.erase(systemIterator);
            return true;
        }
        systemIterator++;
    }

    return false;
}

bool Model::update(string name, System *system){

    SystemIterator systemIterator = systemsBegin();

    while(systemIterator < systemsEnd()){

        if((*systemIterator)->getName() == name){
            (*systemIterator) = system;
            return true;
        }
        systemIterator++;
    }
}



//FLOW
bool Model::add(Flow *flow){
    int vectorSize = flows.size();
    flows.push_back(flow);

    if(flows.size() > vectorSize)
        return true;
    
    return false;
}

bool Model::remove(Flow *flow){

    FlowIterator flowIterator = flowsBegin();

    while(flowIterator < flowsEnd()){

        if(*flowIterator == flow){
            flows.erase(flowIterator);
            return true;
        }
        flowIterator++;
    }

    return false;
}

bool Model::update(string name, Flow *flow){

    FlowIterator flowIterator = flowsBegin();

    while(flowIterator < flowsEnd()){

        if((*flowIterator)->getName() == name){
            (*flowIterator) = flow;
            return true;
        }
        flowIterator++;
    }

    return false;
}

// ---------------------------------
//Operator Overload

Model& Model::operator= (const Model &model){

    if(this == &model)
        return *this;

    name = model.getName();

    SystemIterator systemIterator = systemsBegin();
    while(systemIterator < systemsEnd()){
        add(*systemIterator);
        systemIterator++;
    }

    FlowIterator flowIterator = flowsBegin();
    while(flowIterator < flowsEnd()){
        add(*flowIterator);
        flowIterator++;
    }
}


// ---------------------------------
//Run


bool Model::run(int startTime, int endTime, int increment){

    for(int i = startTime; i < endTime; i+= increment){

        int flowsSize = flows.size();
        int counter = 0;
        double *equationArray = new double[flowsSize];


        for(FlowIterator i = flowsBegin(); i < flowsEnd(); i++, counter++){
            equationArray[counter] = (*i)->equation();
        }

        int counter = 0;
        for(FlowIterator i = flowsBegin(); i < flowsEnd(); i++, counter++){

            System *source = (*i)->getSource(); 
            source->setValue((source->getValue() - equationArray[counter]));

            System *target = (*i)->getTarget();
            target->setValue(target->getValue() + equationArray[counter]);
        }
    }
}


