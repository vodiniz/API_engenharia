#ifndef FLOW_H_
#define FLOW_H_

#include "System.h"

using namespace std;


class Flow{

    string name;
    System* source;
    System* target;

    public:

        //Construtor e Destrutor
        Flow(string, System* = NULL, System* = NULL);
        virtual ~Flow();

        //Getters e Setters
        bool setName(string);
        const string getName();

        bool setSource(System*);
        const System* getSource();

        bool setTarget(System*);
        const System* getTarget();

        //Método para limpar o source/target

        bool clearTarget();
        bool clearSource();

        //Metodo para executar o Flow
        bool execute();

    protected:
        
        //Método para calcular a equação do Flow
        virtual bool equation() = 0;

};

#endif