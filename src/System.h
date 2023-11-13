#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <iostream>

using namespace std;

/*! System class for representing stock, quantities, mass or even energy. */


/**
 * \brief Class for representing stock, quantities, mass or even energy.
 */


class System {

    protected:
        string name;  /*!< A string for naming the systems. */
        double value;  /*!< A double value for representing mass, quantities or energy. */

    public:

        /**
         * @brief Creates a new System
         * 
         * 
         * A default constructor with overloaded constructor and default value for name and value
         * @param name
         * @param value;
        */
        System(string = "", double = 0.);

        /**
         * @brief Destructor
         * 
         * 
         * A virtual destructor;
        */
        virtual ~System();

        /**
         * @brief Copy constructor
         * 
         * 
         * Copy constructor takes a reference to system as an argument.
         * @param system 
        */
        System(const System& system) ;

        //---------------------------------getters e setters---------------------------------

        /**
         * @brief Get the Name field on System.
         * 
         * 
         * 
         * @return return a const string containing the System name.
        */
        const string getName() const;

        /**
         * @brief Set a new name for the System.
         * 
         * Will set a new name based on the string passed as a param. 
         * 
         * @return return true if sucefully setted the new name, and false if it failed.
        */
        bool setName(string) ;


        /**
         * @brief Get the value field on System.
         * 
         * 
         * 
         * @return return a const double containing the System current value.
         *
         *
         */

        const double getValue() const;


        /**
         * @brief Set a new Value for the System.
         * 
         * Will set a new Value based on the double passed as a param. 
         * 
         * @return return true if sucefully setted the new Value, and false if it failed.
        */
        bool setValue(double);

        /**
         * @brief Overload for = operator.
         * 
         * This is an overload for = operator, in the format of a = b, in which a is being assigned as b.
         * 
         * @return return a System reference which is a copy to the assigned System.
        */
        System &operator= (const System&);


};


#endif