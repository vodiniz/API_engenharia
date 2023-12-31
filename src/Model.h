#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <vector>

#include "System.h"
#include "Flow.h"

using namespace std;

class Model{


    protected:
        string name;
        vector<System*> systems;
        vector<Flow*> flows;

    public:
        //Construtor e Destrutor   
        Model(string="");
        virtual ~Model();



        //Getters e Setters
        bool setName(string);
        const string getName() const;

        //MÉTODOS CRUD
        bool add(System*);
        bool add(Flow*);

        // bool remove(System*);
        bool removeSystem(System*);
        bool removeSystem(string);


        // bool remove(Flow*);
        bool removeFlow(Flow*);
        bool removeFlow(string);


        bool update(string, System*);
        bool update(string, Flow*);


        //Método executar simulação
        bool run(int, int);


        //Iterator para os containers
        typedef vector<System*>::iterator SystemIterator;
        SystemIterator systemsBegin();


        
        SystemIterator systemsEnd();

        typedef vector<Flow*>::iterator FlowIterator;
        FlowIterator flowsBegin();
        FlowIterator flowsEnd();

        //Vector size
        int flowsSize();
        int systemsSize();


    private:
        //Construtor de cópia
        Model(const Model&);
    
        //Sobrecarga para os operadores
        Model& operator= (const Model&);

        //Construtor de cópia


};


#endif