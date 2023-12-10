#ifndef MODEL_HANDLE_HPP_
#define MODEL_HANDLE_HPP_


#include "Model.hpp"
#include "ModelBody.hpp"
#include "HandleBodySemDebug.h"

using namespace std;
// template <typename T>
class ModelHandle: public Model, Handle<ModelBody>{

    public:
        ModelHandle(){
            this->pImpl_->setName("");
            add((Model*)pImpl_);
        }

        ModelHandle(string name){
            this->pImpl_->setName(name);
        }

        ~ModelHandle(){
            for(Model::ModelIterator it = modelsBegin(); it < modelsEnd(); it++)
                if(*it == (Model*)this){
                    removeModel(it);
                break;
            }     
        }

        bool removeModel(ModelIterator model){
            return this->pImpl_->removeModel(model);
        }

        const string getName() const{
            return this->pImpl_->getName();
        }

        bool setName(string name){
            return this->pImpl_->setName(name);
        }

        const int getClock() const{
            return this->pImpl_->getClock();
        }

        bool add(Flow *flow){
            return this->pImpl_->add(flow);
        }

        bool removeFlow(Flow *flow){
            return this->pImpl_->removeFlow(flow);
        }

        bool removeFlow(string name){
            return this->pImpl_->removeFlow(name);
        }

        bool add(System *system){
            return this->pImpl_->add(system);
        }

        bool removeSystem(System *system){
            return this->pImpl_->removeSystem(system);
        }

        bool removeSystem(string name){
            return this->pImpl_->removeSystem(name);
        }

        bool updateSystem(string currentName, double value, string newName = ""){
            return this->pImpl_->updateSystem(currentName, value, newName);
        }


        bool updateFlow(string currentName, System* source, System* target, string newName = ""){
            return this->pImpl_->updateFlow(currentName, source, target, newName);
        }
        
        bool add(Model *model){
            return Handle<ModelBody>::pImpl_->add(model);
        }

        bool run(int startTime, int endTime){
            return this->pImpl_->run(startTime, endTime);
        }

        SystemIterator systemsBegin(){
            return this->pImpl_->systemsBegin();
        }

        SystemIterator systemsEnd(){
            return this->pImpl_->systemsEnd();
        }

        int systemsSize(){
            return this->pImpl_->systemsSize();
        }

        FlowIterator flowsBegin(){
            return this->pImpl_->flowsBegin();
        }

        FlowIterator flowsEnd(){
            return this->pImpl_->flowsEnd();
        }

        int flowsSize(){
            return this->pImpl_->flowsSize();
        }

        ModelIterator modelsBegin(){
            return this->pImpl_->modelsBegin();
        }

        ModelIterator modelsEnd(){
            return this->pImpl_->modelsEnd();
        }

        int modelsSize(){
            return this->pImpl_->modelsSize();
        }

        Model *createModel(){
            return this->pImpl_->createModel();
        }
        Model *createModel(string name){
            return this->pImpl_->createModel(name);
        }
        
        System* createSystem(){
            return this->pImpl_->createSystem();
        }

        System* createSystem(string name){
            return this->pImpl_->createSystem(name);
        }  

        System* createSystem(string name, double value){
            return this->pImpl_->createSystem(name, value);
        }

};


#endif