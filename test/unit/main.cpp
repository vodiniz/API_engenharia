#include "testSystem.h"
#include "testFlow.h"
#include "testModel.h"


int main(void){


    //System test
    systemTestSetterGetter();
    systemTestCopyOverload();
    

    //Flow test
    flowTestSetterGetter();
    flowTestClear();
    flowTestEquation();
    flowTestCopyOverload();


    //Model test
    modelTestSetterGetter();
    modelTestCrud();
    modelTestIterator();
    modelTestCopyOverload();

    return 0;
}

