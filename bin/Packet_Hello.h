
#pragma once

#include "common.h"

class Hello 
{
public:

         
    
class Builder_    
{    
    private:    
        
    
    public:    
    Builder_()    
            
    {}    
    
    Builder_() {}    
    
    Hello build() const    
    {            
        //static_assert(, "All fields must be set before building."); // Added static assert    
        return Hello();    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_;

private:
    

    uint8_t id = 100;

    Hello()
        
    {}
};

