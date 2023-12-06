#include <iostream>
#include <assert.h>
#include <math.h>

#include "unit_Flow.hpp"
#include "../../src/SystemImpl.hpp"

using namespace std;



void unit_Flow_constructor_default(){

    Flow *flow = new FlowTest();

    assert(sizeof(*flow) > 0);
    assert(flow->getTarget() == NULL);
    assert(flow->getSource() == NULL);
    assert(flow->getName() == "");

    delete flow;   
}
void unit_Flow_constructor_with_name(){
    Flow *flow = new FlowTest("MyFlow");

    assert(flow->getName() == "MyFlow");
    assert(flow->getTarget() == NULL);
    assert(flow->getSource() == NULL);

    delete flow;
}

void unit_Flow_constructor_with_name_source_target(){

    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");

    Flow *flow = new FlowTest("MyFlow", system1, system2);

    assert(flow->getSource() == system1);
    assert(flow->getTarget() == system2);

    delete system1;
    delete system2;
    delete flow;

}


void unit_Flow_copy_constructor(){
    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");

    Flow *flow1 = new FlowTest("MyFlow", system1, system2);
    Flow *flow2 = new FlowTest(*flow1);

    assert(flow1->getName() == flow2->getName());
    assert(flow1->getSource() == flow2->getSource());
    assert(flow1->getTarget() == flow2->getTarget());


    delete system1;
    delete system2;
    delete flow1;
    delete flow2;
}


void unit_Flow_destructor(){}


void unit_Flow_getName(){

    Flow *flow = new FlowTest("MyFlow");
    assert(flow->getName() == "MyFlow");

    delete flow;
}


void unit_Flow_setName(){

    Flow *flow = new FlowTest("MyFlow");
    
    flow->setName("NewName");

    assert(flow->getName() == "NewName");

    delete flow;

}


void unit_Flow_getSource(){

    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");

    Flow *flow = new FlowTest("MyFlow", system1, system2);

    assert(flow->getSource() == system1);
    assert(flow->getSource()->getName() == "System1");

    delete system1;
    delete system2;
    delete flow;

}


void unit_Flow_setSource(){

    System *system1 = new SystemImpl("System1");

    Flow *flow = new FlowTest();
    flow->setSource(system1);

    assert(flow->getSource() == system1);
    assert(flow->getSource()->getName() == "System1");

    delete system1;
    delete flow;

}


void unit_Flow_getTarget(){

    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");

    Flow *flow = new FlowTest("MyFlow", system1, system2);

    assert(flow->getTarget() == system2);
    assert(flow->getTarget()->getName() == "System2");

    delete system1;
    delete system2;
    delete flow;
}


void unit_Flow_setTarget(){
    System *system1 = new SystemImpl("System1");

    Flow *flow = new FlowTest();
    flow->setTarget(system1);

    assert(flow->getTarget() == system1);
    assert(flow->getTarget()->getName() == "System1");

    delete system1;
    delete flow;

}


void unit_Flow_clearSource(){
    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");

    Flow *flow = new FlowTest("MyFlow", system1, system2);

    flow->clearSource();

    assert(flow->getSource() == NULL);

    delete system1;
    delete system2;
    delete flow;


}

void unit_Flow_clearTarget(){
    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");

    Flow *flow = new FlowTest("MyFlow", system1, system2);

    flow->clearTarget();

    assert(flow->getTarget() == NULL);

    delete system1;
    delete system2;
    delete flow;
}



void unit_Flow_assignOverload(){

    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");

    Flow *flow = new FlowTest("MyFlow", system1, system2);
    Flow *flow2 = new FlowTest();

    *flow2 = *flow;

    

    assert(flow2->getSource() == system1);
    assert(flow2->getTarget() == system2);

    assert(flow2->getName() == flow->getName());

    delete system1;
    delete system2;
    delete flow;
    delete flow2;
}

void run_unit_test_Flow(){
    
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
}
