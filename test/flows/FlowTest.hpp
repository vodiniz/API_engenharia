#ifndef FLOW_TEST_HPP
#define FLOW_TEST_HPP

#include "../../src/FlowBody.hpp"

class FlowTest : public FlowBody {
    //Construtor e Destrutor
    public:
        using FlowBody::operator=;
        
        FlowTest(){}

        FlowTest(string name):
            FlowBody(name){}
            
        FlowTest(string name, System *source, System *target): 
            FlowBody(name, source, target){}

        FlowTest(Flow& flow): FlowBody(flow){}
            
        double equation(){
            return (getSource()->getValue())/2;
        }
    
};

#endif