
#pragma once

#include "common.h"

class BeginFlow 
{
public:

         
template<bool f0set, bool f1set, bool f2set, bool f3set>    
class Builder_    
{    
    private:    
    float m_SystemMode;    
    uint8_t m_BurnTime;    
    float m_NitrousEnable;    
    float m_IpaEnable;    
    
    public:    
    Builder_(float SystemModeIn, uint8_t BurnTimeIn, float NitrousEnableIn, float IpaEnableIn)    
        : m_SystemMode(SystemModeIn), m_BurnTime(BurnTimeIn), m_NitrousEnable(NitrousEnableIn), m_IpaEnable(IpaEnableIn)    
    {}    
    
    Builder_() {}    
    
    BeginFlow build() const    
    {            
        static_assert( f0set &&  f1set &&  f2set &&  f3set, "All fields must be set before building."); // Added static assert    
        return BeginFlow(this->m_SystemMode, this->m_BurnTime, this->m_NitrousEnable, this->m_IpaEnable);    
    }    
    
            
    Builder_<true, f1set, f2set, f3set> withSystemMode(float input) const     
    {    
        static_assert(! f0set, "Cannot set field 'SystemMode', it is already set");    
        return Builder_<true, f1set, f2set, f3set>(input, this->m_BurnTime, this->m_NitrousEnable, this->m_IpaEnable);    
    }    
    
            
    Builder_<f0set, true, f2set, f3set> withBurnTime(uint8_t input) const     
    {    
        static_assert(! f1set, "Cannot set field 'BurnTime', it is already set");    
        return Builder_<f0set, true, f2set, f3set>(this->m_SystemMode, input, this->m_NitrousEnable, this->m_IpaEnable);    
    }    
    
            
    Builder_<f0set, f1set, true, f3set> withNitrousEnable(float input) const     
    {    
        static_assert(! f2set, "Cannot set field 'NitrousEnable', it is already set");    
        return Builder_<f0set, f1set, true, f3set>(this->m_SystemMode, this->m_BurnTime, input, this->m_IpaEnable);    
    }    
    
            
    Builder_<f0set, f1set, f2set, true> withIpaEnable(float input) const     
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
    float m_SystemMode;
    uint8_t m_BurnTime;
    float m_NitrousEnable;
    float m_IpaEnable;

    uint8_t id = 200;

    BeginFlow(float SystemModeIn, uint8_t BurnTimeIn, float NitrousEnableIn, float IpaEnableIn)
        : m_SystemMode(SystemModeIn), m_BurnTime(BurnTimeIn), m_NitrousEnable(NitrousEnableIn), m_IpaEnable(IpaEnableIn)
    {}
};

