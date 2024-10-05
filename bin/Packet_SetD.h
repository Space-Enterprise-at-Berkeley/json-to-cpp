
#pragma once

#include "common.h"

class SetD 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    float m_Value;    
    
    public:    
    Builder_(float ValueIn)    
        : m_Value(ValueIn)    
    {}    
    
    Builder_() {}    
    
    SetD build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return SetD(this->m_Value);    
    }    
    
            
    Builder_<true> withValue(float input) const     
    {    
        static_assert(! f0set, "Cannot set field 'Value', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    float m_Value;

    uint8_t id = 208;

    SetD(float ValueIn)
        : m_Value(ValueIn)
    {}
};

