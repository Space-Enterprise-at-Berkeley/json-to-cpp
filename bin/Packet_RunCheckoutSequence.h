
#pragma once

#include "common.h"

class RunCheckoutSequence 
{
public:

         
    
class Builder_    
{    
    private:    
        
    
    public:    
    Builder_()    
            
    {}    
    
    Builder_() {}    
    
    RunCheckoutSequence build() const    
    {            
        //static_assert(, "All fields must be set before building."); // Added static assert    
        return RunCheckoutSequence();    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_;

private:
    

    uint8_t id = 204;

    RunCheckoutSequence()
        
    {}
};

