
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


class PacketActuateActuator 
{
public:

         
template<bool f0set, bool f1set, bool f2set>    
class Builder_    
{    
    private:    
    uint8_t m_ActuatorNumber;    
    ACActuatorActions m_Action;    
    uint32_t m_ActuateTime;    
    
    public:    
    Builder_(uint8_t ActuatorNumberIn, ACActuatorActions ActionIn, uint32_t ActuateTimeIn)    
        : m_ActuatorNumber(ActuatorNumberIn), m_Action(ActionIn), m_ActuateTime(ActuateTimeIn)    
    {}    
    
    Builder_() {}    
    
    PacketActuateActuator build() const    
    {            
        static_assert( f0set &&  f1set &&  f2set, "All fields must be set before building."); // Added static assert    
        return PacketActuateActuator(this->m_ActuatorNumber, this->m_Action, this->m_ActuateTime);    
    }    
    
            
    Builder_<true, f1set, f2set> withActuatorNumber(uint8_t input) const     
    {    
        static_assert(! f0set, "Cannot set field 'ActuatorNumber', it is already set");    
        return Builder_<true, f1set, f2set>(input, this->m_Action, this->m_ActuateTime);    
    }    
    
            
    Builder_<f0set, true, f2set> withAction(ACActuatorActions input) const     
    {    
        static_assert(! f1set, "Cannot set field 'Action', it is already set");    
        return Builder_<f0set, true, f2set>(this->m_ActuatorNumber, input, this->m_ActuateTime);    
    }    
    
            
    Builder_<f0set, f1set, true> withActuateTime(uint32_t input) const     
    {    
        static_assert(! f2set, "Cannot set field 'ActuateTime', it is already set");    
        return Builder_<f0set, f1set, true>(this->m_ActuatorNumber, this->m_Action, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false, false>;

private:
    uint8_t m_ActuatorNumber;
    ACActuatorActions m_Action;
    uint32_t m_ActuateTime;

    uint8_t id = 100;

    PacketActuateActuator(uint8_t ActuatorNumberIn, ACActuatorActions ActionIn, uint32_t ActuateTimeIn)
        : m_ActuatorNumber(ActuatorNumberIn), m_Action(ActionIn), m_ActuateTime(ActuateTimeIn)
    {}
};

