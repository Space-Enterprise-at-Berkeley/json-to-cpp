
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


class PacketZeroChannel 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    uint8_t m_Channel;    
    
    public:    
    Builder_(uint8_t ChannelIn)    
        : m_Channel(ChannelIn)    
    {}    
    
    Builder_() {}    
    
    PacketZeroChannel build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return PacketZeroChannel(this->m_Channel);    
    }    
    
            
    Builder_<true> withChannel(uint8_t input) const     
    {    
        static_assert(! f0set, "Cannot set field 'Channel', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    uint8_t m_Channel;

    uint8_t id = 100;

    PacketZeroChannel(uint8_t ChannelIn)
        : m_Channel(ChannelIn)
    {}
};

