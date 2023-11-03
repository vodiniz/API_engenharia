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


//Vector size
int Model::flowsSize(){
    return flows.size();
}
int Model::systemsSize(){
    return systems.size();
}



// ---------------------------------
//Métodos CRUD
//tenho que checar se já existe o elemento no Vetor antes de adicionar????

//SYSTEM

bool Model::add(System *system){
    int vectorSize = flowsSize();
    systems.push_back(system);

    if(systemsSize() > vectorSize)
        return true;
    
    return false;
}

bool Model::removeSystem(System *system){

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

bool Model::removeSystem(string name){

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

bool Model::update(string name, System *system){

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
bool Model::add(Flow *flow){
    int vectorSize = flowsSize();
    flows.push_back(flow);

    if(flowsSize() > vectorSize)
        return true;
    
    return false;
}

bool Model::removeFlow(Flow *flow){

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

bool Model::removeFlow(string name){

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

    cout << "\n\n\nTamanho system: " << systems.size() << "\n\n\n";

    FlowIterator flowIterator = flowsBegin();
    while(flowIterator < flowsEnd()){
        add(*flowIterator);
        flowIterator++;
    }
    
    return *this;
}


// ---------------------------------
//Run


bool Model::run(int startTime, int endTime, int increment){

    for(int i = startTime; i < endTime; i+= increment){

        int flowsSize = Model::flowsSize();
        int counter = 0;
        double *equationArray = new double[flowsSize];


        for(FlowIterator i = flowsBegin(); i < flowsEnd(); i++, counter++){
            equationArray[counter] = (*i)->equation();
        }

        counter = 0;
        for(FlowIterator i = flowsBegin(); i < flowsEnd(); i++, counter++){

            System *source = (*i)->getSource(); 
            source->setValue((source->getValue() - equationArray[counter]));

            System *target = (*i)->getTarget();
            target->setValue(target->getValue() + equationArray[counter]);
        }
    }

    return true;
}


