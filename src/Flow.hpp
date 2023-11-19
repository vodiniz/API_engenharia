#ifndef FLOW_H_
#define FLOW_H_

#include "System.hpp"

using namespace std;

class Flow{
    public:

        virtual ~Flow() {};
        virtual const string getName() const = 0;
        virtual bool setName(string) = 0;

        virtual System* getSource() const = 0;
        virtual bool setSource(System*) = 0;

        virtual System* getTarget() const = 0;
        virtual bool setTarget(System*) = 0;

        virtual bool clearSource() = 0;
        virtual bool clearTarget() = 0;
        
        virtual double equation() = 0;
};


#endif