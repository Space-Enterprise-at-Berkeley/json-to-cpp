
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
#ifdef AC_2
#error
#endif
#ifdef AC_3
#error
#endif
#ifdef AC_1
#error
#endif


class PacketPhaseCurrents 
{
public:

         
template<bool f0set, bool f1set, bool f2set>    
class Builder_    
{    
    private:    
    float m_CurrentA;    
    float m_CurrentB;    
    float m_CurrentC;    
    
    public:    
    Builder_(float CurrentAIn, float CurrentBIn, float CurrentCIn)    
        : m_CurrentA(CurrentAIn), m_CurrentB(CurrentBIn), m_CurrentC(CurrentCIn)    
    {}    
    
    Builder_() {}    
    
    PacketPhaseCurrents build() const    
    {            
        static_assert( f0set &&  f1set &&  f2set, "All fields must be set before building."); // Added static assert    
        return PacketPhaseCurrents(this->m_CurrentA, this->m_CurrentB, this->m_CurrentC);    
    }    
    
            
    Builder_<true, f1set, f2set> withCurrentA(float input) const     
    {    
        static_assert(! f0set, "Cannot set field 'CurrentA', it is already set");    
        return Builder_<true, f1set, f2set>(input, this->m_CurrentB, this->m_CurrentC);    
    }    
    
            
    Builder_<f0set, true, f2set> withCurrentB(float input) const     
    {    
        static_assert(! f1set, "Cannot set field 'CurrentB', it is already set");    
        return Builder_<f0set, true, f2set>(this->m_CurrentA, input, this->m_CurrentC);    
    }    
    
            
    Builder_<f0set, f1set, true> withCurrentC(float input) const     
    {    
        static_assert(! f2set, "Cannot set field 'CurrentC', it is already set");    
        return Builder_<f0set, f1set, true>(this->m_CurrentA, this->m_CurrentB, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false, false>;

private:
    float m_CurrentA;
    float m_CurrentB;
    float m_CurrentC;

    uint8_t id = 8;

    PacketPhaseCurrents(float CurrentAIn, float CurrentBIn, float CurrentCIn)
        : m_CurrentA(CurrentAIn), m_CurrentB(CurrentBIn), m_CurrentC(CurrentCIn)
    {}
};

