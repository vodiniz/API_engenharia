#ifndef UNIT_HANDLE_BODY_HPP_
#define UNIT_HANDLE_BODY_HPP_

#include "../../src/Model.hpp"
#include "../../src/SystemHandle.hpp"
#include "../../src/FlowBody.hpp"

#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <math.h>



void unit_test_handle_body();


/**
 * \brief Represents a Flow with Exponential behavior.
 *
 * This class is a child from Flow and is implemented for testing puporses,
 * in which we have a exponential behavior, a specific behavior that is not
 * implemented, so we redefined the equation
*/
class ExponentialFlow : public FlowBody {
    //Construtor e Destrutor
    public:
        using FlowBody::operator=;
        /**
         * \brief Creates a ExponentialFlow.
         *
         * Creates a new ExponentialFlow. Is overloaded with a default constructor.
         * Can also accept a string as a parameter.
         * 
         * When not passing the name, the default name string will be empty.
         * 
         * @param name
        */
        ExponentialFlow(string name=""):
            FlowBody(name){}
            
        /**
         * \brief Creates a ExponentialFlow.
         *
         * This overloaded constructor acepts tree parameters, the name, a source and a target.
         * 
         * @param name
         * @param source
         * @param target
        */
        ExponentialFlow(string name, System *source, System *target): 
            FlowBody(name, source, target){}
        

        /**
         * @brief A pure virtual equation method which defines the ExponentialFlow behavior.
         * 
         * The equation method will define the mathematical relation beetwen the source and target Systems
         * 
         * The behavior defined is of an exponential 
         * 
         * @return return a double which is defined by 0.01 * source value, or 1% of the source energy.
        */
        double equation(){
            return 0.01 * getSource()->getValue();
        }
};



/**
 * \brief Represents a Flow with Exponential behavior.
 *
 * This class is a child from Flow and is implemented for testing puporses,
 * in which we have a logistic behavior, a specific behavior that is not
 * implemented, so we redefined the equation
*/
class LogisticFlow : public FlowBody {
    //Construtor e Destrutor
    public:
        using FlowBody::operator=;


        /**
         * \brief Creates a LogisticFlow.
         *
         * Creates a new LogisticFlow. Is overloaded with a default constructor.
         * Can also accept a string as a parameter.
         * 
         * When not passing the name, the default name string will be empty.
         * 
         * @param name
        */
        LogisticFlow(string name=""):
            FlowBody(name){}
            

        /**
         * \brief Creates a LogisticFlow.
         *
         * This overloaded constructor acepts tree parameters, the name, a source and a target.
         * 
         * @param name
         * @param source
         * @param target
        */
        LogisticFlow(string name, System *source, System *target): 
            FlowBody(name, source, target){}
        

        /**
         * @brief A pure virtual equation method which defines the LogisticFlow behavior.
         * 
         * The equation method will define the mathematical relation beetwen the source and target Systems
         * 
         * The behavior defined is of an Logistic 
         * 
         * @return return a double 0.01 * targetValue * ( 1 - targetValue)/70.0)).
        */
        double equation(){
            return 0.01 * getTarget()->getValue() * (1 - (getTarget()->getValue()/70.0));
        }
};



#endif