
#pragma once

#include "common.h"

class Diagnostic 
{
public:

         
template<bool f0set, bool f1set>    
class Builder_    
{    
    private:    
    uint8_t m_MotorDirPass;    
    uint8_t m_ServoDirPass;    
    
    public:    
    Builder_(uint8_t MotorDirPassIn, uint8_t ServoDirPassIn)    
        : m_MotorDirPass(MotorDirPassIn), m_ServoDirPass(ServoDirPassIn)    
    {}    
    
    Builder_() {}    
    
    Diagnostic build() const    
    {            
        static_assert( f0set &&  f1set, "All fields must be set before building."); // Added static assert    
        return Diagnostic(this->m_MotorDirPass, this->m_ServoDirPass);    
    }    
    
            
    Builder_<true, f1set> withMotorDirPass(uint8_t input) const     
    {    
        static_assert(! f0set, "Cannot set field 'MotorDirPass', it is already set");    
        return Builder_<true, f1set>(input, this->m_ServoDirPass);    
    }    
    
            
    Builder_<f0set, true> withServoDirPass(uint8_t input) const     
    {    
        static_assert(! f1set, "Cannot set field 'ServoDirPass', it is already set");    
        return Builder_<f0set, true>(this->m_MotorDirPass, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false>;

private:
    uint8_t m_MotorDirPass;
    uint8_t m_ServoDirPass;

    uint8_t id = 4;

    Diagnostic(uint8_t MotorDirPassIn, uint8_t ServoDirPassIn)
        : m_MotorDirPass(MotorDirPassIn), m_ServoDirPass(ServoDirPassIn)
    {}
};

