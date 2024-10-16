
#pragma once

#include "common.h"

#ifdef PT
#error
#endif
#ifdef TC
#error
#endif
#ifdef LC
#error
#endif
#ifdef AC
#error
#endif
#ifdef GD
#error
#endif
#ifdef CF
#error
#endif
#ifdef ER
#error
#endif
#ifdef AC_2
#error
#endif
#ifdef AC_3
#error
#endif
#ifdef AC_1
#error
#endif


class PacketAbort 
{
public:

         
template<bool f0set, bool f1set>    
class Builder_    
{    
    private:    
    SystemMode m_SystemMode;    
    ErrorCodes m_AbortReason;    
    
    public:    
    Builder_(SystemMode SystemModeIn, ErrorCodes AbortReasonIn)    
        : m_SystemMode(SystemModeIn), m_AbortReason(AbortReasonIn)    
    {}    
    
    Builder_() {}    
    
    PacketAbort build() const    
    {            
        static_assert( f0set &&  f1set, "All fields must be set before building."); // Added static assert    
        return PacketAbort(this->m_SystemMode, this->m_AbortReason);    
    }    
    
            
    Builder_<true, f1set> withSystemMode(SystemMode input) const     
    {    
        static_assert(! f0set, "Cannot set field 'SystemMode', it is already set");    
        return Builder_<true, f1set>(input, this->m_AbortReason);    
    }    
    
            
    Builder_<f0set, true> withAbortReason(ErrorCodes input) const     
    {    
        static_assert(! f1set, "Cannot set field 'AbortReason', it is already set");    
        return Builder_<f0set, true>(this->m_SystemMode, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false>;

private:
    SystemMode m_SystemMode;
    ErrorCodes m_AbortReason;

    uint8_t id = 133;

    PacketAbort(SystemMode SystemModeIn, ErrorCodes AbortReasonIn)
        : m_SystemMode(SystemModeIn), m_AbortReason(AbortReasonIn)
    {}
};

