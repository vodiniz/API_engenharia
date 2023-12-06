#include <iostream>
#include <math.h>
#include <assert.h>

#include "unit_Model.hpp"
#include "../../src/Model.hpp"
#include "../../src/System.hpp"



using namespace std;

void unit_Model_constructor_default(){


    Model *model = Model::createModel();

    assert(sizeof(*model) > 0);
    assert(model->getName() == "");
    assert(model->getClock() == 0);
    assert(model->systemsSize() == 0);
    assert(model->flowsSize() == 0);

    delete model;
}

void unit_Model_constructor_with_name(){

    Model *model = Model::createModel("Model");
    
    assert(sizeof(*model) > 0);
    assert(model->getName() == "Model");
    assert(model->getClock() == 0);

    delete model;
}


void unit_Model_destructor(){}

void unit_Model_getName(){

    Model *model = Model::createModel("Model");

    assert(model->getName() == "Model");

    delete model;
}
void unit_Model_setName(){

    Model *model = Model::createModel();

    
    model->setName("NewName");
    assert(model->getName() != "Model");
    assert(model->getName() == "NewName");


    delete model;
}

void unit_Model_getClock(){
    Model *model = Model::createModel();

    assert(model->getClock() == 0);

    delete model;
}

void unit_Model_removeSystem_pointer(){

    Model* model = Model::createModel("Model");

    System *system = model->createSystem("System");

    assert(model->systemsSize() == 1);
    assert(*(model->systemsBegin()) == system); 

    model->removeSystem(system);
    assert(model->systemsSize() == 0);

    delete model;
}
void unit_Model_removeSystem_name(){

    Model* model = Model::createModel("Model");
    System *system = model->createSystem("System");

    assert(model->systemsSize() == 1);
    assert(*(model->systemsBegin()) == system); 

    model->removeSystem("System");
    assert(model->systemsSize() == 0);

    delete model;
}

void unit_Model_removeFlow_pointer(){

    Model* model = Model::createModel("Model");

    Flow *flow = model->createFlow<MyFlow>("Flow");

    assert(model->flowsSize() == 1);
    assert(*(model->flowsBegin()) == flow);

    model->removeFlow(flow);
    assert(model->flowsSize() == 0);

    delete model;

}
void unit_Model_removeFlow_name(){
    
    Model* model = Model::createModel("Model");

    Flow *flow = model->createFlow<MyFlow>("Flow");

    assert(model->flowsSize() == 1);
    assert(*(model->flowsBegin()) == flow);

    model->removeFlow("Flow");
    assert(model->flowsSize() == 0);

    delete model;
}

void unit_Model_updateSystem(){

    Model* model = Model::createModel("Model");

    System *system = model->createSystem("System");


    model->updateSystem("System", 30., "System2");

    assert(round(fabs(system->getValue() - 30.0)* 10000) < 1);
    assert(system->getName() == "System2");


    delete model;
}

void unit_Model_updateFlow(){

    Model* model = Model::createModel("Model");

    Flow *flow = model->createFlow<MyFlow>("Flow");

    System* system1 = model->createSystem();
    System* system2 = model->createSystem();



    model->updateFlow("Flow",system1, system2, "Flow2");

    assert(flow->getName() == "Flow2");
    assert(flow->getSource() == system1);
    assert(flow->getTarget() == system2);


    delete model;
}

void unit_Model_run(){

    Model* model = Model::createModel("Model");

    int startTime = 0;
    int endTime = 100;

    model->run(startTime, endTime);

    assert(model->getClock() == (endTime - startTime));

    delete model;
}

void unit_Model_systemsBegin(){

    Model* model = Model::createModel("Model");

    System *system = model->createSystem("System");
    System *system2 = model->createSystem("System2");

    assert(*(model->systemsBegin()) != system2); 
    assert(*(model->systemsBegin()) == system); 

    delete model;
}
void unit_Model_systemsEnd(){

    Model* model = Model::createModel("Model");

    System *system = model->createSystem("System");
    System *system2 = model->createSystem("System2");

    Model::SystemIterator it = model->systemsEnd();

    it--;

    assert(*it == system2); 
    assert(*it != system); 

    delete model;
}
void unit_Model_systemsSize(){

    Model* model = Model::createModel("Model");

    for(int i = 0; i < 10; i++){
        model->createSystem();
    }

    assert(model->systemsSize() == 10);

    delete model;

}


void unit_Model_flowsBegin(){

    Model* model = Model::createModel("Model");

    Flow *flow = model->createFlow<MyFlow>("Flow");
    Flow *flow2 = model->createFlow<MyFlow>("Flow2");

    assert(*(model->flowsBegin()) != flow2); 
    assert(*(model->flowsBegin()) == flow); 

    delete model;
}
void unit_Model_flowsEnd(){

    Model* model = Model::createModel("Model");

    Flow *flow = model->createFlow<MyFlow>("Flow");
    Flow *flow2 = model->createFlow<MyFlow>("Flow2");

    Model::FlowIterator it = model->flowsEnd();

    it--;
    assert(*it == flow2); 
    assert(*it != flow);

    delete model;
}
void unit_Model_flowsSize(){

}

void unit_Model_createModel(){
    assert(Model::modelsSize() == 0);

    Model* model = Model::createModel();

    assert(model->modelsSize() == 1);

    delete model;

    assert(Model::modelsSize() == 0);


}

void unit_Model_createSystem(){

    Model* model = Model::createModel();

    assert(model->systemsSize() == 0);

    System* system1 = model->createSystem("System1");
    assert(model->systemsSize() == 1);

    System* system2 = model->createSystem("System2");
    assert(model->systemsSize() == 2);


    delete model;

}

void unit_Model_createFlow(){
    Model* model = Model::createModel();

    assert(model->flowsSize() == 0);

    Flow* flow1 = model->createFlow<MyFlow>("Flow1");
    assert(model->flowsSize() == 1);

    Flow* flow2 = model->createFlow<MyFlow>("Flow2");
    assert(model->flowsSize() == 2);

    delete model;

}

void run_unit_test_Model(){
    
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
        

}