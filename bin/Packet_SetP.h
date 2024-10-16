
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


class PacketSetP 
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
    
    PacketSetP build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return PacketSetP(this->m_Value);    
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

    uint8_t id = 206;

    PacketSetP(float ValueIn)
        : m_Value(ValueIn)
    {}
};

