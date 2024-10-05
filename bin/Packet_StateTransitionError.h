
#pragma once

#include "common.h"

class StateTransitionError 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    uint8_t m_ErrorCode;    
    
    public:    
    Builder_(uint8_t ErrorCodeIn)    
        : m_ErrorCode(ErrorCodeIn)    
    {}    
    
    Builder_() {}    
    
    StateTransitionError build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return StateTransitionError(this->m_ErrorCode);    
    }    
    
            
    Builder_<true> withErrorCode(uint8_t input) const     
    {    
        static_assert(! f0set, "Cannot set field 'ErrorCode', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    uint8_t m_ErrorCode;

    uint8_t id = 5;

    StateTransitionError(uint8_t ErrorCodeIn)
        : m_ErrorCode(ErrorCodeIn)
    {}
};

