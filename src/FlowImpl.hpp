#ifndef FLOWIMPL_H_
#define FLOWIMPL_H_

#include "Flow.hpp"

using namespace std;

/**
 * \brief Represents a flow beetwen Systems.
 *
 * Flow will keep track of it source and target, and keeps track of the mathematical equation
 * which will define the flow from one System to another.
 */
class FlowImpl: public Flow{

    protected:
        string name; /*!< A string for naming the Flow. */
        System *source; /*!< A System pointer for the source. */
        System *target; /*!< A System pointer for the target. */

    public:

        //???? Apenas um construtor, inicializando System como NULL pode ser interessante.


        /**
         * \brief Creates a Flow.
         *
         * Creates a new Flow. Is overloaded with a default constructor.
         * Can also accept a string as a parameter.
         * 
         * When not passing the name, the default name string will be empty.
         * 
         *
         * @param name A string for naming the Flow.

        */
        FlowImpl(string=""); 


        /**
         * \brief Creates a Flow.
         *
         * This overloaded constructor acepts tree parameters, the name, a source and a target.
         * 
         * @param name A string for naming the Flow.
         * @param source A System pointer for the source*
         * @param target A System pointer for the source*
        */
        FlowImpl(string, System*, System*);


        /**
         * @brief Destructor
         * 
         * 
         * A virtual destructor;
        */
        virtual ~FlowImpl();

        /**
         * @brief Copy constructor
         * 
         * 
         * Copy constructor takes a reference to Flow as an argument.
         * @param flow& The base Flow which the copy will be based.
        */
        FlowImpl(const Flow &flow);

//---------------------------------getters e setters---------------------------------

        /**
         * @brief Get the name field on Flow.
         * 
         * 
         * 
         * @return return a const string containing the Flow name.
        */
        const string getName() const;


        /**
         * @brief Set a new name for the Flow.
         * 
         * Will set a new name based on the string passed as a param. 
         * 
         * @return return true if sucefully setted the new name, and false if it failed.
        */
        bool setName(string);

        /**
         * @brief Get the source field on Flow.
         * 
         * 
         * 
         * @return return a const System* pointing to the system which is defined as the source.
        */
        System* getSource() const;


        /**
         * @brief Set a new source for the Flow.
         * 
         * Will set a new source based on the System pointer passed as a param. 
         * 
         * @return return true if sucefully setted the new source, and false if it failed.
        */
        bool setSource(System*);


        /**
         * @brief Get the target field on Flow.
         * 
         * 
         * @return return a const System* pointing to the system which is defined as the target.
        */
        System* getTarget() const;


        /**
         * @brief Set a new target for the Flow.
         * 
         * Will set a new target based on the System pointer passed as a param. 
         * 
         * @return return true if sucefully setted the new target, and false if it failed.
        */
        bool setTarget(System*);


        /**
         * @brief Clear the pointer to the source System.
         * 
         * Will set the source pointer to NULL. 
         * 
         * @return return true if sucefully setted source to NULL, and false if it failed.
        */
        bool clearSource();


        /**
         * @brief Clear the pointer to the target System.
         * 
         * Will set the target pointer to NULL. 
         * 
         * @return return true if sucefully setted target to NULL, and false if it failed.
        */
        bool clearTarget();


        // ????será se é legal com as referências?
        /**
         * @brief Overload for = operator.
         * 
         * This is an overload for = operator, in the format of a = b, in which a is being assigned as b.
         * 
         * @return return a Flow reference which is a copy to the assigned Flow.
        */
        Flow& operator= (const Flow&);
        
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