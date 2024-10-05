
#pragma once

#include "common.h"

class Ack 
{
public:

         
template<bool f0set>    
class Builder_    
{    
    private:    
    std::array<uint8_t, 40> m_ProtoVersion;    
    
    public:    
    Builder_(std::array<uint8_t, 40> ProtoVersionIn)    
        : m_ProtoVersion(ProtoVersionIn)    
    {}    
    
    Builder_() {}    
    
    Ack build() const    
    {            
        static_assert( f0set, "All fields must be set before building."); // Added static assert    
        return Ack(this->m_ProtoVersion);    
    }    
    
            
    Builder_<true> withProtoVersion(std::array<uint8_t, 40> input) const     
    {    
        static_assert(! f0set, "Cannot set field 'ProtoVersion', it is already set");    
        return Builder_<true>(input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false>;

private:
    std::array<uint8_t, 40> m_ProtoVersion;

    uint8_t id = 0;

    Ack(std::array<uint8_t, 40> ProtoVersionIn)
        : m_ProtoVersion(ProtoVersionIn)
    {}
};

