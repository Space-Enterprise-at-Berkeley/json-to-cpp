
#pragma once

#include "common.h"

class PressureTelemetry 
{
public:

         
template<bool f0set, bool f1set, bool f2set, bool f3set, bool f4set, bool f5set, bool f6set, bool f7set>    
class Builder_    
{    
    private:    
    float m_FilteredUpstreamPressure1;    
    float m_FilteredUpstreamPressure2;    
    float m_FilteredDownstreamPressure1;    
    float m_FilteredDownstreamPressure2;    
    float m_RawUpstreamPressure1;    
    float m_RawUpstreamPressure2;    
    float m_RawDownstreamPressure1;    
    float m_RawDownstreamPressure2;    
    
    public:    
    Builder_(float FilteredUpstreamPressure1In, float FilteredUpstreamPressure2In, float FilteredDownstreamPressure1In, float FilteredDownstreamPressure2In, float RawUpstreamPressure1In, float RawUpstreamPressure2In, float RawDownstreamPressure1In, float RawDownstreamPressure2In)    
        : m_FilteredUpstreamPressure1(FilteredUpstreamPressure1In), m_FilteredUpstreamPressure2(FilteredUpstreamPressure2In), m_FilteredDownstreamPressure1(FilteredDownstreamPressure1In), m_FilteredDownstreamPressure2(FilteredDownstreamPressure2In), m_RawUpstreamPressure1(RawUpstreamPressure1In), m_RawUpstreamPressure2(RawUpstreamPressure2In), m_RawDownstreamPressure1(RawDownstreamPressure1In), m_RawDownstreamPressure2(RawDownstreamPressure2In)    
    {}    
    
    Builder_() {}    
    
