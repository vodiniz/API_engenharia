#ifndef FLOW_H_
#define FLOW_H_

#include "System.h"

using namespace std;


class Flow{

    protected:
        string name;
        System *source;
        System *target;

    public:

        //Construtor e Destrutor
        //???? Apenas um construtor, inicializando System como NULL pode ser interessante.
        Flow(string=""); 
        Flow(string, System*, System*);

        virtual ~Flow();

        //Construtor de cópia
        Flow(const Flow&);

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


        //Sobrecarga para os operadores
        // será se é legal com as referências?
        Flow& operator= (const Flow&);
        
        //Método para calcular a equação do Flow
        virtual double equation() = 0;

};

#endif