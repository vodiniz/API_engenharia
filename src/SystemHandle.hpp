#ifndef SYSTEM_HANDLE_HPP_
#define SYSTEM_HANDLE_HPP_


#include "HandleBodySemDebug.h"
#include "System.hpp"
#include "SystemBody.hpp"


class SystemHandle : public System, Handle<SystemBody>{

    public:	

        SystemHandle(){  
            pImpl_->setName("");
            pImpl_->setValue(0.0);
        }

        SystemHandle(string name){  
            pImpl_->setName(name);
            pImpl_->setValue(0.0);
        }

        SystemHandle(double value){  
            pImpl_->setName("");
            pImpl_->setValue(value);
        }

        SystemHandle(string name, double value){  
            pImpl_->setName(name);
            pImpl_->setValue(value);
        }
        
        /// Destructor
        virtual ~SystemHandle(){}

        /// copy constructor 
        SystemHandle(const System &system){ 
            pImpl_->setName(system.getName());
            pImpl_->setValue(system.getValue());
        }

        /// assignment operator
        SystemHandle& operator=(const System &system){
            pImpl_->setName(system.getName());
            pImpl_->setValue(system.getValue());
        }
        
        double getValue(void){
            return pImpl_->getValue();
        }
        
        virtual string getName(void){
            return pImpl_->getName();
        }

        virtual bool setValue(double val ){
            return pImpl_->setValue(val);
        }
        virtual bool setName(string id ){
            return pImpl_->setName( id );
        }
	
};

#endif