    PressureTelemetry build() const    
    {            
        static_assert( f0set &&  f1set &&  f2set &&  f3set &&  f4set &&  f5set &&  f6set &&  f7set, "All fields must be set before building."); // Added static assert    
        return PressureTelemetry(this->m_FilteredUpstreamPressure1, this->m_FilteredUpstreamPressure2, this->m_FilteredDownstreamPressure1, this->m_FilteredDownstreamPressure2, this->m_RawUpstreamPressure1, this->m_RawUpstreamPressure2, this->m_RawDownstreamPressure1, this->m_RawDownstreamPressure2);    
    }    
    
            
    Builder_<true, f1set, f2set, f3set, f4set, f5set, f6set, f7set> withFilteredUpstreamPressure1(float input) const     
    {    
        static_assert(! f0set, "Cannot set field 'FilteredUpstreamPressure1', it is already set");    
        return Builder_<true, f1set, f2set, f3set, f4set, f5set, f6set, f7set>(input, this->m_FilteredUpstreamPressure2, this->m_FilteredDownstreamPressure1, this->m_FilteredDownstreamPressure2, this->m_RawUpstreamPressure1, this->m_RawUpstreamPressure2, this->m_RawDownstreamPressure1, this->m_RawDownstreamPressure2);    
    }    
    
            
    Builder_<f0set, true, f2set, f3set, f4set, f5set, f6set, f7set> withFilteredUpstreamPressure2(float input) const     
    {    
        static_assert(! f1set, "Cannot set field 'FilteredUpstreamPressure2', it is already set");    
        return Builder_<f0set, true, f2set, f3set, f4set, f5set, f6set, f7set>(this->m_FilteredUpstreamPressure1, input, this->m_FilteredDownstreamPressure1, this->m_FilteredDownstreamPressure2, this->m_RawUpstreamPressure1, this->m_RawUpstreamPressure2, this->m_RawDownstreamPressure1, this->m_RawDownstreamPressure2);    
    }    
    
            
    Builder_<f0set, f1set, true, f3set, f4set, f5set, f6set, f7set> withFilteredDownstreamPressure1(float input) const     
    {    
        static_assert(! f2set, "Cannot set field 'FilteredDownstreamPressure1', it is already set");    
        return Builder_<f0set, f1set, true, f3set, f4set, f5set, f6set, f7set>(this->m_FilteredUpstreamPressure1, this->m_FilteredUpstreamPressure2, input, this->m_FilteredDownstreamPressure2, this->m_RawUpstreamPressure1, this->m_RawUpstreamPressure2, this->m_RawDownstreamPressure1, this->m_RawDownstreamPressure2);    
    }    
    
            
    Builder_<f0set, f1set, f2set, true, f4set, f5set, f6set, f7set> withFilteredDownstreamPressure2(float input) const     
    {    
        static_assert(! f3set, "Cannot set field 'FilteredDownstreamPressure2', it is already set");    
        return Builder_<f0set, f1set, f2set, true, f4set, f5set, f6set, f7set>(this->m_FilteredUpstreamPressure1, this->m_FilteredUpstreamPressure2, this->m_FilteredDownstreamPressure1, input, this->m_RawUpstreamPressure1, this->m_RawUpstreamPressure2, this->m_RawDownstreamPressure1, this->m_RawDownstreamPressure2);    
    }    
    
            
    Builder_<f0set, f1set, f2set, f3set, true, f5set, f6set, f7set> withRawUpstreamPressure1(float input) const     
    {    
        static_assert(! f4set, "Cannot set field 'RawUpstreamPressure1', it is already set");    
        return Builder_<f0set, f1set, f2set, f3set, true, f5set, f6set, f7set>(this->m_FilteredUpstreamPressure1, this->m_FilteredUpstreamPressure2, this->m_FilteredDownstreamPressure1, this->m_FilteredDownstreamPressure2, input, this->m_RawUpstreamPressure2, this->m_RawDownstreamPressure1, this->m_RawDownstreamPressure2);    
    }    
    
            
    Builder_<f0set, f1set, f2set, f3set, f4set, true, f6set, f7set> withRawUpstreamPressure2(float input) const     
    {    
        static_assert(! f5set, "Cannot set field 'RawUpstreamPressure2', it is already set");    
        return Builder_<f0set, f1set, f2set, f3set, f4set, true, f6set, f7set>(this->m_FilteredUpstreamPressure1, this->m_FilteredUpstreamPressure2, this->m_FilteredDownstreamPressure1, this->m_FilteredDownstreamPressure2, this->m_RawUpstreamPressure1, input, this->m_RawDownstreamPressure1, this->m_RawDownstreamPressure2);    
    }    
    
            
    Builder_<f0set, f1set, f2set, f3set, f4set, f5set, true, f7set> withRawDownstreamPressure1(float input) const     
    {    
        static_assert(! f6set, "Cannot set field 'RawDownstreamPressure1', it is already set");    
        return Builder_<f0set, f1set, f2set, f3set, f4set, f5set, true, f7set>(this->m_FilteredUpstreamPressure1, this->m_FilteredUpstreamPressure2, this->m_FilteredDownstreamPressure1, this->m_FilteredDownstreamPressure2, this->m_RawUpstreamPressure1, this->m_RawUpstreamPressure2, input, this->m_RawDownstreamPressure2);    
    }    
    
            
    Builder_<f0set, f1set, f2set, f3set, f4set, f5set, f6set, true> withRawDownstreamPressure2(float input) const     
    {    
        static_assert(! f7set, "Cannot set field 'RawDownstreamPressure2', it is already set");    
        return Builder_<f0set, f1set, f2set, f3set, f4set, f5set, f6set, true>(this->m_FilteredUpstreamPressure1, this->m_FilteredUpstreamPressure2, this->m_FilteredDownstreamPressure1, this->m_FilteredDownstreamPressure2, this->m_RawUpstreamPressure1, this->m_RawUpstreamPressure2, this->m_RawDownstreamPressure1, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false, false, false, false, false, false, false>;

private:
    float m_FilteredUpstreamPressure1;
    float m_FilteredUpstreamPressure2;
    float m_FilteredDownstreamPressure1;
    float m_FilteredDownstreamPressure2;
    float m_RawUpstreamPressure1;
    float m_RawUpstreamPressure2;
    float m_RawDownstreamPressure1;
    float m_RawDownstreamPressure2;

    uint8_t id = 1;

    PressureTelemetry(float FilteredUpstreamPressure1In, float FilteredUpstreamPressure2In, float FilteredDownstreamPressure1In, float FilteredDownstreamPressure2In, float RawUpstreamPressure1In, float RawUpstreamPressure2In, float RawDownstreamPressure1In, float RawDownstreamPressure2In)
        : m_FilteredUpstreamPressure1(FilteredUpstreamPressure1In), m_FilteredUpstreamPressure2(FilteredUpstreamPressure2In), m_FilteredDownstreamPressure1(FilteredDownstreamPressure1In), m_FilteredDownstreamPressure2(FilteredDownstreamPressure2In), m_RawUpstreamPressure1(RawUpstreamPressure1In), m_RawUpstreamPressure2(RawUpstreamPressure2In), m_RawDownstreamPressure1(RawDownstreamPressure1In), m_RawDownstreamPressure2(RawDownstreamPressure2In)
    {}
};

