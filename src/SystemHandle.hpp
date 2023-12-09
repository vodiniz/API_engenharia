#ifndef SYSTEM_HANDLE_HPP_
#define SYSTEM_HANDLE_HPP_


#include "HandleBodySemDebug.h"
#include "System.hpp"
#include "SystemBody.hpp"

using namespace std;

// template <typename T>
class SystemHandle : public System, Handle<SystemBody>{

    public:	

        SystemHandle(){  
            this->pImpl_->setName("");
            this->pImpl_->setValue(0.0);
        }

        SystemHandle(string name){  
            this->pImpl_->setName(name);
            this->pImpl_->setValue(0.0);
        }

        SystemHandle(double value){  
            this->pImpl_->setName("");
            this->pImpl_->setValue(value);
        }

        SystemHandle(string name, double value){  
            this->pImpl_->setName(name);
            this->pImpl_->setValue(value);
        }
        
        /// Destructor
        virtual ~SystemHandle(){}

        /// copy constructor 
        SystemHandle(const System &system){ 
            this->pImpl_->setName(system.getName());
            this->pImpl_->setValue(system.getValue());
        }

        /// assignment operator
        SystemHandle& operator=(const System &system){
            this->pImpl_->setName(system.getName());
            this->pImpl_->setValue(system.getValue());
            return *this;
        }
        
        const double getValue() const{
            return this->pImpl_->getValue();
        }
        
        bool setValue(double val ){
            return this->pImpl_->setValue(val);
        }
        
        const string getName() const{
            return this->pImpl_->getName();
        }

        bool setName(string id ){
            return this->pImpl_->setName( id );
        }
};

#endif