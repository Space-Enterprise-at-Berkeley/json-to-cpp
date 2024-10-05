
#pragma once

#include "common.h"

class StopFlow 
{
public:

         
    
class Builder_    
{    
    private:    
        
    
    public:    
    Builder_()    
            
    {}    
    
    Builder_() {}    
    
    StopFlow build() const    
    {            
        //static_assert(, "All fields must be set before building."); // Added static assert    
        return StopFlow();    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_;

private:
    

    uint8_t id = 201;

    StopFlow()
        
    {}
};

