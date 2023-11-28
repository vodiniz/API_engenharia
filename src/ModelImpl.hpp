#ifndef MODELIMPL_H_
#define MODELIMPL_H_

#include <iostream>
#include <vector>

#include "Model.hpp"

using namespace std;
/**
 * \brief Represents the simulation model.
 *
 * Model will keep track of all the Systems and Flows added to it.
 * We can add, remove and update Systems and Flows.
 * We also run simulations based on the startTime and endTime.
*/
class ModelImpl: public Model{


    protected:
        string name; /*!< A string for naming the Model. */
        int clock = 0; /*!< A integer for keeping track of elapsed time. */
        vector<System*> systems; /*!< A container for manteining the Systems references. */
        vector<Flow*> flows; /*!< A container for manteining the Flows references. */
        static vector<Model*> models; /*!< A container for keeping a static model. */

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
        ModelImpl(string="");


        /**
         * @brief Destructor
         * 
         * 
         * A virtual destructor;
        */
        virtual ~ModelImpl();



//---------------------------------getters e setters---------------------------------


        /**
         * @brief Get the name field on Flow.
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


        /**
         * @brief Get the clock field on Flow.
         * 
         * @return return a integer with the clock value.
        */

        const int getClock() const;

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
         * @param currrentName A string for identifying the System.
         * @param value The new value for the system which we will update.
         * @param newName The new Name for the system which we will update.
         * 
         * 
         * @return return true if sucefully update the System, and false if it failed.
        */
        bool updateSystem(string currentName, double value, string newName = "");

        /**
         * @brief Update a Flow pointer from the flows container.
         * 
         * Uses a name as a parameter for identifying the Flow which will be updated on the container.
         * Also receives a Flow pointer as a param which will substitute the Flow identified with the name. 
         * 
         * @param currrentName A string for identifying the Flow.
         * @param newName The new Name for the flow which we will update.
         * @param source Pointer the new source for the flow.
         * @param target Pointer the new target for the flow.
         * 
         * @return return true if sucefully update the Flow, and false if it failed.
        */
        bool updateFlow(string currentName, System* source, System* target, string newName = "");

        /**
         * @brief Virtual method to add a model pointer to the @ref #models container.
         * 
         * @return return true if sucefully added the System, and false if it failed.
        */
        static bool add(Model*);

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
         * @brief Return a iterator to the first System in the container.
         * 
         * @return return SystemIterator type, which is defined as an iterator for the System container.
        */
        SystemIterator systemsBegin();


        /**
         * @brief Returns an iterator referring to the past-the-end element in the systems container.
         * 
         * @return return SystemIterator type, which is defined as an iterator for the System container.
        */
        SystemIterator systemsEnd();


        /**
         * @brief Method for getting the size of the systems container.
         * 
         * @return returns the number of elements in the systems container.
        */
        int systemsSize();


        /**
         * @brief Return a iterator to the first Flow in the container.
         * 
         * @return return FlowIterator type, which is defined as an iterator for the System container.
        */
        FlowIterator flowsBegin();


        /**
         * @brief Returns an iterator referring to the past-the-end element in the flows container.
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


        /**
         * @brief Virtual method which return a iterator to the first Model in the container.
         * 
         * @return return ModelIterator type, which is defined as an iterator for the Model container.
        */
        virtual ModelIterator modelsBegin();

        /**
         * @brief Virtual method which returns an iterator referring to the past-the-end element in the Model container.
         * 
         * @return return ModelIterator type, which is defined as an iterator for the Model container.
        */
        virtual ModelIterator modelsEnd();

        /**
         * @brief Virtual method for getting the size of the models container.
         * 
         * @return returns the number of elements in the models container.
        */
        static int modelsSize();


        /**
         * @brief Method for Creating a Model object.
         * 
         * @param name Name for the Model object.
         * 
         * @return Pointer to the created Model.
        */
        static Model* createModel(string name = "");


        /**
         * @brief Method for creating a System.
         * 
         * This method will create a system and add it to the @ref #systems container.
         * 
         * @param name Name for a System
         * @param value Value for the system
         * 
         * @return returns a pointer to the created System.
        */
        System* createSystem(string name = "", double value = 0.);

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
        ModelImpl(const Model& model);
    
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
        ModelImpl& operator= (const ModelImpl&);



};


#endif