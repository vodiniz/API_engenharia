#ifndef FLOW_H_
#define FLOW_H_

#include "System.hpp"

using namespace std;


/**
 *\brief Flow interface, which will hide the implementation of methods.
 * 
 * Creating this interface will enable us to hide the API implementation from another functions
 * and will permit us to create a layered approach for the API. 
 * 
*/
class Flow{
    public:

        /**
         * @brief Destructor
         * 
         * A virtual destructor;
        */
        virtual ~Flow() {};

        /**
         * @brief Virtual method to get the Name field on Flow.
         * 
         * @return return a const string containing the Flow name.
        */
        virtual const string getName() const = 0;

        /**
         * @brief Virtual method to set a new name for the Flow.
         * 
         * Will set a new name based on the string passed as a param. 
         * @param name A string representing the name of the Flow.
         * @return return true if sucefully setted the new name, and false if it failed.
        */
        virtual bool setName(string) = 0;

        /**
         * @brief Virtual method to get the source System.
         * 
         * @return return a System pointer containing the source. If the Flow doesn't have
         * a source, a NULL value is returned. 
        */
        virtual System* getSource() const = 0;

        /**
         * @brief Virtual method to set a new source for the Flow.
         * 
         * Will set a new source based on the System pointer passed as a param. 
         * 
         * @param source A System pointer for the new source.
         * @return return true if sucefully setted the new source, and false if it failed.
        */
        virtual bool setSource(System*) = 0;

        /**
         * @brief Virtual method to get the Target System.
         * 
         * @return return a System pointer containing the Target. If the Flow doesn't have
         * a source, a NULL value is returned. 
        */
        virtual System* getTarget() const = 0;

        /**
         * @brief Virtual method to set a new target for the Flow.
         * 
         * Will set a new target based on the System pointer passed as a param. 
         * 
         * @param target A System pointer for the new target.
         * @return return true if sucefully setted the new target, and false if it failed.
        */
        virtual bool setTarget(System*) = 0;
        
        /**
         * @brief Virtual method to clear the Flow source.
         * 
         * Will set the source to NULL
         * 
         * @return return true if sucefully changed the source to NULL, and false if it failed.
        */
        virtual bool clearSource() = 0;

        /**
         * @brief Virtual method to clear the Flow target.
         * 
         * Will set the target to NULL
         * 
         * @return return true if sucefully changed the target to NULL, and false if it failed.
        */
        virtual bool clearTarget() = 0;
    

        /**
         * @brief A pure virtual equation method which defines the flow behavior.
         * 
         * The equation method will define the mathematical relation beetwen the source and target Systems
         * As we do not know the needed implementation we defined flow as an abstract class
         * Whoever is using the API will need to implement this method with the behavior they want.
         * 
         * @return return a double value defined by the implemented equation.
        */
        virtual double equation() = 0;
};


#endif