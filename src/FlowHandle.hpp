#ifndef FLOW_HANDLE_HPP_
#define FLOW_HANDLE_HPP_

#include "HandleBodySemDebug.h"
#include "Flow.hpp"

using namespace std;

template <typename T>
class FlowHandle : public Flow,public Handle<T>{

public:
    FlowHandle(){
        Handle<T>::pImpl_->setName("");
        Handle<T>::pImpl_->setSource(NULL);
        Handle<T>::pImpl_->setTarget(NULL);
    }

    FlowHandle(string name){
        Handle<T>::pImpl_->setName(name);
        Handle<T>::pImpl_->setSource(NULL);
        Handle<T>::pImpl_->setTarget(NULL);
    }

    FlowHandle(string name, System *source, System *target){
        Handle<T>::pImpl_->setName(name);
        Handle<T>::pImpl_->setSource(source);
        Handle<T>::pImpl_->setTarget(target);   
    }

    virtual ~FlowHandle(){}


    FlowHandle(const Flow &flow){
        Handle<T>::pImpl_->setName(flow.getName());
        Handle<T>::pImpl_->setSource(flow.getSource());
        Handle<T>::pImpl_->setTarget(flow.getTarget());      
    }

    const string getName() const{
        return  Handle<T>::pImpl_->getName();
    }

    bool setName(string){
        return  Handle<T>::pImpl_->setName();
    }

    System* getSource() const{
        return  Handle<T>::pImpl_->getSource();
    }

    bool setSource(System*){
        return  Handle<T>::pImpl_->getSource();
    }

    System* getTarget() const{
        return  Handle<T>::pImpl_->getTarget();
    }

    bool setTarget(System*){
        return  Handle<T>::pImpl_->setTarget();
    }

    bool clearSource(){
        return  Handle<T>::pImpl_->clearSource();
    }

    bool clearTarget(){
        return  Handle<T>::pImpl_->clearTarget();
    }

    Flow& operator= (const Flow& flow){
            Handle<T>::pImpl_->setName(flow.getName());
            Handle<T>::pImpl_->setSource(flow.getSource());
            Handle<T>::pImpl_->setTarget(flow.getTarget());

        return this;
    }

    double equation(){
        return  Handle<T>::pImpl_->equation();
    }
};

#endif