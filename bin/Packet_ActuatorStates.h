
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
#ifdef CF
#error
#endif
#ifdef ER
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


class PacketActuatorStates 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    std::array<ACActuatorStatesType, 8> m_States;    
    
    public:    
    Builder_(std::array<ACActuatorStatesType, 8> StatesIn)    
        : m_States(StatesIn)    
    {}    
    
    Builder_() {}    
    
    PacketActuatorStates build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return PacketActuatorStates(this->m_States);    
    }    
    
            
    Builder_<true> withStates(std::array<ACActuatorStatesType, 8> input) const     
    {    
        static_assert(! f0set, "Cannot set field 'States', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    std::array<ACActuatorStatesType, 8> m_States;

    uint8_t id = 2;

    PacketActuatorStates(std::array<ACActuatorStatesType, 8> StatesIn)
        : m_States(StatesIn)
    {}
};

