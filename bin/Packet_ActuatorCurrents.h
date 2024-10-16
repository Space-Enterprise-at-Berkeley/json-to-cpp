
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


class PacketActuatorCurrents 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    std::array<float, 8> m_Currents;    
    
    public:    
    Builder_(std::array<float, 8> CurrentsIn)    
        : m_Currents(CurrentsIn)    
    {}    
    
    Builder_() {}    
    
    PacketActuatorCurrents build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return PacketActuatorCurrents(this->m_Currents);    
    }    
    
            
    Builder_<true> withCurrents(std::array<float, 8> input) const     
    {    
        static_assert(! f0set, "Cannot set field 'Currents', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    std::array<float, 8> m_Currents;

    uint8_t id = 4;

    PacketActuatorCurrents(std::array<float, 8> CurrentsIn)
        : m_Currents(CurrentsIn)
    {}
};

