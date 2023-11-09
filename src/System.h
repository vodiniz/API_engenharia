#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <iostream>

using namespace std;

class System {

    protected:
        string name;
        double value;

    public:

        //construtor e destrutor
        System(string = "", double = 0.);
        virtual ~System();

        // Construtor de cópia
        System(const System&) ;

        //getters e setters
        const string getName() const;
        bool setName(string) ;

        const double getValue() const;
        bool setValue(double);

        //Sobrecarga para os operadores
        System &operator= (const System&);


};


#endif