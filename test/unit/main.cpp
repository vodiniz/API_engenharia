#include "unit_Flow.hpp"
#include "unit_Model.hpp"
#include "unit_System.hpp"


int main(void){


    // ------------------------------------------------------------------
    // ------------------------------------------------------------------
    // SYSTEM UNIT TESTS
    unit_System_constructor_default();
    unit_System_constructor_with_name();
    unit_System_constructor_with_name_value();
    unit_system_copy_constructor();

    unit_System_destructor();

    unit_System_getName();
    unit_System_setName();

    unit_System_getValue();
    unit_System_setValue();

    unit_System_assignOverload();

    cout << "------------------------------------------------------------------\n" <<
        "Passed System Unit tests.\n" << 
        "------------------------------------------------------------------\n";
        
    // ------------------------------------------------------------------
    // ------------------------------------------------------------------

    unit_Flow_constructor_default();
    unit_Flow_constructor_with_name();
    unit_Flow_constructor_with_name_source_target();
    unit_Flow_copy_constructor();

    unit_Flow_destructor();


    unit_Flow_getName();
    unit_Flow_setName();

    unit_Flow_getSource();
    unit_Flow_setSource();



    unit_Flow_getTarget();
    unit_Flow_setTarget();

    unit_Flow_clearSource();

    unit_Flow_assignOverload();

    cout << "------------------------------------------------------------------\n" <<
        "Passed Flow Unit tests.\n" << 
        "------------------------------------------------------------------\n";

    // ------------------------------------------------------------------
    // ------------------------------------------------------------------
        
    unit_Model_constructor_default();
    unit_Model_constructor_with_name();

    unit_Model_destructor();

    unit_Model_getName();
    unit_Model_setName();

    unit_Model_createModel();
    unit_Model_createSystem();
    unit_Model_createFlow();

    unit_Model_removeSystem_pointer();
    unit_Model_removeSystem_name();

    unit_Model_removeFlow_pointer();
    unit_Model_removeFlow_name();

    unit_Model_updateSystem();
    unit_Model_updateFlow();

    unit_Model_run();

    unit_Model_systemsBegin();
    unit_Model_systemsEnd();
    unit_Model_systemsSize();


    unit_Model_flowsBegin();
    unit_Model_flowsEnd();
    unit_Model_flowsSize();

    cout << "------------------------------------------------------------------\n" <<
        "Passed Model Unit tests.\n" << 
        "------------------------------------------------------------------\n";
        

    return 0;
}

