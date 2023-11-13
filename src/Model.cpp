#include "Model.hpp"
#include "Flow.hpp"

using namespace std;

//Construtor e Destrutor
Model::Model(string name):
    name(name){}

Model::~Model(){}

Model::Model(const Model& model){

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
bool Model::setName(string name){
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

//???? Pode remover o While e usar um for, ficaria bem mais legível
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
// ???? Checar com vector.back é mais esperto que conferir o tamanho.

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


bool Model::run(int startTime, int endTime){

    for(int i = startTime; i < endTime; i++){

        int flowsSize = Model::flowsSize();
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


