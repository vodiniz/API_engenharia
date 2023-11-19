#ifndef _FUNCTIONAL_TESTS_H_
#define _FUNCTIONAL_TESTS_H_

#include "../../src/ModelImpl.hpp"
#include "../../src/SystemImpl.hpp"
#include "../../src/FlowImpl.hpp"



using namespace std;

//???? Não precisa do construtor se parar pra pensar...

/**
 * \brief Represents a Flow with Exponential behavior.
 *
 * This class is a child from Flow and is implemented for testing puporses,
 * in which we have a exponential behavior, a specific behavior that is not
 * implemented, so we redefined the equation
*/
class ExponentialFlow : public FlowImpl {
    //Construtor e Destrutor
    public:

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
            FlowImpl(name){}
            
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
            FlowImpl(name, source, target){}
        

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
class logisticFlow : public FlowImpl {
    //Construtor e Destrutor
    public:


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
        logisticFlow(string name=""):
            FlowImpl(name){}
            

        /**
         * \brief Creates a LogisticFlow.
         *
         * This overloaded constructor acepts tree parameters, the name, a source and a target.
         * 
         * @param name
         * @param source
         * @param target
        */
        logisticFlow(string name, System *source, System *target): 
            FlowImpl(name, source, target){}
        

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



/**
 * \brief A test for verifying if the model running a exponentialTest asserts
 * 
 * Given a Model with two System, pop1 and pop2 with value of 100.0 and 0.0
 * When the Model will ran for 100 time units with one increments
 * Them we will assert the resulting value with 36.6032 and 63.3968, respectvely.
 * 
 */
void exponentialTest();

/**
 * \brief A test for verifying if the model running a logisticFlow asserts
 * 
 * Given a Model with two System, p1 and p2 with value of 100.0 and 0.0
 * When the Model will ran for 100 time units with one increments
 * Them we will assert the resulting value with 88.2167 and 21.7833, respectvely.
 * 
 */
void logisticTest();


/**
 * \brief A test for verifying if the model running a logisticFlow asserts
 * 
 * Given a Complex Model with 6 System, Q1, Q2, Q3, Q4, Q5 and Q6, with the values
 * 100.0, 0.0, 100.0, 0.0, 0.0 and 6 ExponentialFlows.
 * When the Model will ran for 100 time units with one increments
 * Them we will assert the resulting System value with 31.8513, 18.4003, 77.1143, 56.1728, 16.4612 respectvely.
 */
void complexTest();

#endif