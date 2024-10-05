
#pragma once

#include "common.h"

class Potentiometers 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    std::array<uint16_t, 8> m_Potentiometers;    
    
    public:    
    Builder_(std::array<uint16_t, 8> PotentiometersIn)    
        : m_Potentiometers(PotentiometersIn)    
    {}    
    
    Builder_() {}    
    
    Potentiometers build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return Potentiometers(this->m_Potentiometers);    
    }    
    
            
    Builder_<true> withPotentiometers(std::array<uint16_t, 8> input) const     
    {    
        static_assert(! f0set, "Cannot set field 'Potentiometers', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    std::array<uint16_t, 8> m_Potentiometers;

    uint8_t id = 6;

    Potentiometers(std::array<uint16_t, 8> PotentiometersIn)
        : m_Potentiometers(PotentiometersIn)
    {}
};

