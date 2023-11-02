#include "../../src/System.h"

#include <assert.h>
#include <math.h>

using namespace std;

void testSetterGetter(){

    cout << "-------------------------------\n";

    System system1("Fulano");
    assert("Fulano" == system1.getName());

    system1.setName("Ciclano");
    assert("Ciclano" == system1.getName());

    assert(fabs(system1.getValue()) < 0.0001);

    system1.setValue(10.0);
    assert(fabs(system1.getValue() - 10.0) < 0.0001);


    cout << "Passed testSetterGetter" << endl;
    cout << "-------------------------------\n";
}

void testCopyOverload(){
    cout << "-------------------------------\n";

    System a("Fulano", 13.0);
    System b;

    b = a;
    assert(b.getName() == a.getName());
    assert(fabs(a.getValue() - b.getValue()) < 0.0001);

    cout << "Passed testCopyOverload" << endl;
    cout << "-------------------------------\n";

}

int main(void){

    testSetterGetter();
    testCopyOverload();

    return 0;
}