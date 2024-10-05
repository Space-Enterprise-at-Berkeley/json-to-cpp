
#pragma once

#include "common.h"

class OvercurrentTrigger 
{
public:

         
template<bool f0set, bool f1set>    
class Builder_    
{    
    private:    
    float m_AvgCurrent;    
    float m_BufferSize;    
    
    public:    
    Builder_(float AvgCurrentIn, float BufferSizeIn)    
        : m_AvgCurrent(AvgCurrentIn), m_BufferSize(BufferSizeIn)    
    {}    
    
    Builder_() {}    
    
    OvercurrentTrigger build() const    
    {            
        static_assert( f0set &&  f1set, "All fields must be set before building."); // Added static assert    
        return OvercurrentTrigger(this->m_AvgCurrent, this->m_BufferSize);    
    }    
    
            
    Builder_<true, f1set> withAvgCurrent(float input) const     
    {    
        static_assert(! f0set, "Cannot set field 'AvgCurrent', it is already set");    
        return Builder_<true, f1set>(input, this->m_BufferSize);    
    }    
    
            
    Builder_<f0set, true> withBufferSize(float input) const     
    {    
        static_assert(! f1set, "Cannot set field 'BufferSize', it is already set");    
        return Builder_<f0set, true>(this->m_AvgCurrent, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false>;

private:
    float m_AvgCurrent;
    float m_BufferSize;

    uint8_t id = 10;

    OvercurrentTrigger(float AvgCurrentIn, float BufferSizeIn)
        : m_AvgCurrent(AvgCurrentIn), m_BufferSize(BufferSizeIn)
    {}
};

