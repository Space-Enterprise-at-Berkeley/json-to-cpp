
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


class PacketPartialOpen 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    float m_EncoderTicks;    
    
    public:    
    Builder_(float EncoderTicksIn)    
        : m_EncoderTicks(EncoderTicksIn)    
    {}    
    
    Builder_() {}    
    
    PacketPartialOpen build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return PacketPartialOpen(this->m_EncoderTicks);    
    }    
    
            
    Builder_<true> withEncoderTicks(float input) const     
    {    
        static_assert(! f0set, "Cannot set field 'EncoderTicks', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    float m_EncoderTicks;

    uint8_t id = 202;

    PacketPartialOpen(float EncoderTicksIn)
        : m_EncoderTicks(EncoderTicksIn)
    {}
};

