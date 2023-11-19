#ifndef _UNIT_MODEL_H_
#define _UNIT_MODEL_H_

#include "../../src/FlowImpl.hpp"

void unit_Model_constructor_default();
void unit_Model_constructor_with_name();
void unit_Model_copy_constructor();

void unit_Model_destructor();

void unit_Model_getName();
void unit_Model_setName();

void unit_Model_add_System();
void unit_Model_add_Flow();

void unit_Model_removeSystem_pointer();
void unit_Model_removeSystem_name();

void unit_Model_removeFlow_pointer();
void unit_Model_removeFlow_name();

void unit_Model_update_System();
void unit_Model_update_Flow();

void unit_Model_run();

void unit_Model_systemsBegin();
void unit_Model_systemsEnd();
void unit_Model_systemsSize();


void unit_Model_flowsBegin();
void unit_Model_flowsEnd();
void unit_Model_flowsSize();


void unit_Model_assignOverload();



class myFlow : public FlowImpl {
    //Construtor e Destrutor
    public:

        myFlow(string name=""):
            FlowImpl(name){}
            
        myFlow(string name, System *source, System *target): 
            FlowImpl(name, source, target){}
            
    protected:
        double equation(){
            return (getSource()->getValue())/2;
        }
    
};

#endif