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

    void unit_Flow_constructor_default();
    void unit_Flow_constructor_with_name();
    void unit_Flow_constructor_with_name_source_target();
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

    cout << "------------------------------------------------------------------\n" <<
        "Passed Flow Unit tests.\n" << 
        "------------------------------------------------------------------\n";
        
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

    cout << "------------------------------------------------------------------\n" <<
        "Passed Model Unit tests.\n" << 
        "------------------------------------------------------------------\n";
        

    return 0;
}

