
#pragma once

#include "common.h"

class LimitSwitch 
{
public:

         
template<bool f0set, bool f1set>    
class Builder_    
{    
    private:    
    float m_FullyClosedSwitch;    
    float m_FullyOpenSwitch;    
    
    public:    
    Builder_(float FullyClosedSwitchIn, float FullyOpenSwitchIn)    
        : m_FullyClosedSwitch(FullyClosedSwitchIn), m_FullyOpenSwitch(FullyOpenSwitchIn)    
    {}    
    
    Builder_() {}    
    
    LimitSwitch build() const    
    {            
        static_assert( f0set &&  f1set, "All fields must be set before building."); // Added static assert    
        return LimitSwitch(this->m_FullyClosedSwitch, this->m_FullyOpenSwitch);    
    }    
    
            
    Builder_<true, f1set> withFullyClosedSwitch(float input) const     
    {    
        static_assert(! f0set, "Cannot set field 'FullyClosedSwitch', it is already set");    
        return Builder_<true, f1set>(input, this->m_FullyOpenSwitch);    
    }    
    
            
    Builder_<f0set, true> withFullyOpenSwitch(float input) const     
    {    
        static_assert(! f1set, "Cannot set field 'FullyOpenSwitch', it is already set");    
        return Builder_<f0set, true>(this->m_FullyClosedSwitch, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false>;

private:
    float m_FullyClosedSwitch;
    float m_FullyOpenSwitch;

    uint8_t id = 7;

    LimitSwitch(float FullyClosedSwitchIn, float FullyOpenSwitchIn)
        : m_FullyClosedSwitch(FullyClosedSwitchIn), m_FullyOpenSwitch(FullyOpenSwitchIn)
    {}
};

