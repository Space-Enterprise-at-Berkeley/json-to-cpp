
#pragma once

#include "common.h"

class Values 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    std::array<float, 8> m_Values;    
    
    public:    
    Builder_(std::array<float, 8> ValuesIn)    
        : m_Values(ValuesIn)    
    {}    
    
    Builder_() {}    
    
    Values build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return Values(this->m_Values);    
    }    
    
            
    Builder_<true> withValues(std::array<float, 8> input) const     
    {    
        static_assert(! f0set, "Cannot set field 'Values', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    std::array<float, 8> m_Values;

    uint8_t id = 2;

    Values(std::array<float, 8> ValuesIn)
        : m_Values(ValuesIn)
    {}
};

