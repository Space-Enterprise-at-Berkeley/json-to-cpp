
#pragma once

#include "common.h"

class Zero 
{
public:

         
    
class Builder_    
{    
    private:    
        
    
    public:    
    Builder_()    
            
    {}    
    
    Builder_() {}    
    
    Zero build() const    
    {            
        //static_assert(, "All fields must be set before building."); // Added static assert    
        return Zero();    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_;

private:
    

    uint8_t id = 205;

    Zero()
        
    {}
};

