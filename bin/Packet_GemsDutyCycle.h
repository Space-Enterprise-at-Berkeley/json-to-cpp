
#pragma once

#include "common.h"

class GemsDutyCycle 
{
public:

         
    
class Builder_    
{    
    private:    
        
    
    public:    
    Builder_()    
            
    {}    
    
    Builder_() {}    
    
    GemsDutyCycle build() const    
    {            
        //static_assert(, "All fields must be set before building."); // Added static assert    
        return GemsDutyCycle();    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_;

private:
    

    uint8_t id = 8;

    GemsDutyCycle()
        
    {}
};

