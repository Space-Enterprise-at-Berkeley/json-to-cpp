
#pragma once

#include "common.h"

class AutomationInfo 
{
public:

         
template<bool f0set, bool f1set>    
class Builder_    
{    
    private:    
    uint8_t m_AutomationState;    
    float m_FillDp;    
    
    public:    
    Builder_(uint8_t AutomationStateIn, float FillDpIn)    
        : m_AutomationState(AutomationStateIn), m_FillDp(FillDpIn)    
    {}    
    
    Builder_() {}    
    
    AutomationInfo build() const    
    {            
        static_assert( f0set &&  f1set, "All fields must be set before building."); // Added static assert    
        return AutomationInfo(this->m_AutomationState, this->m_FillDp);    
    }    
    
            
    Builder_<true, f1set> withAutomationState(uint8_t input) const     
    {    
        static_assert(! f0set, "Cannot set field 'AutomationState', it is already set");    
        return Builder_<true, f1set>(input, this->m_FillDp);    
    }    
    
            
    Builder_<f0set, true> withFillDp(float input) const     
    {    
        static_assert(! f1set, "Cannot set field 'FillDp', it is already set");    
        return Builder_<f0set, true>(this->m_AutomationState, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false>;

private:
    uint8_t m_AutomationState;
    float m_FillDp;

    uint8_t id = 7;

    AutomationInfo(uint8_t AutomationStateIn, float FillDpIn)
        : m_AutomationState(AutomationStateIn), m_FillDp(FillDpIn)
    {}
};

