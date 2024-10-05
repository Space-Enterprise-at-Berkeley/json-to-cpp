
#pragma once

#include "common.h"

class MotorTelemetry 
{
public:

         
template<bool f0set, bool f1set, bool f2set, bool f3set, bool f4set, bool f5set, bool f6set, bool f7set>    
class Builder_    
{    
    private:    
    float m_EncoderAngle;    
    float m_AngleSetpoint;    
    float m_PressureSetpoint;    
    float m_MotorPower;    
    float m_PressureControlIP;    
    float m_PressureControl;    
    float m_PressureControlID;    
    float m__reserved0;    
    
    public:    
    Builder_(float EncoderAngleIn, float AngleSetpointIn, float PressureSetpointIn, float MotorPowerIn, float PressureControlIPIn, float PressureControlIn, float PressureControlIDIn, float _reserved0In)    
        : m_EncoderAngle(EncoderAngleIn), m_AngleSetpoint(AngleSetpointIn), m_PressureSetpoint(PressureSetpointIn), m_MotorPower(MotorPowerIn), m_PressureControlIP(PressureControlIPIn), m_PressureControl(PressureControlIn), m_PressureControlID(PressureControlIDIn), m__reserved0(_reserved0In)    
    {}    
    
    Builder_() {}    
    
    MotorTelemetry build() const    
    {            
        static_assert( f0set &&  f1set &&  f2set &&  f3set &&  f4set &&  f5set &&  f6set &&  f7set, "All fields must be set before building."); // Added static assert    
        return MotorTelemetry(this->m_EncoderAngle, this->m_AngleSetpoint, this->m_PressureSetpoint, this->m_MotorPower, this->m_PressureControlIP, this->m_PressureControl, this->m_PressureControlID, this->m__reserved0);    
    }    
    
            
    Builder_<true, f1set, f2set, f3set, f4set, f5set, f6set, f7set> withEncoderAngle(float input) const     
    {    
        static_assert(! f0set, "Cannot set field 'EncoderAngle', it is already set");    
        return Builder_<true, f1set, f2set, f3set, f4set, f5set, f6set, f7set>(input, this->m_AngleSetpoint, this->m_PressureSetpoint, this->m_MotorPower, this->m_PressureControlIP, this->m_PressureControl, this->m_PressureControlID, this->m__reserved0);    
    }    
    
            
    Builder_<f0set, true, f2set, f3set, f4set, f5set, f6set, f7set> withAngleSetpoint(float input) const     
    {    
        static_assert(! f1set, "Cannot set field 'AngleSetpoint', it is already set");    
        return Builder_<f0set, true, f2set, f3set, f4set, f5set, f6set, f7set>(this->m_EncoderAngle, input, this->m_PressureSetpoint, this->m_MotorPower, this->m_PressureControlIP, this->m_PressureControl, this->m_PressureControlID, this->m__reserved0);    
    }    
    
            
    Builder_<f0set, f1set, true, f3set, f4set, f5set, f6set, f7set> withPressureSetpoint(float input) const     
    {    
        static_assert(! f2set, "Cannot set field 'PressureSetpoint', it is already set");    
        return Builder_<f0set, f1set, true, f3set, f4set, f5set, f6set, f7set>(this->m_EncoderAngle, this->m_AngleSetpoint, input, this->m_MotorPower, this->m_PressureControlIP, this->m_PressureControl, this->m_PressureControlID, this->m__reserved0);    
    }    
    
            
    Builder_<f0set, f1set, f2set, true, f4set, f5set, f6set, f7set> withMotorPower(float input) const     
    {    
        static_assert(! f3set, "Cannot set field 'MotorPower', it is already set");    
        return Builder_<f0set, f1set, f2set, true, f4set, f5set, f6set, f7set>(this->m_EncoderAngle, this->m_AngleSetpoint, this->m_PressureSetpoint, input, this->m_PressureControlIP, this->m_PressureControl, this->m_PressureControlID, this->m__reserved0);    
    }    
    
            
    Builder_<f0set, f1set, f2set, f3set, true, f5set, f6set, f7set> withPressureControlIP(float input) const     
    {    
        static_assert(! f4set, "Cannot set field 'PressureControlIP', it is already set");    
        return Builder_<f0set, f1set, f2set, f3set, true, f5set, f6set, f7set>(this->m_EncoderAngle, this->m_AngleSetpoint, this->m_PressureSetpoint, this->m_MotorPower, input, this->m_PressureControl, this->m_PressureControlID, this->m__reserved0);    
    }    
    
            
    Builder_<f0set, f1set, f2set, f3set, f4set, true, f6set, f7set> withPressureControl(float input) const     
    {    
        static_assert(! f5set, "Cannot set field 'PressureControl', it is already set");    
        return Builder_<f0set, f1set, f2set, f3set, f4set, true, f6set, f7set>(this->m_EncoderAngle, this->m_AngleSetpoint, this->m_PressureSetpoint, this->m_MotorPower, this->m_PressureControlIP, input, this->m_PressureControlID, this->m__reserved0);    
    }    
    
            
    Builder_<f0set, f1set, f2set, f3set, f4set, f5set, true, f7set> withPressureControlID(float input) const     
    {    
        static_assert(! f6set, "Cannot set field 'PressureControlID', it is already set");    
        return Builder_<f0set, f1set, f2set, f3set, f4set, f5set, true, f7set>(this->m_EncoderAngle, this->m_AngleSetpoint, this->m_PressureSetpoint, this->m_MotorPower, this->m_PressureControlIP, this->m_PressureControl, input, this->m__reserved0);    
    }    
    
            
    Builder_<f0set, f1set, f2set, f3set, f4set, f5set, f6set, true> with_reserved0(float input) const     
    {    
        static_assert(! f7set, "Cannot set field '_reserved0', it is already set");    
        return Builder_<f0set, f1set, f2set, f3set, f4set, f5set, f6set, true>(this->m_EncoderAngle, this->m_AngleSetpoint, this->m_PressureSetpoint, this->m_MotorPower, this->m_PressureControlIP, this->m_PressureControl, this->m_PressureControlID, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false, false, false, false, false, false, false>;

private:
    float m_EncoderAngle;
    float m_AngleSetpoint;
    float m_PressureSetpoint;
    float m_MotorPower;
    float m_PressureControlIP;
    float m_PressureControl;
    float m_PressureControlID;
    float m__reserved0;

    uint8_t id = 2;

    MotorTelemetry(float EncoderAngleIn, float AngleSetpointIn, float PressureSetpointIn, float MotorPowerIn, float PressureControlIPIn, float PressureControlIn, float PressureControlIDIn, float _reserved0In)
        : m_EncoderAngle(EncoderAngleIn), m_AngleSetpoint(AngleSetpointIn), m_PressureSetpoint(PressureSetpointIn), m_MotorPower(MotorPowerIn), m_PressureControlIP(PressureControlIPIn), m_PressureControl(PressureControlIn), m_PressureControlID(PressureControlIDIn), m__reserved0(_reserved0In)
    {}
};

