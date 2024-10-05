
#pragma once

#include "common.h"

class ResetCalibration 
{
public:

         
    
class Builder_    
{    
    private:    
        
    
    public:    
    Builder_()    
            
    {}    
    
    Builder_() {}    
    
    ResetCalibration build() const    
    {            
        //static_assert(, "All fields must be set before building."); // Added static assert    
        return ResetCalibration();    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_;

private:
    

    uint8_t id = 104;

    ResetCalibration()
        
    {}
};

