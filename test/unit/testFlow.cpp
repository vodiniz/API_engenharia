#include "../../src/Flow.hpp"
#include "../../src/System.hpp"

#include <assert.h>
#include <math.h>

using namespace std;

class myFlow : public Flow {
    //Construtor e Destrutor
    public:

        myFlow(string name=""):
            Flow(name){}
            
        myFlow(string name, System *source, System *target): 
            Flow(name, source, target){}
            
    protected:
        double equation(){
            return (getSource()->getValue())/2;
        }
    
};

void flowTestSetterGetter(){

    cout << "-------------------------------\n";

    myFlow test1;
    myFlow flow;

    flow.setName("meuFlow");
    assert("meuFlow" == flow.getName());

    System system1("Fulano", 10.);
    System system2("Ciclano", 20.);

    System system3("Beltrano", 30.);
    System system4("Calano", 40.);

    myFlow flow2("construtor2", &system3, &system4);
    assert(flow2.getName() == "construtor2");
    assert(flow2.getSource()->getName() == "Beltrano");
    assert(flow2.getTarget()->getName() == "Calano");


    flow.setSource(&system1);

    assert((flow.getSource()->getName()) == system1.getName());
    assert(flow.getSource()->getValue() == system1.getValue());

    flow.setTarget(&system2);

    assert((flow.getTarget()->getName()) == system2.getName());
    assert(flow.getTarget()->getValue() == system2.getValue());




    cout << "Passed FlowTestSetterGetter" << endl;
    cout << "-------------------------------\n";
}


void flowTestClear(){

    cout << "-------------------------------\n";
    System system1("Fulano", 10.);
    System system2("Ciclano", 20.);

    myFlow flow("meuFlow", &system1, &system2);

    flow.clearSource();
    flow.clearTarget();

    assert(flow.getSource() == NULL);
    assert(flow.getTarget() == NULL);

    cout << "Passed FlowTestClear" << endl;
    cout << "-------------------------------\n";
}

void flowTestCopyOverload(){

    cout << "-------------------------------\n";
    System system1("Fulano", 10.);
    System system2("Ciclano", 20.);

    myFlow flow("meuFlow", &system1, &system2);

    myFlow flow2;

    flow2 = flow;

    assert((flow2.getSource()->getName()) == flow.getSource()->getName());
    assert(flow2.getSource()->getValue() == flow.getSource()->getValue());

    assert((flow2.getTarget()->getName()) == flow.getTarget()->getName());
    assert(flow2.getTarget()->getValue() == flow.getTarget()->getValue());
    cout << "Passed FlowTestOverload" << endl;
    cout << "-------------------------------\n";
}
