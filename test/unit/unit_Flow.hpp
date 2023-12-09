#ifndef _UNIT_FLOW_H_
#define _UNIT_FLOW_H_

#include "../../src/FlowBody.hpp"


/**
 * @brief A unitary test for asserting the default constructor of FlowImpl.
*/
void unit_Flow_constructor_default();

/**
 * @brief A unitary test for asserting the constructor of FlowImpl with name param.
*/
void unit_Flow_constructor_with_name();

/**
 * @brief A unitary test for asserting the constructor of FlowImpl with name, source and target params.
*/
void unit_Flow_constructor_with_name_source_target();

/**
 * @brief A unitary test for asserting the copy constructor of FlowImpl.
*/
void unit_Flow_copy_constructor();

/**
 * @brief A unitary test for asserting the destructor of FlowImpl.
*/
void unit_Flow_destructor();


/**
 * @brief A unitary test for asserting the getName method.
*/
void unit_Flow_getName();

/**
 * @brief A unitary test for asserting the setName method.
*/
void unit_Flow_setName();


/**
 * @brief A unitary test for asserting the getSource method.
*/
void unit_Flow_getSource();

/**
 * @brief A unitary test for asserting the setSource method.
*/
void unit_Flow_setSource();


/**
 * @brief A unitary test for asserting the getTarget method.
*/
void unit_Flow_getTarget();

/**
 * @brief A unitary test for asserting the setTarget method.
*/
void unit_Flow_setTarget();

/**
 * @brief A unitary test for asserting the clearSource method.
*/
void unit_Flow_clearSource();

/**
 * @brief A unitary test for asserting the clearTarget method.
*/
void unit_Flow_clearTarget();


/**
 * @brief A unitary test for asserting the overload of the assignment(=) operator.
*/
void unit_Flow_assignOverload();

void run_unit_test_Flow();


class FlowTest : public FlowBody {
    //Construtor e Destrutor
    public:

        using FlowBody::operator=;
        
        FlowTest(string name=""):
            FlowBody(name){}
            
        FlowTest(string name, System *source, System *target): 
            FlowBody(name, source, target){}

        FlowTest(Flow& flow): FlowBody(flow){}
            
    protected:
        double equation(){
            return (getSource()->getValue())/2;
        }
    
};


#endif