#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <vector>

#include "System.hpp"
#include "Flow.hpp"

using namespace std;
/**
 * \brief Represents the simulation model.
 *
 * Model will keep track of all the Systems and Flows added to it.
 * We can add, remove and update Systems and Flows.
 * We also run simulations based on the startTime and endTime.
*/
class Model{


    protected:
        string name; /*!< A string for naming the Model. */
        vector<System*> systems; /*!< A container for manteining the Systems references. */
        vector<Flow*> flows; /*!< A container for manteining the Flows references. */

    public:
         /**
         * @brief Creates a Model.
         *
         * Creates a new Model. Is overloaded with a default value for name.
         * Can also accept a string as a parameter.
         * 
         * When not passing the name, the default name string will be empty.
         * 
         *
         * @param name A string for naming the Model.
        */
        Model(string="");


        /**
         * @brief Destructor
         * 
         * 
         * A virtual destructor;
        */
        virtual ~Model();



//---------------------------------getters e setters---------------------------------


        /**
         * @brief Get the name field on Flow.
         * 
         * 
         * 
         * @return return a const string containing the Model @ref #name.
        */

        const string getName() const;
        /**
         * @brief Set a new @ref #name for the Model.
         * 
         * Will set a new name based on the string passed as a param. 
         * 
         * @return return true if sucefully setted the new name, and false if it failed.
        */
        bool setName(string);

//---------------------------------CRUD METHODS---------------------------------



        /**
         * @brief Add a System pointer to the @ref #systems container.
         * 
         * 
         * 
         * @return return true if sucefully added the System, and false if it failed.
        */
        bool add(System*); //????Pode melhorar depois com o jeito de verificar se foi adicionado no container.
        
        
        /**
         * @brief Add a Flow pointer to the @ref #flows container.
         * 
         * 
         * 
         * @return return true if sucefully added the System, and false if it failed.
        */
        bool add(Flow*);

        /**
         * @brief Remove a System pointer from the @ref #systems container.
         * 
         * Uses a system pointer as a parameter for removing the System.
         * 
         * @param system* The System pointer which we will compare to our list element to remove.
         * 
         * @return return true if sucefully removed the System, and false if it failed.
        */
        bool removeSystem(System* system);

        /**
         * @brief Remove a System pointer from the @ref systems container.
         * 
         * Uses a system name as a parameter for removing the System.
         * 
         * @param name A string for naming the Model.
         * 
         * @return return true if sucefully removed the System, and false if it failed.
        */
        bool removeSystem(string name);



        /**
         * @brief Remove a Flow pointer from the @ref #flows container.
         * 
         * Uses a Flow pointer as a parameter for removing the System.
         * 
         * @param flow* The Flow pointer which we will compare to our list element to remove.
         * 
         * @return return true if sucefully removed the Flow, and false if it failed.
        */
        bool removeFlow(Flow* flow);
        
        
        /**
         * @brief Remove a Flow pointer from the @ref flows container.
         * 
         * Uses a name as a parameter for removing the System.
         * 
         * @param name A string for naming the Model.
         * 
         * @return return true if sucefully removed the Flow, and false if it failed.
        */
        bool removeFlow(string name);


        /**
         * @brief Update a System pointer from the systems container.
         * 
         * Uses a name as a parameter for identifying the System which will be updated on the container.
         * Also receives a System pointer as a param which will substitute the System identified with the name. 
         * 
         * @param name A string for naming the Model.
         * @param system The system which we will update the element on our list.
         * 
         * @return return true if sucefully update the System, and false if it failed.
        */
        bool update(string name, System* system);

        /**
         * @brief Update a Flow pointer from the flows container.
         * 
         * Uses a name as a parameter for identifying the Flow which will be updated on the container.
         * Also receives a Flow pointer as a param which will substitute the Flow identified with the name. 
         * 
         * @param name A string for naming the Model.
         * @param flow* The Flow pointer which we will compare to our list element to remove.
         * 
         * @return return true if sucefully update the Flow, and false if it failed.
        */
        bool update(string name, Flow* flow);


        /**
         * @brief Run the simulation.
         * 
         * Will run the simulation based on the startTime and endTime
         * 
         * @param startTime start time of the simulation, based on seconds.
         * @param endTime end time of the simulation, based on seconds.
         * 
         * @return return true if sucefully ran the simulation, and false if it failed.
        */
        bool run(int startTime, int endTime);


        /**
         * @brief New iterator type for the System container.
         * 
         * A new iterator type for our System container, which will be used
         * for iterating over our container while encapsulating its implementation.
         * 
        */
        typedef vector<System*>::iterator SystemIterator;

        /**
         * @brief Return a iterator to the first System in the container.
         * 
         * 
         * @return return SystemIterator type, which is defined as an iterator for the System container.
        */
        SystemIterator systemsBegin();


        /**
         * @brief Returns an iterator referring to the past-the-end element in the systems container.
         * 
         * 
         * @return return SystemIterator type, which is defined as an iterator for the System container.
        */
        SystemIterator systemsEnd();


        /**
         * @brief Function for getting the size of the systems container.
         * 
         * @return returns the number of elements in the systems container.
        */
        int systemsSize();


        /**
         * @brief New iterator type for the Flow container.
         * 
         * A new iterator type for our Flow container, which will be used
         * for iterating over our container while encapsulating its implementation.
         * 
        */
        typedef vector<Flow*>::iterator FlowIterator;


        /**
         * @brief Return a iterator to the first Flow in the container.
         * 
         * 
         * @return return FlowIterator type, which is defined as an iterator for the System container.
        */
        FlowIterator flowsBegin();


        /**
         * @brief Returns an iterator referring to the past-the-end element in the flows container.
         * 
         * 
         * @return return FlowIterator type, which is defined as an iterator for the flows container.
        */
        FlowIterator flowsEnd();


        /**
         * @brief Function for getting the size of the flows container.
         * 
         * @return returns the number of elements in the @ref #flows container.
        */
        int flowsSize();


    private:
        /**
         * @brief Copy constructor
         * 
         * 
         * Copy constructor takes a reference to Model as an argument.
         * 
         * It is a private method because as we have a container with a pointer to Flows and Systems 
         * we can cause problems on the long run of the API because a copy of a model can interfere with 
         * another existing model. So to prevent the API user to make a copy we need to "hide" the method.
         * @param model& The model reference which will be assigned to the Model being called.
        */
        Model(const Model& model);
    
        /**
         * @brief Overload for = operator.
         * 
         * This is an overload for = operator, in the format of a = b, in which a is being assigned as b.
         * This will make a deep copy of both containers( @ref #flows and @ref #systems) .
         * 
         * It is a private method because as we have a container with a pointer to Flows and Systems 
         * we can cause problems on the long run of the API because a copy of a model can interfere with 
         * another existing model. So to prevent the API user to make a copy we need to "hide" the method.
         * 
         * @return return a Model reference which is a copy to the assigned Model.
        */
        Model& operator= (const Model&);



};


#endif