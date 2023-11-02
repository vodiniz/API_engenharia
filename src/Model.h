#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <vector>

#include "System.h"
#include "Flow.h"

using namespace std;

class Model{

    string name;
    vector<System*> systems;
    vector<Flow*> flows;

    public:
        //Construtor e Destrutor        
        Model(string);
        virtual ~Model();

        //Construtor de cópia
        Model(const Model&) ;


        //Getters e Setters
        bool setName(string);
        const string getName() const;

        //MÉTODOS CRUD
        bool add(System*);
        bool add(Flow*);

        bool remove(System*);
        bool remove(Flow*);

        bool update(string, System*);
        bool update(string, Flow*);

        //Método executar simulação

        bool run(int, int, int = 1);


        //Iterator para os containers
        typedef vector<System*>::iterator SystemIterator;
        SystemIterator systemsBegin();
        SystemIterator systemsEnd();

        typedef vector<Flow*>::iterator FlowIterator;
        FlowIterator flowsBegin();
        FlowIterator flowsEnd();


        //Sobrecarga para os operadores
        Model& operator= (const Model&);


    protected:

};


#endif