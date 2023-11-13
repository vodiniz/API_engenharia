#include "testSystem.hpp"
#include "testFlow.hpp"
#include "testModel.hpp"


int main(void){


    //System test
    systemTestSetterGetter();
    systemTestCopyOverload();
    

    //Flow test
    flowTestSetterGetter();
    flowTestClear();
    flowTestCopyOverload();


    //Model test
    modelTestSetterGetter();
    modelTestCrud();
    modelTestIterator();
    modelTestCopyOverload();

    return 0;
}

