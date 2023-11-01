#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <iostream>

using namespace std;

class System {
    string name;
    double value;

    public:

        //construtor e destrutor
        System(string, double = 0.);
        virtual ~System();

        //getters e setters

        bool setName(string);
        const string getName();

        bool setValue(double);
        const double getValue();
};

#endif