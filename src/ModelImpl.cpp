#include "ModelImpl.hpp"
#include "System.hpp"
#include "Flow.hpp"

using namespace std;

//Construtor e Destrutor
ModelImpl::ModelImpl(string name):
    name(name){}

ModelImpl::~ModelImpl(){}

ModelImpl::ModelImpl(const Model& model){

    // if(this == &model)
    //     return;


    name = model.getName();

    for(SystemIterator it = systemsBegin(); it < systemsEnd(); it++){
        add(*it);
    }


    for(FlowIterator it = flowsBegin(); it < flowsEnd(); it++){
        add(*it);
    }

}

// ---------------------------------
//Getters e Setters
bool ModelImpl::setName(string name){
    this->name = name;
    return true;
}

const string ModelImpl::getName() const{
    return name;
}

const int ModelImpl::getClock() const{
    return clock;
}

// ---------------------------------
//Iterator
ModelImpl::SystemIterator ModelImpl::systemsBegin(){
    return systems.begin();
}


ModelImpl::SystemIterator ModelImpl::systemsEnd(){
    return systems.end();
}

ModelImpl::FlowIterator ModelImpl::flowsBegin(){
    return flows.begin();
}

ModelImpl::FlowIterator ModelImpl::flowsEnd(){
    return flows.end();
}


//Vector size
int ModelImpl::flowsSize(){
    return flows.size();
}
int ModelImpl::systemsSize(){
    return systems.size();
}



// ---------------------------------
//Métodos CRUD
//tenho que checar se já existe o elemento no Vetor antes de adicionar????

//SYSTEM

bool ModelImpl::add(System *system){
    int vectorSize = flowsSize();
    systems.push_back(system);

    if(systemsSize() > vectorSize)
        return true;
    
    return false;
}

//???? Pode remover o While e usar um for, ficaria bem mais legível
bool ModelImpl::removeSystem(System *system){

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

bool ModelImpl::removeSystem(string name){

    SystemIterator systemIterator = systemsBegin();

    while(systemIterator < systemsEnd()){

        if(((*systemIterator)->getName()) == name){
            systems.erase(systemIterator);
            return true;
        }
        systemIterator++;
    }

    return false;
}

bool ModelImpl::update(string name, System *system){

    SystemIterator systemIterator = systemsBegin();

    while(systemIterator < systemsEnd()){

        if((*systemIterator)->getName() == name){
            (*systemIterator) = system;
            return true;
        }
        systemIterator++;
    }

    return false;
}



//FLOW
// ???? Checar com vector.back é mais esperto que conferir o tamanho.

bool ModelImpl::add(Flow *flow){
    int vectorSize = flowsSize();
    flows.push_back(flow);

    if(flowsSize() > vectorSize)
        return true;
    
    return false;
}

bool ModelImpl::removeFlow(Flow *flow){

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

bool ModelImpl::removeFlow(string name){

    FlowIterator flowIterator = flowsBegin();

    while(flowIterator < flowsEnd()){

        if((*flowIterator)->getName() == name){
            flows.erase(flowIterator);
            return true;
        }
        flowIterator++;
    }

    return false;
}

bool ModelImpl::update(string name, Flow *flow){

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

ModelImpl& ModelImpl::operator= (const ModelImpl& model){

    // if(this == &model)
    //     return *this;

    systems.clear();
    flows.clear();

    name = model.getName();

    for(SystemIterator it = systemsBegin(); it < systemsEnd(); it++){
        add(*it);
    }


    for(FlowIterator it = flowsBegin(); it < flowsEnd(); it++){
        add(*it);
    }

    return *this;
}


// ---------------------------------
//Run


bool ModelImpl::run(int startTime, int endTime){



    for(int i = startTime; i < endTime; i++, clock++){
        int flowsSize = ModelImpl::flowsSize();

        int counter = 0;
        double *equationArray = new double[flowsSize];
        

        for(FlowIterator it = flowsBegin(); it < flowsEnd(); it++, counter++){
            equationArray[counter] = (*it)->equation();
        }


        counter = 0;
        for(FlowIterator it = flowsBegin(); it < flowsEnd(); it++, counter++){

            System *source = (*it)->getSource(); 
            source->setValue((source->getValue() - equationArray[counter]));

            System *target = (*it)->getTarget();
            target->setValue(target->getValue() + equationArray[counter]);
        }
    }

    return true;
}


