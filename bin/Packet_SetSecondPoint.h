
#pragma once

#include "common.h"

class SetSecondPoint 
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
    
    SetSecondPoint build() const    
    {            
        static_assert( f0set &&  f1set, "All fields must be set before building."); // Added static assert    
        return SetSecondPoint(this->m_Channel, this->m_Value);    
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

    uint8_t id = 102;

    SetSecondPoint(uint8_t ChannelIn, float ValueIn)
        : m_Channel(ChannelIn), m_Value(ValueIn)
    {}
};

