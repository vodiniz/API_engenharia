#include <iostream>
#include <math.h>
#include <assert.h>

#include "unit_Model.hpp"
#include "../../src/ModelImpl.hpp"
#include "../../src/SystemImpl.hpp"
#include "../../src/FlowImpl.hpp"


using namespace std;

void unit_Model_constructor_default(){


    Model *model = new ModelImpl();

    assert(sizeof(*model) > 0);
    assert(model->getName() == "");
    assert(model->getClock() == 0);
    assert(model->systemsSize() == 0);
    assert(model->flowsSize() == 0);

    delete model;
}
void unit_Model_constructor_with_name(){
    Model *model = new ModelImpl("Model");
    
    assert(sizeof(*model) > 0);
    assert(model->getName() == "Model");
    assert(model->getClock() == 0);

    cout << "TESTE2" << endl;

    delete model;
}


void unit_Model_destructor(){}

void unit_Model_getName(){

    Model *model = new ModelImpl("Model");
    assert(model->getName() == "Model");

    delete model;
}
void unit_Model_setName(){
    Model *model = new ModelImpl("Model");
    
    model->setName("NewName");
    assert(model->getName() != "Model");
    assert(model->getName() == "NewName");


    delete model;
}

void unit_Model_getClock(){
    Model *model = new ModelImpl("Model");
    assert(model->getClock() == 0);
}

void unit_Model_add_System(){
    Model *model = new ModelImpl("Model");

    System *system = new SystemImpl("System");
    model->add(system);

    assert(model->systemsSize() > 0);
    assert(*(model->systemsBegin()) == system); 

    delete system;
    delete model;
}

void unit_Model_add_Flow(){

    Model *model = new ModelImpl("Model");

    Flow *flow = new MyFlow("Flow");
    model->add(flow);

    assert(model->flowsSize() > 0);
    assert(*(model->flowsBegin()) == flow); 

    delete flow;
    delete model;
}

void unit_Model_removeSystem_pointer(){

    Model *model = new ModelImpl("Model");
    System *system = new SystemImpl("System");
    model->add(system);

    assert(model->systemsSize() > 0);
    assert(*(model->systemsBegin()) == system); 

    model->removeSystem(system);
    assert(model->systemsSize() == 0);

    delete system;
    delete model;
}
void unit_Model_removeSystem_name(){

    Model *model = new ModelImpl("Model");
    System *system = new SystemImpl("System");
    model->add(system);

    assert(model->systemsSize() > 0);
    assert(*(model->systemsBegin()) == system); 

    model->removeSystem("System");
    assert(model->systemsSize() == 0);

    delete system;
    delete model;
}

void unit_Model_removeFlow_pointer(){

    Model *model = new ModelImpl("Model");

    Flow *flow = new MyFlow("Flow");
    model->add(flow);

    assert(model->flowsSize() > 0);
    assert(*(model->flowsBegin()) == flow);

    model->removeFlow(flow);
    assert(model->flowsSize() == 0);

    delete flow;
    delete model;

}
void unit_Model_removeFlow_name(){
    
    Model *model = new ModelImpl("Model");

    Flow *flow = new MyFlow("Flow");
    model->add(flow);

    assert(model->flowsSize() > 0);
    assert(*(model->flowsBegin()) == flow);

    model->removeFlow("Flow");
    assert(model->flowsSize() == 0);

    delete flow;
    delete model;
}

void unit_Model_update_System(){
    
    Model *model = new ModelImpl("Model");

    System *system = new SystemImpl("System");
    model->add(system);

    System *system2 = new SystemImpl("System2");

    model->update("System", system2);

    assert(*(model->systemsBegin()) != system);
    assert(*(model->systemsBegin()) == system2);

    delete system;
    delete model;
}
void unit_Model_update_Flow(){

    Model *model = new ModelImpl("Model");

    Flow *flow = new MyFlow("Flow");
    model->add(flow);

    Flow *flow2 = new MyFlow("Flow2");


    model->update("Flow", flow2);

    assert(*(model->flowsBegin()) != flow);
    assert(*(model->flowsBegin()) == flow2);

    delete flow;
    delete model;
}

void unit_Model_run(){

    Model *model = new ModelImpl("Model");

    int startTime = 0;
    int endTime = 100;

    model->run(startTime, endTime);

    assert(model->getClock() == (endTime - startTime));

    delete model;
}

void unit_Model_systemsBegin(){

    Model *model = new ModelImpl("Model");

    System *system = new SystemImpl("System");
    System *system2 = new SystemImpl("System2");

    model->add(system);
    model->add(system2);

    assert(*(model->systemsBegin()) != system2); 
    assert(*(model->systemsBegin()) == system); 

    delete system;
    delete system2;
    delete model;
}
void unit_Model_systemsEnd(){

    Model *model = new ModelImpl("Model");

    System *system = new SystemImpl("System");
    System *system2 = new SystemImpl("System2");

    model->add(system);
    model->add(system2);

    Model::SystemIterator it = model->systemsEnd();

    it--;

    assert(*it == system2); 
    assert(*it != system); 

    delete system;
    delete system2;
    delete model;
}
void unit_Model_systemsSize(){

    Model *model = new ModelImpl("Model");

    for(int i = 0; i < 10; i++){
        model->add(new SystemImpl());
    }

    assert(model->systemsSize() == 10);

    for(Model::SystemIterator it = model->systemsBegin(); it < model->systemsEnd(); it++){
        delete (*it);
    }

    delete model;

}


