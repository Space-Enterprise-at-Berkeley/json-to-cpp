
#pragma once

#include "common.h"

class RequestCalibrationSettings 
{
public:

         
    
class Builder_    
{    
    private:    
        
    
    public:    
    Builder_()    
            
    {}    
    
    Builder_() {}    
    
    RequestCalibrationSettings build() const    
    {            
        //static_assert(, "All fields must be set before building."); // Added static assert    
        return RequestCalibrationSettings();    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_;

private:
    

    uint8_t id = 103;

    RequestCalibrationSettings()
        
    {}
};

