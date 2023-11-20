#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <string>

using namespace std;

/**
 *\brief System interface, which will hide the implementation of methods.
 * 
 * Creating this interface will enable us to hide the API implementation from another functions
 * and will permit us to create a layered aproach for the API. 
 * 
*/
class System{


    public:

        /**
         * @brief Destructor
         * 
         * 
         * A virtual destructor;
        */
        virtual ~System() {};


        /**
         * @brief Virtual method to get the Name field on System.
         * 
         * @return return a const string containing the System name.
        */
        virtual const string getName() const = 0;

        /**
         * @brief Virtual method to set a new name for the System.
         * 
         * Will set a new name based on the string passed as a param. 
         * 
         * @return return true if sucefully setted the new name, and false if it failed.
        */
        virtual bool setName(string) = 0;

        /**
         * @brief Virtual method to get the value field on System.
         * 
         * @return return a const double containing the System current value.
        */
        virtual const double getValue() const = 0;

        /**
         * @brief Virtual method to set a new Value for the System.
         * 
         * Will set a new Value based on the double passed as a param. 
         * 
         * @return return true if sucefully setted the new Value, and false if it failed.
        */
        virtual bool setValue(double) = 0;

        /**
         * @brief Virtual Overload for = operator.
         * 
         * This is an overload for = operator, in the format of a = b, in which a is being assigned as b.
         * 
         * @return return a System reference which is a copy to the assigned System.
        */
        virtual System& operator=(const System& system) = 0;

};
#endif