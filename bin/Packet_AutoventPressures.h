
#pragma once

#include "common.h"

class AutoventPressures 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    float m_AutoventPressure;    
    
    public:    
    Builder_(float AutoventPressureIn)    
        : m_AutoventPressure(AutoventPressureIn)    
    {}    
    
    Builder_() {}    
    
    AutoventPressures build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return AutoventPressures(this->m_AutoventPressure);    
    }    
    
            
    Builder_<true> withAutoventPressure(float input) const     
    {    
        static_assert(! f0set, "Cannot set field 'AutoventPressure', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    float m_AutoventPressure;

    uint8_t id = 5;

    AutoventPressures(float AutoventPressureIn)
        : m_AutoventPressure(AutoventPressureIn)
    {}
};

