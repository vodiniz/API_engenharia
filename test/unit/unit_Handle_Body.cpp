#include "unit_Handle_Body.hpp"

int numHandleCreated = 0;
int numHandleDeleted = 0;
int numBodyCreated = 0;
int numBodyDeleted = 0;

void unit_test_handle_body(){
    Model *model = Model::createModel("Modelo de pop.");
    Flow* f1 = model->createFlow<LogisticFlow>("nascimento");

    System* s1 = model->createSystem("populacao", 10.0);
    System* s2 = model->createSystem("Teste", 7.90);

    assert(s1->getName() == "populacao");
    assert(round(fabs(s1->getValue() - 10.0)* 10000) < 1);
    assert(s2->getName() == "Teste");
    assert(round(fabs(s2->getValue() - 7.9)* 10000) < 1);

    s1 = s2;

    assert(s1->getName() == "Teste");
    assert(round(fabs(s1->getValue() - 7.9)* 10000) < 1);
    {
    SystemHandle s3("tiago", 7.0), s4("antonio", 8.);
    assert(s3.getName() == "tiago");
    assert(round(fabs(s3.getValue() - 7.0)* 10000) < 1);
    assert(s4.getName() == "antonio");
    assert(round(fabs(s4.getValue() - 8.0)* 10000) < 1);

    s3 = s4;

    assert(s3.getName() == "antonio");
    assert(round(fabs(s3.getValue() - 8.0)* 10000) < 1);

    f1->setSource(s1);
    f1->setTarget(s2);
    cout << "modelsSize:" << model->modelsSize() << endl;
    model->run(0,30);


    delete model;
    
    cout << "Created handles: "  << numHandleCreated << endl;
    cout << "Deleted handles: "  << numHandleDeleted << endl;    
    cout << "Created bodies: "  << numBodyCreated << endl;
    cout << "Deleted bodies: "  << numBodyDeleted << endl;


}



}