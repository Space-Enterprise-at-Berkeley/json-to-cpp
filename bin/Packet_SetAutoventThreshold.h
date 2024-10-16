
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
#ifdef ER
#error
#endif
#ifdef AC_1
#error
#endif


class PacketSetAutoventThreshold 
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
    
    PacketSetAutoventThreshold build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return PacketSetAutoventThreshold(this->m_AutoventPressure);    
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

    uint8_t id = 124;

    PacketSetAutoventThreshold(float AutoventPressureIn)
        : m_AutoventPressure(AutoventPressureIn)
    {}
};

