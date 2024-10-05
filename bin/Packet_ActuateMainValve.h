
#pragma once

#include "common.h"

class ActuateMainValve 
{
public:

         
    
class Builder_    
{    
    private:    
        
    
    public:    
    Builder_()    
            
    {}    
    
    Builder_() {}    
    
    ActuateMainValve build() const    
    {            
        //static_assert(, "All fields must be set before building."); // Added static assert    
        return ActuateMainValve();    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_;

private:
    

    uint8_t id = 210;

    ActuateMainValve()
        
    {}
};

