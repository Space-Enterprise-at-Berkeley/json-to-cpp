
#pragma once

#include "common.h"

class Temperatures 
{
public:

         
template<bool f0set, bool f1set, bool f2set>    
class Builder_    
{    
    private:    
    float m_BoardTemp1;    
    float m_BoardTemp2;    
    float m_MotorTemp;    
    
    public:    
    Builder_(float BoardTemp1In, float BoardTemp2In, float MotorTempIn)    
        : m_BoardTemp1(BoardTemp1In), m_BoardTemp2(BoardTemp2In), m_MotorTemp(MotorTempIn)    
    {}    
    
    Builder_() {}    
    
    Temperatures build() const    
    {            
        static_assert( f0set &&  f1set &&  f2set, "All fields must be set before building."); // Added static assert    
        return Temperatures(this->m_BoardTemp1, this->m_BoardTemp2, this->m_MotorTemp);    
    }    
    
            
    Builder_<true, f1set, f2set> withBoardTemp1(float input) const     
    {    
        static_assert(! f0set, "Cannot set field 'BoardTemp1', it is already set");    
        return Builder_<true, f1set, f2set>(input, this->m_BoardTemp2, this->m_MotorTemp);    
    }    
    
            
    Builder_<f0set, true, f2set> withBoardTemp2(float input) const     
    {    
        static_assert(! f1set, "Cannot set field 'BoardTemp2', it is already set");    
        return Builder_<f0set, true, f2set>(this->m_BoardTemp1, input, this->m_MotorTemp);    
    }    
    
            
    Builder_<f0set, f1set, true> withMotorTemp(float input) const     
    {    
        static_assert(! f2set, "Cannot set field 'MotorTemp', it is already set");    
        return Builder_<f0set, f1set, true>(this->m_BoardTemp1, this->m_BoardTemp2, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false, false>;

private:
    float m_BoardTemp1;
    float m_BoardTemp2;
    float m_MotorTemp;

    uint8_t id = 9;

    Temperatures(float BoardTemp1In, float BoardTemp2In, float MotorTempIn)
        : m_BoardTemp1(BoardTemp1In), m_BoardTemp2(BoardTemp2In), m_MotorTemp(MotorTempIn)
    {}
};

