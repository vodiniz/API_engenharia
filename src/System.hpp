#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <string>

using namespace std;

class System{

    public:
        virtual ~System() {};

        virtual const string getName() const = 0;
        virtual bool setName(string) = 0;

        virtual const double getValue() const = 0;
        virtual bool setValue(double) = 0;

};
#endif