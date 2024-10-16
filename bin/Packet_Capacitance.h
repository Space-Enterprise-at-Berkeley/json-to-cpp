
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


class PacketCapacitance 
{
public:

         
template<bool f0set, bool f1set, bool f2set>    
class Builder_    
{    
    private:    
    float m_Cap;    
    float m_Ref;    
    float m_Temperature;    
    
    public:    
    Builder_(float CapIn, float RefIn, float TemperatureIn)    
        : m_Cap(CapIn), m_Ref(RefIn), m_Temperature(TemperatureIn)    
    {}    
    
    Builder_() {}    
    
    PacketCapacitance build() const    
    {            
        static_assert( f0set &&  f1set &&  f2set, "All fields must be set before building."); // Added static assert    
        return PacketCapacitance(this->m_Cap, this->m_Ref, this->m_Temperature);    
    }    
    
            
    Builder_<true, f1set, f2set> withCap(float input) const     
    {    
        static_assert(! f0set, "Cannot set field 'Cap', it is already set");    
        return Builder_<true, f1set, f2set>(input, this->m_Ref, this->m_Temperature);    
    }    
    
            
    Builder_<f0set, true, f2set> withRef(float input) const     
    {    
        static_assert(! f1set, "Cannot set field 'Ref', it is already set");    
        return Builder_<f0set, true, f2set>(this->m_Cap, input, this->m_Temperature);    
    }    
    
            
    Builder_<f0set, f1set, true> withTemperature(float input) const     
    {    
        static_assert(! f2set, "Cannot set field 'Temperature', it is already set");    
        return Builder_<f0set, f1set, true>(this->m_Cap, this->m_Ref, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false, false>;

private:
    float m_Cap;
    float m_Ref;
    float m_Temperature;

    uint8_t id = 1;

    PacketCapacitance(float CapIn, float RefIn, float TemperatureIn)
        : m_Cap(CapIn), m_Ref(RefIn), m_Temperature(TemperatureIn)
    {}
};

