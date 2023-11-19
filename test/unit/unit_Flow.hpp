#ifndef _UNIT_FLOW_H_
#define _UNIT_FLOW_H_

#include "../../src/FlowImpl.hpp"

void unit_Flow_constructor_default();
void unit_Flow_with_name_source_target();
void unit_Flow_copy_constructor();
void unit_Flow_destructor();

void unit_Flow_getName();
void unit_Flow_setName();

void unit_Flow_getSource();
void unit_Flow_setSource();

void unit_Flow_getTarget();
void unit_Flow_setTarget();

void unit_Flow_clearSource();

void unit_Flow_assignOverload();


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