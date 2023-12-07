#include "ModelBody.hpp"
#include "SystemImpl.hpp"
#include "FlowBody.hpp"

vector<Model*> ModelBody::models;

using namespace std;

//Construtor e Destrutor
ModelBody::ModelBody(string name):
    name(name){}

ModelBody::~ModelBody(){

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

ModelBody::ModelBody(const Model& model){

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
bool ModelBody::setName(string name){
    this->name = name;
    return true;
}

const string ModelBody::getName() const{
    return name;
}

const int ModelBody::getClock() const{
    return clock;
}

// ---------------------------------
//Iterator
ModelBody::SystemIterator ModelBody::systemsBegin(){
    return systems.begin();
}


ModelBody::SystemIterator ModelBody::systemsEnd(){
    return systems.end();
}

ModelBody::FlowIterator ModelBody::flowsBegin(){
    return flows.begin();
}

ModelBody::FlowIterator ModelBody::flowsEnd(){
    return flows.end();
}

ModelBody::ModelIterator ModelBody::modelsBegin(){
    return models.begin();
}


ModelBody::ModelIterator ModelBody::modelsEnd(){
    return models.end();
}


//Vector size
int ModelBody::flowsSize(){
    return flows.size();
}
int ModelBody::systemsSize(){
    return systems.size();
}
int ModelBody::modelsSize(){
    return models.size();
}

int ModelBody::modelsSize(){
    return ModelBody::modelsSize();
}


// ---------------------------------
//Métodos CRUD
//tenho que checar se já existe o elemento no Vetor antes de adicionar????

//SYSTEM

bool ModelBody::add(System *system){
    int vectorSize = flowsSize();
    systems.push_back(system);

    if(systemsSize() > vectorSize)
        return true;
    
    return false;
}

//???? Pode remover o While e usar um for, ficaria bem mais legível
bool ModelBody::removeSystem(System *system){

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

bool ModelBody::removeSystem(string name){

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

bool ModelBody::updateSystem(string currentName, double value, string newName){

    

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

bool ModelBody::add(Flow *flow){
    int vectorSize = flowsSize();
    flows.push_back(flow);

    if(flowsSize() > vectorSize)
        return true;
    
    return false;
}

bool ModelBody::removeFlow(Flow *flow){

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

bool ModelBody::removeFlow(string name){

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

bool ModelBody::updateFlow(string currentName, System* source, System* target, string newName){

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

bool ModelBody::add(Model* model){
    
    size_t size = models.size();

    models.push_back(model);

    return(models.size() > size);
}

bool Model::add(Model* model){
    return ModelBody::add(model);
}




// ---------------------------------
//Operator Overload

ModelBody& ModelBody::operator= (const ModelBody& model){

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


bool ModelBody::run(int startTime, int endTime){



    for(int i = startTime; i < endTime; i++, clock++){
        int flowsSize = ModelBody::flowsSize();

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

Model* ModelBody::createModel(string name){
    Model* model = new ModelBody(name);
    add(model);

    return model;
}

Model* Model::createModel(string name){
    return ModelBody::createModel(name);
}


System* ModelBody::createSystem(string name, double value){
    System* system = new SystemImpl(name, value);
    add(system);
    return system;
}