#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <iostream>
#include <vector>

#include "System.hpp"
#include "Flow.hpp"
#include "FlowHandle.hpp"


/**
 *\brief Model interface, which will hide the implementation of methods.
 * 
 * Creating this interface will enable us to hide the API implementation from another functions
 * and will permit us to create a layered approach for the API. 
*/
class Model{

    protected:
        /**
         * @brief Virtual method to add a Flow pointer to the @ref #flows container.
         * 
         * @return return true if sucefully added the System, and false if it failed.
        */
        virtual bool add(Flow*) = 0;

        /**
         * @brief Virtual method to add a System pointer to the @ref #systems container.
         * 
         * @return return true if sucefully added the System, and false if it failed.
        */
        virtual bool add(System*) = 0;

        /**
         * @brief Virtual method to add a model pointer to the @ref #models container.
         * 
         * @return return true if sucefully added the System, and false if it failed.
        */
        static bool add(Model* model);



    public: 

        /**
         * @brief Destructor
         * 
         * A virtual destructor;
        */
        virtual ~Model() {};

        /**
         * @brief Virtual method to get the Name field on Model.
         * 
         * @return return a const string containing the Model name.
        */
        virtual const string getName() const = 0;

        /**
         * @brief Virtual method to set a new name for the Model.
         * 
         * Will set a new name based on the string passed as a param. 
         * @param name A string representing the name of the Model.
         * @return return true if sucefully setted the new name, and false if it failed.
        */
        virtual bool setName(string) = 0;

        /**
         * @brief Virtual method to get the current clock.
         * 
         * The clock will represent the how many iterations we had in our simulation. 
         * @return return a integer with the clock value.
        */
        virtual const int getClock() const = 0;
        

        /**
         * @brief Virtual method to remove a System pointer from the @ref #systems container.
         * 
         * Uses a system pointer as a parameter for removing the System.
         * 
         * @param system* The System pointer which we will compare to our list element to remove.
         * 
         * @return return true if sucefully removed the System, and false if it failed.
        */
        virtual bool removeSystem(System* system) = 0;


        /**
         * @brief Virtual method to remove a System pointer from the @ref systems container.
         * 
         * Uses a system name as a parameter for removing the System.
         * 
         * @param name A string for naming the Model.
         * 
         * @return return true if sucefully removed the System, and false if it failed.
        */
        virtual bool removeSystem(string name) = 0;

        
        /**
         * @brief Virtual method to update a System pointer from the systems container.
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
        virtual bool updateSystem(string currentName, double value, string newName = "") = 0;



        /**
         * @brief Virtual method to remove a Flow pointer from the @ref #flows container.
         * 
         * Uses a Flow pointer as a parameter for removing the System.
         * 
         * @param flow* The Flow pointer which we will compare to our list element to remove.
         * 
         * @return return true if sucefully removed the Flow, and false if it failed.
        */
        virtual bool removeFlow(Flow* flow) = 0;

        /**
         * @brief Virtual method to remove a Flow pointer from the @ref flows container.
         * 
         * Uses a name as a parameter for removing the System.
         * 
         * @param name A string for naming the Model.
         * 
         * @return return true if sucefully removed the Flow, and false if it failed.
        */
        virtual bool removeFlow(string name) = 0;

        /**
         * @brief Virtual method to update a Flow pointer from the flows container.
         * 
         * Uses a name as a parameter for identifying the Flow which will be updated on the container.
         * Also receives a Flow pointer as a param which will substitute the Flow identified with the name. 
         * 
         * @param currrentName A string for identifying the Flow.
         * @param source Pointer the new source for the flow.
         * @param target Pointer the new target for the flow.
         * @param newName The new Name for the flow which we will update.
         * 
         * @return return true if sucefully update the Flow, and false if it failed.
        */
        virtual bool updateFlow(string currentName,System* source, System* target, string newName = "") = 0;


        /**
         * @brief Virtual method to run the simulation.
         * 
         * Will run the simulation based on the startTime and endTime
         * 
         * @param startTime start time of the simulation, based on seconds.
         * @param endTime end time of the simulation, based on seconds.
         * 
         * @return return true if sucefully ran the simulation, and false if it failed.
        */
        virtual bool run(int startTime, int endTime) = 0;




        /**
         * @brief New iterator type for the System container.
         * 
         * A new iterator type for our System container, which will be used
         * for iterating over our container while encapsulating its implementation.
         * 
        */

        typedef vector<System*>::iterator SystemIterator;


        /**
         * @brief Virtual method which return a iterator to the first System in the container.
         * 
         * @return return SystemIterator type, which is defined as an iterator for the System container.
        */
        virtual SystemIterator systemsBegin() = 0;

        /**
         * @brief Virtual method which returns an iterator referring to the past-the-end element in the systems container.
         * 
         * @return return SystemIterator type, which is defined as an iterator for the System container.
        */
        virtual SystemIterator systemsEnd() = 0;

        /**
         * @brief Virtual method for getting the size of the systems container.
         * 
         * @return returns the number of elements in the systems container.
        */
        virtual int systemsSize() = 0;
        
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
         * @return return FlowIterator type, which is defined as an iterator for the System container.
        */
        virtual FlowIterator flowsBegin() = 0;
        

        /**
         * @brief Returns an iterator referring to the past-the-end element in the flows container.
         * 
         * @return return FlowIterator type, which is defined as an iterator for the flows container.
        */
        virtual FlowIterator flowsEnd() = 0;

        /**
         * @brief Function for getting the size of the flows container.
         * 
         * @return returns the number of elements in the @ref #flows container.
        */
        virtual int flowsSize() = 0;


        /**
         * @brief New iterator type for the Model container.
         * 
         * A new iterator type for our Model container, which will be used
         * for iterating over our container while encapsulating its implementation.
         * 
        */
        typedef vector<Model*>::iterator ModelIterator;

      /**
         * @brief Virtual method which return a iterator to the first Model in the container.
         * 
         * @return return ModelIterator type, which is defined as an iterator for the Model container.
        */
        virtual ModelIterator modelsBegin() = 0;

        /**
         * @brief Virtual method which returns an iterator referring to the past-the-end element in the Model container.
         * 
         * @return return ModelIterator type, which is defined as an iterator for the Model container.
        */
        virtual ModelIterator modelsEnd() = 0;

        /**
         * @brief Virtual method for getting the size of the models container.
         * 
         * @return returns the number of elements in the models container.
        */
        static int modelsSize();


        /**
         * @brief Virtual method to remove a Model pointer from the @ref models container.
         * 
         * Uses a Model pointer as a parameter for removing the System.
         * 
         * @param model A pointer to the Model.
         * 
         * @return return true if sucefully removed the Model, and false if it failed.
        */
        virtual bool removeModel(ModelIterator model)  = 0;


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
        virtual System* createSystem(string = "", double = 0.) = 0;

        /**
         * @brief Method for creating a Flow with template.
         * 
         * This method will create a Flow provided a template and add it to the @ref #flows container.
         * 
         * @param name Name for a Flow.
         * @param source Pointer to the source system.
         * @param target Pointer to the target system.
         * 
         * 
         * @return returns a pointer to the created Flow.
        */

        template <typename T>
        Flow* createFlow(string name = "", System * source = NULL, System * target = NULL){
            Flow* flow = new FlowHandle<T>(name, source, target);
            add(flow);
            return flow;
        }


};
#endif