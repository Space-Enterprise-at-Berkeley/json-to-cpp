
#pragma once

#include "common.h"

class StaticPress 
{
public:

         
    
class Builder_    
{    
    private:    
        
    
    public:    
    Builder_()    
            
    {}    
    
    Builder_() {}    
    
    StaticPress build() const    
    {            
        //static_assert(, "All fields must be set before building."); // Added static assert    
        return StaticPress();    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_;

private:
    

    uint8_t id = 203;

    StaticPress()
        
    {}
};

