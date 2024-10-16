
#pragma once

#include "common.h"

#ifdef TC
#error
#endif
#ifdef AC
#error
#endif
#ifdef CF
#error
#endif
#ifdef AC_2
#error
#endif
#ifdef AC_3
#error
#endif
#ifdef AC_1
#error
#endif


class PacketRequestCalibrationSettings 
{
public:

         
    
class Builder_    
{    
    private:    
        
    
    public:    
    Builder_()    
            
    {}    
    
    Builder_() {}    
    
    PacketRequestCalibrationSettings build() const    
    {            
        //static_assert(, "All fields must be set before building."); // Added static assert    
        return PacketRequestCalibrationSettings();    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_;

private:
    

    uint8_t id = 102;

    PacketRequestCalibrationSettings()
        
    {}
};

