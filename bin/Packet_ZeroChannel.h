
#pragma once

#include "common.h"

class ZeroChannel 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    float m_Channel;    
    
    public:    
    Builder_(float ChannelIn)    
        : m_Channel(ChannelIn)    
    {}    
    
    Builder_() {}    
    
    ZeroChannel build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return ZeroChannel(this->m_Channel);    
    }    
    
            
    Builder_<true> withChannel(float input) const     
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
    float m_Channel;

    uint8_t id = 101;

    ZeroChannel(float ChannelIn)
        : m_Channel(ChannelIn)
    {}
};

