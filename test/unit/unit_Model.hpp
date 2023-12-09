#ifndef _UNIT_MODEL_H_
#define _UNIT_MODEL_H_

#include "../../src/FlowBody.hpp"



/**
 * @brief A unitary test for asserting the default constructor of Model.
*/
void unit_Model_constructor_default();

/**
 * @brief A unitary test for asserting the constructor of Model with the name parameter.
*/
void unit_Model_constructor_with_name();

/**
 * @brief A unitary test for asserting the destructor of Model.
*/
void unit_Model_destructor();

/**
 * @brief A unitary test for asserting the getName method.
*/
void unit_Model_getName();

/**
 * @brief A unitary test for asserting the setName method.
*/
void unit_Model_setName();

/**
 * @brief A unitary test for asserting the getClock method.
*/
void unit_Model_getClock();

/**
 * @brief A unitary test for asserting the removeSystem method with a System pointer.
*/
void unit_Model_removeSystem_pointer();

/**
 * @brief A unitary test for asserting the removeSystem method with a name.
*/
void unit_Model_removeSystem_name();

/**
 * @brief A unitary test for asserting the removeFlow method with a Flow pointer.
*/
void unit_Model_removeFlow_pointer();

/**
 * @brief A unitary test for asserting the removeFlow method with a name.
*/
void unit_Model_removeFlow_name();

/**
 * @brief A unitary test for asserting the update method with the System param overload.
*/
void unit_Model_updateSystem();

/**
 * @brief A unitary test for asserting the update method with the Flow param overload.
*/
void unit_Model_updateFlow();

/**
 * @brief A unitary test for asserting the run method.
*/
void unit_Model_run();

/**
 * @brief A unitary test for asserting the systemsBegin method.
*/
void unit_Model_systemsBegin();

/**
 * @brief A unitary test for asserting the systemsEnd method.
*/
void unit_Model_systemsEnd();

/**
 * @brief A unitary test for asserting the systemsSize method.
*/
void unit_Model_systemsSize();

/**
 * @brief A unitary test for asserting the flowsBegin method.
*/
void unit_Model_flowsBegin();

/**
 * @brief A unitary test for asserting the flowsEnd method.
*/
void unit_Model_flowsEnd();

/**
 * @brief A unitary test for asserting the flowsSize method.
*/
void unit_Model_flowsSize();

/**
 * @brief A unitary test for asserting the modelsBegin method.
*/
void unit_Model_modelsBegin();

/**
 * @brief A unitary test for asserting the modelsEnd method.
*/
void unit_Model_modelsEnd();

/**
 * @brief A unitary test for asserting the modelsSize method.
*/
void unit_Model_modelsSize();

/**
 * @brief A unitary test for asserting the createModel method.
*/
void unit_Model_createModel();

/**
 * @brief A unitary test for asserting the createSystem method.
*/
void unit_Model_createSystem();

/**
 * @brief A unitary test for asserting the createFlow method.
*/
void unit_Model_createFlow();


void run_unit_test_Model();

class MyFlow : public FlowBody {
    //Construtor e Destrutor
    public:
        using FlowBody::operator=;
        MyFlow(string name=""):
            FlowBody(name){}
            
        MyFlow(string name, System *source, System *target): 
            FlowBody(name, source, target){}
            
    protected:
        double equation(){
            return (getSource()->getValue())/2;
        }
    
};


#endif