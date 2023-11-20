#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <vector>

#include "System.hpp"
#include "Flow.hpp"

class Model{
    public: 
        virtual ~Model() {};

        virtual bool setName(string) = 0;
        virtual const string getName() const = 0;
        virtual const int getClock() const = 0;

        virtual bool add(System*) = 0;
        virtual bool removeSystem(System* system) = 0;
        virtual bool removeSystem(string name) = 0;
        virtual bool update(string name, System* system) = 0;

        virtual bool add(Flow*) = 0;
        virtual bool removeFlow(Flow* flow) = 0;
        virtual bool removeFlow(string name) = 0;
        virtual bool update(string name, Flow* flow) = 0;

        virtual bool run(int startTime, int endTime) = 0;




        /**
         * @brief New iterator type for the System container.
         * 
         * A new iterator type for our System container, which will be used
         * for iterating over our container while encapsulating its implementation.
         * 
        */

        typedef vector<System*>::iterator SystemIterator;
        virtual SystemIterator systemsBegin() = 0;
        virtual SystemIterator systemsEnd() = 0;
        virtual int systemsSize() = 0;
        
        /**
         * @brief New iterator type for the Flow container.
         * 
         * A new iterator type for our Flow container, which will be used
         * for iterating over our container while encapsulating its implementation.
         * 
        */
        typedef vector<Flow*>::iterator FlowIterator;
        virtual FlowIterator flowsBegin() = 0;
        virtual FlowIterator flowsEnd() = 0;
        virtual int flowsSize() = 0;

};
#endif