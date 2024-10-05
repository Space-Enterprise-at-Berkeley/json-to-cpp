
#pragma once

#include "common.h"

class FlowState 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    uint8_t m_FlowState;    
    
    public:    
    Builder_(uint8_t FlowStateIn)    
        : m_FlowState(FlowStateIn)    
    {}    
    
    Builder_() {}    
    
    FlowState build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return FlowState(this->m_FlowState);    
    }    
    
            
    Builder_<true> withFlowState(uint8_t input) const     
    {    
        static_assert(! f0set, "Cannot set field 'FlowState', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    uint8_t m_FlowState;

    uint8_t id = 6;

    FlowState(uint8_t FlowStateIn)
        : m_FlowState(FlowStateIn)
    {}
};

