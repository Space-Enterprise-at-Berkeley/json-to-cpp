
#pragma once

#include "common.h"

class PartialOpen 
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
    
    PartialOpen build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return PartialOpen(this->m_EncoderTicks);    
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

    PartialOpen(float EncoderTicksIn)
        : m_EncoderTicks(EncoderTicksIn)
    {}
};

