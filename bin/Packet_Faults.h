
#pragma once

#include "common.h"

class Faults 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    std::array<uint8_t, 8> m_Faults;    
    
    public:    
    Builder_(std::array<uint8_t, 8> FaultsIn)    
        : m_Faults(FaultsIn)    
    {}    
    
    Builder_() {}    
    
    Faults build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return Faults(this->m_Faults);    
    }    
    
            
    Builder_<true> withFaults(std::array<uint8_t, 8> input) const     
    {    
        static_assert(! f0set, "Cannot set field 'Faults', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    std::array<uint8_t, 8> m_Faults;

    uint8_t id = 4;

    Faults(std::array<uint8_t, 8> FaultsIn)
        : m_Faults(FaultsIn)
    {}
};

