
#pragma once

#include "common.h"

class Pong 
{
public:

         
    
class Builder_    
{    
    private:    
        
    
    public:    
    Builder_()    
            
    {}    
    
    Builder_() {}    
    
    Pong build() const    
    {            
        //static_assert(, "All fields must be set before building."); // Added static assert    
        return Pong();    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_;

private:
    

    uint8_t id = 99;

    Pong()
        
    {}
};

