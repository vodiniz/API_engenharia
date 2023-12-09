#ifndef FLOW_HANDLE_HPP_
#define FLOW_HANDLE_HPP_

#include "HandleBodySemDebug.h"
#include "Flow.hpp"

using namespace std;

template <typename T>
class FlowHandle : public Flow, Handle<T>{

    public:
        FlowHandle(){
            this->pImpl_->setName("");
            this->pImpl_->setSource(NULL);
            this->pImpl_->setTarget(NULL);
        }

        FlowHandle(string name){
            this->pImpl_->setName(name);
            this->pImpl_->setSource(NULL);
            this->pImpl_->setTarget(NULL);
        }

        FlowHandle(string name, System *source, System *target){
            this->pImpl_->setName(name);
            this->pImpl_->setSource(source);
            this->pImpl_->setTarget(target);   
        }

        virtual ~FlowHandle(){}


        FlowHandle(const Flow &flow){
            this->pImpl_->setName(flow.getName());
            this->pImpl_->setSource(flow.getSource());
            this->pImpl_->setTarget(flow.getTarget());      
        }

        const string getName() const{
            return this->pImpl_->getName();
        }

        bool setName(string){
            return this->pImpl_->setName();
        }

        System* getSource() const{
            return this->pImpl_->getSource();
        }

        bool setSource(System*){
            return this->pImpl_->getSource();
        }

        System* getTarget() const{
            return this->pImpl_->getTarget();
        }

        bool setTarget(System*){
            return this->pImpl_->setTarget();
        }

        bool clearSource(){
            return this->pImpl_->clearSource();
        }

        bool clearTarget(){
            return this->pImpl_->clearTarget();
        }

        Flow& operator= (const Flow& flow){
            this->pImpl_->setName(flow.getName());
            this->pImpl_->setSource(flow.getSource());
            this->pImpl_->setTarget(flow.getTarget());

            return this;
        }

        double equation(){
            return this->pImpl_->equation();
        }
};

#endif