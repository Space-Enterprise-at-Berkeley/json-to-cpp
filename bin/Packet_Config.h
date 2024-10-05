
#pragma once

#include "common.h"

class Config 
{
public:

         
template<bool f0set, bool f1set, bool f2set, bool f3set, bool f4set, bool f5set, bool f6set, bool f7set>    
class Builder_    
{    
    private:    
    float m_PressureSetpointConfig;    
    float m_POuterNominal;    
    float m_IOuterNominal;    
    float m_DOuterNominal;    
    float m_PInner;    
    float m_IInner;    
    float m_DInner;    
    float m_FlowDurationSeconds;    
    
    public:    
    Builder_(float PressureSetpointConfigIn, float POuterNominalIn, float IOuterNominalIn, float DOuterNominalIn, float PInnerIn, float IInnerIn, float DInnerIn, float FlowDurationSecondsIn)    
        : m_PressureSetpointConfig(PressureSetpointConfigIn), m_POuterNominal(POuterNominalIn), m_IOuterNominal(IOuterNominalIn), m_DOuterNominal(DOuterNominalIn), m_PInner(PInnerIn), m_IInner(IInnerIn), m_DInner(DInnerIn), m_FlowDurationSeconds(FlowDurationSecondsIn)    
    {}    
    
    Builder_() {}    
    
    Config build() const    
    {            
        static_assert( f0set &&  f1set &&  f2set &&  f3set &&  f4set &&  f5set &&  f6set &&  f7set, "All fields must be set before building."); // Added static assert    
        return Config(this->m_PressureSetpointConfig, this->m_POuterNominal, this->m_IOuterNominal, this->m_DOuterNominal, this->m_PInner, this->m_IInner, this->m_DInner, this->m_FlowDurationSeconds);    
    }    
    
            
    Builder_<true, f1set, f2set, f3set, f4set, f5set, f6set, f7set> withPressureSetpointConfig(float input) const     
    {    
        static_assert(! f0set, "Cannot set field 'PressureSetpointConfig', it is already set");    
        return Builder_<true, f1set, f2set, f3set, f4set, f5set, f6set, f7set>(input, this->m_POuterNominal, this->m_IOuterNominal, this->m_DOuterNominal, this->m_PInner, this->m_IInner, this->m_DInner, this->m_FlowDurationSeconds);    
    }    
    
            
    Builder_<f0set, true, f2set, f3set, f4set, f5set, f6set, f7set> withPOuterNominal(float input) const     
    {    
        static_assert(! f1set, "Cannot set field 'POuterNominal', it is already set");    
        return Builder_<f0set, true, f2set, f3set, f4set, f5set, f6set, f7set>(this->m_PressureSetpointConfig, input, this->m_IOuterNominal, this->m_DOuterNominal, this->m_PInner, this->m_IInner, this->m_DInner, this->m_FlowDurationSeconds);    
    }    
    
            
    Builder_<f0set, f1set, true, f3set, f4set, f5set, f6set, f7set> withIOuterNominal(float input) const     
    {    
        static_assert(! f2set, "Cannot set field 'IOuterNominal', it is already set");    
        return Builder_<f0set, f1set, true, f3set, f4set, f5set, f6set, f7set>(this->m_PressureSetpointConfig, this->m_POuterNominal, input, this->m_DOuterNominal, this->m_PInner, this->m_IInner, this->m_DInner, this->m_FlowDurationSeconds);    
    }    
    
            
    Builder_<f0set, f1set, f2set, true, f4set, f5set, f6set, f7set> withDOuterNominal(float input) const     
    {    
        static_assert(! f3set, "Cannot set field 'DOuterNominal', it is already set");    
        return Builder_<f0set, f1set, f2set, true, f4set, f5set, f6set, f7set>(this->m_PressureSetpointConfig, this->m_POuterNominal, this->m_IOuterNominal, input, this->m_PInner, this->m_IInner, this->m_DInner, this->m_FlowDurationSeconds);    
    }    
    
            
    Builder_<f0set, f1set, f2set, f3set, true, f5set, f6set, f7set> withPInner(float input) const     
    {    
        static_assert(! f4set, "Cannot set field 'PInner', it is already set");    
        return Builder_<f0set, f1set, f2set, f3set, true, f5set, f6set, f7set>(this->m_PressureSetpointConfig, this->m_POuterNominal, this->m_IOuterNominal, this->m_DOuterNominal, input, this->m_IInner, this->m_DInner, this->m_FlowDurationSeconds);    
    }    
    
            
    Builder_<f0set, f1set, f2set, f3set, f4set, true, f6set, f7set> withIInner(float input) const     
    {    
        static_assert(! f5set, "Cannot set field 'IInner', it is already set");    
        return Builder_<f0set, f1set, f2set, f3set, f4set, true, f6set, f7set>(this->m_PressureSetpointConfig, this->m_POuterNominal, this->m_IOuterNominal, this->m_DOuterNominal, this->m_PInner, input, this->m_DInner, this->m_FlowDurationSeconds);    
    }    
    
            
    Builder_<f0set, f1set, f2set, f3set, f4set, f5set, true, f7set> withDInner(float input) const     
    {    
        static_assert(! f6set, "Cannot set field 'DInner', it is already set");    
        return Builder_<f0set, f1set, f2set, f3set, f4set, f5set, true, f7set>(this->m_PressureSetpointConfig, this->m_POuterNominal, this->m_IOuterNominal, this->m_DOuterNominal, this->m_PInner, this->m_IInner, input, this->m_FlowDurationSeconds);    
    }    
    
            
    Builder_<f0set, f1set, f2set, f3set, f4set, f5set, f6set, true> withFlowDurationSeconds(float input) const     
    {    
        static_assert(! f7set, "Cannot set field 'FlowDurationSeconds', it is already set");    
        return Builder_<f0set, f1set, f2set, f3set, f4set, f5set, f6set, true>(this->m_PressureSetpointConfig, this->m_POuterNominal, this->m_IOuterNominal, this->m_DOuterNominal, this->m_PInner, this->m_IInner, this->m_DInner, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false, false, false, false, false, false, false>;

private:
    float m_PressureSetpointConfig;
    float m_POuterNominal;
    float m_IOuterNominal;
    float m_DOuterNominal;
    float m_PInner;
    float m_IInner;
    float m_DInner;
    float m_FlowDurationSeconds;

    uint8_t id = 3;

    Config(float PressureSetpointConfigIn, float POuterNominalIn, float IOuterNominalIn, float DOuterNominalIn, float PInnerIn, float IInnerIn, float DInnerIn, float FlowDurationSecondsIn)
        : m_PressureSetpointConfig(PressureSetpointConfigIn), m_POuterNominal(POuterNominalIn), m_IOuterNominal(IOuterNominalIn), m_DOuterNominal(DOuterNominalIn), m_PInner(PInnerIn), m_IInner(IInnerIn), m_DInner(DInnerIn), m_FlowDurationSeconds(FlowDurationSecondsIn)
    {}
};

