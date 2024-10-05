
#pragma once

#include "common.h"

class ActuatorStates 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    std::array<ACActuatorStates, 8> m_States;    
    
    public:    
    Builder_(std::array<ACActuatorStates, 8> StatesIn)    
        : m_States(StatesIn)    
    {}    
    
    Builder_() {}    
    
    ActuatorStates build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return ActuatorStates(this->m_States);    
    }    
    
            
    Builder_<true> withStates(std::array<ACActuatorStates, 8> input) const     
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
    std::array<ACActuatorStates, 8> m_States;

    uint8_t id = 2;

    ActuatorStates(std::array<ACActuatorStates, 8> StatesIn)
        : m_States(StatesIn)
    {}
};

