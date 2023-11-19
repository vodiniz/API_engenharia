#include <iostream>
#include <math.h>
#include <assert.h>

#include "unit_Model.hpp"

using namespace std;




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