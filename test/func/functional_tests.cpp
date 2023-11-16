#include "functional_tests.hpp"
#include "../../src/Model.hpp"

#include <math.h>
#include <assert.h>

using namespace std;




void exponentialTest(){

    cout << "-------------------------------\n";

    Model model("Exponential");

    System pop1("pop1", 100.);
    System pop2("pop2", 0.);

    ExponentialFlow flow("exponencial", &pop1, &pop2);

    model.add(&pop1);
    model.add(&pop2);
    model.add(&flow);



    model.run(0, 100);
    assert(fabs(pop1.getValue() - 36.6032) < 0.0001);
    assert(fabs(pop2.getValue() - 63.3968) < 0.0001);


    cout << "Passed exponentialTest" << endl;
    cout << "-------------------------------\n";

}




void logisticTest(){
    cout << "-------------------------------\n";
    Model model("Logistic");

    System p1("p1", 100.);
    System p2("p2", 10.);

    logisticFlow flow("logistica", &p1, &p2);

    model.add(&p1);
    model.add(&p2);
    model.add(&flow);

    model.run(0, 100);
    assert(fabs(p1.getValue() - 88.2167) < 0.0001);
    assert(fabs(p2.getValue() - 21.7833) < 0.0001);


    cout << "Passed logisticTest" << endl;
    cout << "-------------------------------\n";
}


void complexTest(){
    cout << "-------------------------------\n";

    Model model("complexModel");

    System Q1("Q1", 100.), Q2("Q2", 0.), Q3("Q3", 100.),
        Q4("Q4", 0.), Q5("Q5", 0.);

    ExponentialFlow f("f", &Q1, &Q2);
    ExponentialFlow g("g", &Q1, &Q3);
    ExponentialFlow r("r", &Q2, &Q5);
    ExponentialFlow t("t", &Q2, &Q3);
    ExponentialFlow u("u", &Q3, &Q4);
    ExponentialFlow v("v", &Q4, &Q1);

    model.add(&Q1);
    model.add(&Q2);
    model.add(&Q3);
    model.add(&Q4);
    model.add(&Q5);
    model.add(&f);
    model.add(&g);
    model.add(&r);
    model.add(&t);
    model.add(&u);
    model.add(&v);


    model.run(0, 100);

    assert(fabs(Q1.getValue() - 31.8513) < 0.0001);
    assert(fabs(Q2.getValue() - 18.4003) < 0.0001);
    assert(fabs(Q3.getValue() - 77.1143) < 0.0001);
    assert(fabs(Q4.getValue() - 56.1728) < 0.0001);
    assert(fabs(Q5.getValue() - 16.4612) < 0.0001);



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

