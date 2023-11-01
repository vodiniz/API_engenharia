#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <vector>

#include "System.h"
#include "Flow.h"

using namespace std;

class Model{

    string name;
    vector<System*> Systems;
    vector<Flow*> Flows;

    public:
        //Construtor e Destrutor        
        Model(string);
        virtual ~Model();

        //Getters e Setters
        bool setName(string);
        const string getName();

        //MÉTODOS CRUD
        bool add(System*);
        bool add(Flow*);

        bool remove(System*);
        bool remove(Flow*);

        bool update(string, System*);
        bool update(string, Flow*);

    protected:

};


#endif