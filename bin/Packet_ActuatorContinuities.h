
#pragma once

#include "common.h"

class ActuatorContinuities 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    std::array<float, 8> m_Continuities;    
    
    public:    
    Builder_(std::array<float, 8> ContinuitiesIn)    
        : m_Continuities(ContinuitiesIn)    
    {}    
    
    Builder_() {}    
    
    ActuatorContinuities build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return ActuatorContinuities(this->m_Continuities);    
    }    
    
            
    Builder_<true> withContinuities(std::array<float, 8> input) const     
    {    
        static_assert(! f0set, "Cannot set field 'Continuities', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    std::array<float, 8> m_Continuities;

    uint8_t id = 3;

    ActuatorContinuities(std::array<float, 8> ContinuitiesIn)
        : m_Continuities(ContinuitiesIn)
    {}
};

