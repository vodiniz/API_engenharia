#ifndef FLOW_H_
#define FLOW_H_

#include "System.h"

using namespace std;


class Flow{

    string name;
    System *source;
    System *target;

    public:

        //Construtor e Destrutor
        Flow(string=""); 
        //Dá pra por string como "" ?
        Flow(string, System*, System*);

        virtual ~Flow();

        //Construtor de cópia
        Flow(const Flow&) ;

        //Getters e Setters
        const string getName() const;
        bool setName(string);

        System* getSource() const;
        bool setSource(System*);

        System* getTarget() const;
        bool setTarget(System*);

        //Método para limpar o source/target

        bool clearTarget();
        bool clearSource();

        //Metodo para executar o Flow
        bool execute();

        //Sobrecarga para os operadores
        // será se é legal com as referências?
        Flow& operator= (const Flow&);
        
        //Método para calcular a equação do Flow
        virtual double equation() = 0;

};

#endif