#include <iostream>
#include <assert.h>
#include <math.h>

#include "unit_System.hpp"
#include "../../src/SystemHandle.hpp"
#include "../../src/SystemBody.hpp"


using namespace std;

void unit_System_constructor_default(){

    System *system = new SystemHandle();
    assert(sizeof(*system) > 0);

    delete system;
}

void unit_System_constructor_with_name(){

    System *system = new SystemHandle("SystemWithName");
    assert(system->getName() == "SystemWithName");
    
    delete system;
}

void unit_System_constructor_with_name_value(){
    System *system = new SystemHandle("SystemWithName", 30.);
    assert(round(fabs(system->getValue() - 30.0)* 10000) < 1);

    delete system;
}

void unit_system_copy_constructor(){

    System *system1 = new SystemHandle("System1", 30.);
    System *system2 = new SystemHandle(*system1);

    assert(system1->getName() == system2->getName());
    assert(round(fabs(system1->getValue() - 30.0)* 10000) == round(fabs(system1->getValue() - 30.0)* 10000));

    delete system1;
    delete system2;
    
}


void unit_System_destructor(){}


void unit_System_getName(){

    System *system = new SystemHandle("SystemWithName");
    assert(system->getName() == "SystemWithName");
    assert(system->getName() != "Anything");

    delete system;
}

void unit_System_setName(){

    System *system = new SystemHandle("SystemWithName");
    
    system->setName("NewName");

    assert(system->getName() != "SystemWithName");
    assert(system->getName() == "NewName");
    
    delete system;
}


void unit_System_getValue(){

    System *system = new SystemHandle("SystemWithName", 30.);
    assert(round(fabs(system->getValue() - 30.0)* 10000) < 1);

    delete system;
}

void unit_System_setValue(){

    System *system = new SystemHandle("SystemWithName", 30.);

    system->setValue(100.);
    assert(round(fabs(system->getValue() - 30.0)* 10000) > 1); 
    assert(round(fabs(system->getValue() - 100.0)* 10000) < 1);

}


void unit_System_assignOverload(){

    System *system1 = new SystemHandle("System1", 50.);
    System *system2 = new SystemHandle();

    system2 = system1;

    assert(system1->getName() == system2->getName());
    assert(round(fabs(system1->getValue() - 50.0)* 10000) == round(fabs(system1->getValue() - 50.0)* 10000));

    delete system1;
    
}


void run_unit_test_System(){
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
        
}
