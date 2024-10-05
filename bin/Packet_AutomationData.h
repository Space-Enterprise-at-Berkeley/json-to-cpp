
#pragma once

#include "common.h"

class AutomationData 
{
public:

         
template<bool f0set, bool f1set, bool f2set, bool f3set>    
class Builder_    
{    
    private:    
    float m_NosTank;    
    float m_NosSource;    
    float m_IpaTank;    
    float m_IpaPress;    
    
    public:    
    Builder_(float NosTankIn, float NosSourceIn, float IpaTankIn, float IpaPressIn)    
        : m_NosTank(NosTankIn), m_NosSource(NosSourceIn), m_IpaTank(IpaTankIn), m_IpaPress(IpaPressIn)    
    {}    
    
    Builder_() {}    
    
    AutomationData build() const    
    {            
        static_assert( f0set &&  f1set &&  f2set &&  f3set, "All fields must be set before building."); // Added static assert    
        return AutomationData(this->m_NosTank, this->m_NosSource, this->m_IpaTank, this->m_IpaPress);    
    }    
    
            
    Builder_<true, f1set, f2set, f3set> withNosTank(float input) const     
    {    
        static_assert(! f0set, "Cannot set field 'NosTank', it is already set");    
        return Builder_<true, f1set, f2set, f3set>(input, this->m_NosSource, this->m_IpaTank, this->m_IpaPress);    
    }    
    
            
    Builder_<f0set, true, f2set, f3set> withNosSource(float input) const     
    {    
        static_assert(! f1set, "Cannot set field 'NosSource', it is already set");    
        return Builder_<f0set, true, f2set, f3set>(this->m_NosTank, input, this->m_IpaTank, this->m_IpaPress);    
    }    
    
            
    Builder_<f0set, f1set, true, f3set> withIpaTank(float input) const     
    {    
        static_assert(! f2set, "Cannot set field 'IpaTank', it is already set");    
        return Builder_<f0set, f1set, true, f3set>(this->m_NosTank, this->m_NosSource, input, this->m_IpaPress);    
    }    
    
            
    Builder_<f0set, f1set, f2set, true> withIpaPress(float input) const     
    {    
        static_assert(! f3set, "Cannot set field 'IpaPress', it is already set");    
        return Builder_<f0set, f1set, f2set, true>(this->m_NosTank, this->m_NosSource, this->m_IpaTank, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false, false, false>;

private:
    float m_NosTank;
    float m_NosSource;
    float m_IpaTank;
    float m_IpaPress;

    uint8_t id = 4;

    AutomationData(float NosTankIn, float NosSourceIn, float IpaTankIn, float IpaPressIn)
        : m_NosTank(NosTankIn), m_NosSource(NosSourceIn), m_IpaTank(IpaTankIn), m_IpaPress(IpaPressIn)
    {}
};

