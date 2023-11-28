#include "functional_tests.hpp"


#include <math.h>
#include <assert.h>

using namespace std;




void exponentialTest(){

    cout << "-------------------------------\n";

    Model* model = Model::createModel("Exponential");

    System *pop1 = model->createSystem("pop1", 100.);
    System *pop2 = model->createSystem("pop2", 0.);

    Flow* flow = model->createFlow<ExponentialFlow>("exponencial", pop1, pop2);


    model->run(0, 100);
    assert(fabs(pop1->getValue() - 36.6032) < 0.0001);
    assert(fabs(pop2->getValue() - 63.3968) < 0.0001);


    delete pop1;
    delete pop2;

    cout << "Passed exponentialTest" << endl;
    cout << "-------------------------------\n";
}




void logisticTest(){
    cout << "-------------------------------\n";
    Model *model = Model::createModel("Logistic");

    System *p1 = model->createSystem("p1", 100.);
    System *p2 = model->createSystem("p2", 10.);

    Flow* flow = model->createFlow<logisticFlow>("logistica", p1, p2);

    model->run(0, 100);
    assert(fabs(p1->getValue() - 88.2167) < 0.0001);
    assert(fabs(p2->getValue() - 21.7833) < 0.0001);


    cout << "Passed logisticTest" << endl;
    cout << "-------------------------------\n";

    delete p1;
    delete p2;
}


void complexTest(){
    cout << "-------------------------------\n";

    Model *model = Model::createModel("complexModel");

    System* Q1 = model->createSystem("Q1", 100.);
    System* Q2 = model->createSystem("Q2", 0.);
    System* Q3 = model->createSystem("Q3", 100.);
    System* Q4 = model->createSystem("Q4", 0.);
    System* Q5 = model->createSystem("Q5", 0.);

    Flow* f = model->createFlow<ExponentialFlow>("f", Q1, Q2);
    Flow* g = model->createFlow<ExponentialFlow>("g", Q1, Q3);
    Flow* r = model->createFlow<ExponentialFlow>("r", Q2, Q5);
    Flow* t = model->createFlow<ExponentialFlow>("t", Q2, Q3);
    Flow* u = model->createFlow<ExponentialFlow>("u", Q3, Q4);
    Flow* v = model->createFlow<ExponentialFlow>("v", Q4, Q1);

    model->run(0, 100); 

    assert(fabs(Q1->getValue() - 31.8513) < 0.0001);
    assert(fabs(Q2->getValue() - 18.4003) < 0.0001);
    assert(fabs(Q3->getValue() - 77.1143) < 0.0001);
    assert(fabs(Q4->getValue() - 56.1728) < 0.0001);
    assert(fabs(Q5->getValue() - 16.4612) < 0.0001);



    cout << "Passed complexTest" << endl;
    cout << "-------------------------------\n";
}



// exponential 0.01*pop1
// Logistica 0.01*p2*(1-p2/70)
// V 0.01*Q4
// U 0.01*Q3
// F 0.01*Q1
// G 0.01*Q1
// T 0.01*Q2
// R 0.01*Q2