void unit_Model_flowsBegin(){

    cout << "TESTESADASDASDEE" << endl;
    Model *model = new ModelImpl("Model");

    Flow *flow = new MyFlow("Flow");
    Flow *flow2 = new MyFlow("Flow2");

    model->add(flow);
    model->add(flow2);

    assert(*(model->flowsBegin()) != flow2); 
    assert(*(model->flowsBegin()) == flow); 

    delete flow;
    delete flow2;
    delete model;
}
void unit_Model_flowsEnd(){

    Model *model = new ModelImpl("Model");

    Flow *flow = new MyFlow("Flow");
    Flow *flow2 = new MyFlow("Flow2");

    model->add(flow);
    model->add(flow2);

    Model::FlowIterator it = model->flowsEnd();

    it--;
    assert(*it == flow2); 
    assert(*it != flow);

    delete flow;
    delete flow2;
    delete model;
}
void unit_Model_flowsSize(){

}


void unit_Model_assignOverload();



// void modelTestSetterGetter(){

//     cout << "-------------------------------\n";

//     ModelImpl test;
//     ModelImpl model("modelo");

//     assert("modelo" == model.getName());

//     model.setName("populacao1");
//     assert("populacao1" == model.getName());

//     cout << "Passed modelTestSetterGetter" << endl;
//     cout << "-------------------------------\n";
// }

// void modelTestCrud(){
//     cout << "-------------------------------\n";
//     ModelImpl model("modelo");

//     SystemImpl pop1("pop1");
//     SystemImpl pop2("pop2");
//     myFlow flow("flow", &pop1, &pop2);


//     assert(model.flowsSize() == 0);
//     assert(model.systemsSize() == 0);

//     model.add(&pop1);
//     Model::SystemIterator it = model.systemsBegin();


//     assert(&pop1 == *it);

//     model.add(&pop2);
//     it = model.systemsBegin();
//     it++;
//     assert(&pop2 == *it);




//     model.add(&flow);
//     assert(&flow == *(model.flowsBegin()));

//     assert(model.flowsSize() == 1);
//     assert(model.systemsSize() == 2);



//     SystemImpl pop3("pop3");
//     model.update("pop2", &pop3);
//     assert(&pop3 == *it);

//     myFlow flow2("flow2");
//     model.update("flow", &flow2);
//     assert(&flow2 == *(model.flowsBegin()));

//     model.add(&flow);

//     model.removeFlow(&flow2);
//     assert(model.flowsSize() == 1);

//     model.removeFlow("flow");
//     assert(model.flowsSize() == 0);




//     model.removeSystem("pop1");
//     assert(model.systemsSize() == 1);

//     model.removeSystem(&pop3);
//     assert(model.systemsSize() == 0);


//     cout << "Passed modelTestCrud" << endl;
//     cout << "-------------------------------\n";
// }


// void modelTestIterator(){
//     cout << "-------------------------------\n";

//     ModelImpl model("Modelo");

//     for(int i = 0; i < 10; i++){
//         model.add(new myFlow(to_string(i)));
//     }

//     ModelImpl::FlowIterator flowIterator = model.flowsBegin();

//     int counter = 0;

//     while(flowIterator < model.flowsEnd()){
//         assert((*flowIterator)->getName() == to_string(counter));
//         counter++;
//         flowIterator++;
//     }

//     for(int i = 0; i < 10; i++){
//         model.add(new SystemImpl(to_string(i)));
//     }

//     counter = 0;
//     Model::SystemIterator systemIterator = model.systemsBegin();
//     while(systemIterator < model.systemsEnd()){
//         assert((*systemIterator)->getName() == to_string(counter));
//         counter++;
//         systemIterator++;
//     }

//     cout << "Passed modelTestIterator" << endl;
//     cout << "-------------------------------\n";
// }


// void modelTestCopyOverload(){

//     SystemImpl system1("Fulano", 10.);
//     cout << "-------------------------------\n";

//     ModelImpl model1("model1");

//     myFlow f1;
//     myFlow f2;

//     model1.add(&f1);
//     model1.add(&f2);

//     ModelImpl model2("model2");


//     assert(model1.flowsSize() == 2);
//     // ????
//     // iterator não está como const!
//     // fazer um iterator const ou utilizar ponteiro
//     // Mas o = nem poderia estar sobrecarregado teria que colocar como privado para 
//     // assert(model2.flowsSize() == 2);

//     cout << "Passed modelTestCopyOverload" << endl;
//     cout << "-------------------------------\n";

// }