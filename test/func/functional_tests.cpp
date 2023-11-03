// exponential 0.01*pop1
// Logistica 0.01*p2*(1-p2/70)
// V 0.01*Q4
// U 0.01*Q3
// F 0.01*Q1
// G 0.01*Q1
// T 0.01*Q2
// R 0.01*Q2


#include "functional_tests.h"
#include "../../src/Model.h"

#include <math.h>
#include <assert.h>

using namespace std;


class ExponentialFlow : public Flow {
    //Construtor e Destrutor
    public:

        ExponentialFlow(string name=""):
            Flow(name){}
            
        ExponentialFlow(string name, System *source, System *target): 
            Flow(name, source, target){}
            
        double equation(){
            return 0.01 * getSource()->getValue();
        }
};


void exponentialTest(){

    cout << "-------------------------------\n";

    Model model("Exponential");

    System pop1("pop1", 100.);
    System pop2("pop2", 0.);

    ExponentialFlow flow("exponencial", &pop1, &pop2);

    model.add(&pop1);
    model.add(&pop2);
    model.add(&flow);




    model.run(0, 10);
    assert(fabs(pop1.getValue() - 90.4382) < 0.0001);
    assert(fabs(pop2.getValue() - 9.5617) < 0.0001);


    pop1.setValue(100.);
    pop2.setValue(0.);
    model.run(0, 100);
    assert(fabs(pop1.getValue() - 36.6032) < 0.0001);
    assert(fabs(pop2.getValue() - 63.3968) < 0.0001);


    pop1.setValue(100.);
    pop2.setValue(0.);
    model.run(0, 547);

    // cout << "\n\n\n\n" << pop1.getValue() << "\n\n\n\n";

    assert(fabs(pop1.getValue() - 0.4096) < 0.0001);
    assert(fabs(pop2.getValue() - 99.5903) < 0.0001);



    cout << "Passed exponentialTest" << endl;
    cout << "-------------------------------\n";

}



class logisticFlow : public Flow {
    //Construtor e Destrutor
    public:

        logisticFlow(string name=""):
            Flow(name){}
            
        logisticFlow(string name, System *source, System *target): 
            Flow(name, source, target){}
            
        double equation(){
            return 0.01 * getTarget()->getValue() * (1 - (getTarget()->getValue()/70.0));
        }
};

void logisticTest(){
    cout << "-------------------------------\n";
    Model model("Logistic");

    System p1("p1", 100.);
    System p2("p2", 10.);

    logisticFlow flow("logistica", &p1, &p2);

    model.add(&p1);
    model.add(&p2);
    model.add(&flow);

    model.run(0, 10);
    assert(fabs(p1.getValue() - 99.1151) < 0.0001);
    assert(fabs(p2.getValue() - 10.8849) < 0.0001);


    p1.setValue(100.);
    p2.setValue(10.);
    model.run(0, 80);
    assert(fabs(p1.getValue() - 91.0933) < 0.0001);
    assert(fabs(p2.getValue() - 18.9067) < 0.0001);

    p1.setValue(100.);
    p2.setValue(10.);
    model.run(0, 347);
    assert(fabs(p1.getValue() - 51.0168) < 0.0001);
    assert(fabs(p2.getValue() - 58.9832) < 0.0001);

    p1.setValue(100.);
    p2.setValue(10.);
    model.run(0, 547);
    assert(fabs(p1.getValue() - 41.7114) < 0.0001);
    assert(fabs(p2.getValue() - 68.2886) < 0.0001);


    cout << "Passed logisticTest" << endl;
    cout << "-------------------------------\n";
}


void multipleSystemsTest(){
    cout << "-------------------------------\n";

    Model model("MultipleSystems");

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

    model.run(0, 10);
    assert(fabs(Q1.getValue() - 82.1225) < 0.0001);
    assert(fabs(Q2.getValue() - 8.3484) < 0.0001);
    assert(fabs(Q3.getValue() - 99.5740) < 0.0001);
    assert(fabs(Q4.getValue() - 9.5504) < 0.0001);
    assert(fabs(Q5.getValue() - 0.4046) < 0.0001);



    Q1.setValue(100.);
    Q2.setValue(0.);
    Q3.setValue(100.);
    Q4.setValue(0.);
    Q5.setValue(0.);
    model.run(0, 100);

    assert(fabs(Q1.getValue() - 31.8513) < 0.0001);
    assert(fabs(Q2.getValue() - 18.4003) < 0.0001);
    assert(fabs(Q3.getValue() - 77.1143) < 0.0001);
    assert(fabs(Q4.getValue() - 56.1728) < 0.0001);
    assert(fabs(Q5.getValue() - 16.4612) < 0.0001);



    Q1.setValue(100.);
    Q2.setValue(0.);
    Q3.setValue(100.);
    Q4.setValue(0.);
    Q5.setValue(0.);
    model.run(0, 1000);

    assert(fabs(Q1.getValue() - 14.3791) < 0.0001);
    assert(fabs(Q2.getValue() - 7.5792) < 0.0001);
    assert(fabs(Q3.getValue() - 24.4748) < 0.0001);
    assert(fabs(Q4.getValue() - 27.2798) < 0.0001);
    assert(fabs(Q5.getValue() - 126.2870) < 0.0001);



    cout << "Passed multipleSystemsTest" << endl;
    cout << "-------------------------------\n";
}

