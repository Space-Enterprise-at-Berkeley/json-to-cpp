
#pragma once

#include "common.h"

#ifdef TC
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


class PacketFirstPointCalibration 
{
public:

         
template<bool f0set, bool f1set>    
class Builder_    
{    
    private:    
    uint8_t m_Channel;    
    float m_Value;    
    
    public:    
    Builder_(uint8_t ChannelIn, float ValueIn)    
        : m_Channel(ChannelIn), m_Value(ValueIn)    
    {}    
    
    Builder_() {}    
    
    PacketFirstPointCalibration build() const    
    {            
        static_assert( f0set &&  f1set, "All fields must be set before building."); // Added static assert    
        return PacketFirstPointCalibration(this->m_Channel, this->m_Value);    
    }    
    
            
    Builder_<true, f1set> withChannel(uint8_t input) const     
    {    
        static_assert(! f0set, "Cannot set field 'Channel', it is already set");    
        return Builder_<true, f1set>(input, this->m_Value);    
    }    
    
            
    Builder_<f0set, true> withValue(float input) const     
    {    
        static_assert(! f1set, "Cannot set field 'Value', it is already set");    
        return Builder_<f0set, true>(this->m_Channel, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false>;

private:
    uint8_t m_Channel;
    float m_Value;

    uint8_t id = 100;

    PacketFirstPointCalibration(uint8_t ChannelIn, float ValueIn)
        : m_Channel(ChannelIn), m_Value(ValueIn)
    {}
};

