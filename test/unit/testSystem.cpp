#include "../../src/System.hpp"

#include <assert.h>
#include <math.h>

using namespace std;

void systemTestSetterGetter(){

    cout << "-------------------------------\n";

    System test;
    System system1("Fulano");
    assert("Fulano" == system1.getName());

    system1.setName("Ciclano");
    assert("Ciclano" == system1.getName());

    assert(fabs(system1.getValue()) < 0.0001);

    system1.setValue(10.0);
    assert(fabs(system1.getValue() - 10.0) < 0.0001);


    cout << "Passed systemTestSetterGetter" << endl;
    cout << "-------------------------------\n";
}

void systemTestCopyOverload(){
    cout << "-------------------------------\n";

    System a("Fulano", 13.0);
    System b;

    b = a;
    assert(b.getName() == a.getName());
    assert(fabs(a.getValue() - b.getValue()) < 0.0001);

    cout << "Passed systemTestCopyOverload" << endl;
    cout << "-------------------------------\n";

}
