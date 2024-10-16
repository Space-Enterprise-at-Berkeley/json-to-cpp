
#pragma once

#include "common.h"

#ifdef PT
#error
#endif
#ifdef TC
#error
#endif
#ifdef LC
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


class PacketFlowState 
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
    
    PacketFlowState build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return PacketFlowState(this->m_FlowState);    
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

    PacketFlowState(uint8_t FlowStateIn)
        : m_FlowState(FlowStateIn)
    {}
};

