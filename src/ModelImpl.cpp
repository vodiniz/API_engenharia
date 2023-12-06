#include "ModelImpl.hpp"
#include "SystemImpl.hpp"
#include "FlowImpl.hpp"

vector<Model*> ModelImpl::models;

using namespace std;

//Construtor e Destrutor
ModelImpl::ModelImpl(string name):
    name(name){}

ModelImpl::~ModelImpl(){

    for(SystemIterator it = systemsBegin(); it < systemsEnd(); it++){
        delete *it;
    }
    for(FlowIterator it = flowsBegin(); it < flowsEnd(); it++)
        delete *it;

    for(ModelIterator it = modelsBegin(); it < modelsEnd(); it++){
        if(*it == this){
            models.erase(it);
            break;
        }
    }
}

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

ModelImpl::ModelIterator ModelImpl::modelsBegin(){
    return models.begin();
}


ModelImpl::ModelIterator ModelImpl::modelsEnd(){
    return models.end();
}


//Vector size
int ModelImpl::flowsSize(){
    return flows.size();
}
int ModelImpl::systemsSize(){
    return systems.size();
}
int ModelImpl::modelsSize(){
    return models.size();
}

int Model::modelsSize(){
    return ModelImpl::modelsSize();
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

bool ModelImpl::updateSystem(string currentName, double value, string newName){

    

    newName = (newName == "")? currentName : newName;

    for(SystemIterator systemIterator = systemsBegin(); systemIterator < systemsEnd(); systemIterator++){
        if((*systemIterator)->getName() == currentName){
            (*systemIterator)->setName(newName);
            (*systemIterator)->setValue(value);
            return true;
        }
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

bool ModelImpl::updateFlow(string currentName, System* source, System* target, string newName){

    newName = (newName == "")? currentName : newName;

    FlowIterator flowIterator = flowsBegin();

    while(flowIterator < flowsEnd()){

        if((*flowIterator)->getName() == currentName){
            (*flowIterator)->setName(newName);
            (*flowIterator)->setSource(source);
            (*flowIterator)->setTarget(target);
            return true;
        }
        flowIterator++;
    }

    return false;
}

bool ModelImpl::add(Model* model){
    
    size_t size = models.size();

    models.push_back(model);

    return(models.size() > size);
}

bool Model::add(Model* model){
    return ModelImpl::add(model);
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

Model* ModelImpl::createModel(string name){
    Model* model = new ModelImpl(name);
    add(model);

    return model;
}

Model* Model::createModel(string name){
    return ModelImpl::createModel(name);
}


System* ModelImpl::createSystem(string name, double value){
    System* system = new SystemImpl(name, value);
    add(system);
    return system;
}