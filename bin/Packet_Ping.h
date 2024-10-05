
#pragma once

#include "common.h"

class Ping 
{
public:

         
    
class Builder_    
{    
    private:    
        
    
    public:    
    Builder_()    
            
    {}    
    
    Builder_() {}    
    
    Ping build() const    
    {            
        //static_assert(, "All fields must be set before building."); // Added static assert    
        return Ping();    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_;

private:
    

    uint8_t id = 199;

    Ping()
        
    {}
};

