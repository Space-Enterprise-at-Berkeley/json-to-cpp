
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


class PacketLaunch 
{
public:

         
template<bool f0set, bool f1set, bool f2set, bool f3set>    
class Builder_    
{    
    private:    
    SystemMode m_SystemMode;    
    float m_BurnTime;    
    uint8_t m_NitrousEnable;    
    uint8_t m_IpaEnable;    
    
    public:    
    Builder_(SystemMode SystemModeIn, float BurnTimeIn, uint8_t NitrousEnableIn, uint8_t IpaEnableIn)    
        : m_SystemMode(SystemModeIn), m_BurnTime(BurnTimeIn), m_NitrousEnable(NitrousEnableIn), m_IpaEnable(IpaEnableIn)    
    {}    
    
    Builder_() {}    
    
    PacketLaunch build() const    
    {            
        static_assert( f0set &&  f1set &&  f2set &&  f3set, "All fields must be set before building."); // Added static assert    
        return PacketLaunch(this->m_SystemMode, this->m_BurnTime, this->m_NitrousEnable, this->m_IpaEnable);    
    }    
    
            
    Builder_<true, f1set, f2set, f3set> withSystemMode(SystemMode input) const     
    {    
        static_assert(! f0set, "Cannot set field 'SystemMode', it is already set");    
        return Builder_<true, f1set, f2set, f3set>(input, this->m_BurnTime, this->m_NitrousEnable, this->m_IpaEnable);    
    }    
    
            
    Builder_<f0set, true, f2set, f3set> withBurnTime(float input) const     
    {    
        static_assert(! f1set, "Cannot set field 'BurnTime', it is already set");    
        return Builder_<f0set, true, f2set, f3set>(this->m_SystemMode, input, this->m_NitrousEnable, this->m_IpaEnable);    
    }    
    
            
    Builder_<f0set, f1set, true, f3set> withNitrousEnable(uint8_t input) const     
    {    
        static_assert(! f2set, "Cannot set field 'NitrousEnable', it is already set");    
        return Builder_<f0set, f1set, true, f3set>(this->m_SystemMode, this->m_BurnTime, input, this->m_IpaEnable);    
    }    
    
            
    Builder_<f0set, f1set, f2set, true> withIpaEnable(uint8_t input) const     
    {    
        static_assert(! f3set, "Cannot set field 'IpaEnable', it is already set");    
        return Builder_<f0set, f1set, f2set, true>(this->m_SystemMode, this->m_BurnTime, this->m_NitrousEnable, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false, false, false>;

private:
    SystemMode m_SystemMode;
    float m_BurnTime;
    uint8_t m_NitrousEnable;
    uint8_t m_IpaEnable;

    uint8_t id = 149;

    PacketLaunch(SystemMode SystemModeIn, float BurnTimeIn, uint8_t NitrousEnableIn, uint8_t IpaEnableIn)
        : m_SystemMode(SystemModeIn), m_BurnTime(BurnTimeIn), m_NitrousEnable(NitrousEnableIn), m_IpaEnable(IpaEnableIn)
    {}
};

