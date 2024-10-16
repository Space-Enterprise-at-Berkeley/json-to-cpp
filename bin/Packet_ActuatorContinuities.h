
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


class PacketActuatorContinuities 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    std::array<float, 8> m_Continuities;    
    
    public:    
    Builder_(std::array<float, 8> ContinuitiesIn)    
        : m_Continuities(ContinuitiesIn)    
    {}    
    
    Builder_() {}    
    
    PacketActuatorContinuities build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return PacketActuatorContinuities(this->m_Continuities);    
    }    
    
            
    Builder_<true> withContinuities(std::array<float, 8> input) const     
    {    
        static_assert(! f0set, "Cannot set field 'Continuities', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    std::array<float, 8> m_Continuities;

    uint8_t id = 3;

    PacketActuatorContinuities(std::array<float, 8> ContinuitiesIn)
        : m_Continuities(ContinuitiesIn)
    {}
};

