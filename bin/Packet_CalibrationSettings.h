
#pragma once

#include "common.h"

class CalibrationSettings 
{
public:

         
template<bool f0set, bool f1set, bool f2set, bool f3set>    
class Builder_    
{    
    private:    
    OffsetMultiplier m_UpstreamPt1;    
    OffsetMultiplier m_UpstreamPt2;    
    OffsetMultiplier m_DownstreamPt1;    
    OffsetMultiplier m_DownstreamPt2;    
    
    public:    
    Builder_(OffsetMultiplier UpstreamPt1In, OffsetMultiplier UpstreamPt2In, OffsetMultiplier DownstreamPt1In, OffsetMultiplier DownstreamPt2In)    
        : m_UpstreamPt1(UpstreamPt1In), m_UpstreamPt2(UpstreamPt2In), m_DownstreamPt1(DownstreamPt1In), m_DownstreamPt2(DownstreamPt2In)    
    {}    
    
    Builder_() {}    
    
    CalibrationSettings build() const    
    {            
        static_assert( f0set &&  f1set &&  f2set &&  f3set, "All fields must be set before building."); // Added static assert    
        return CalibrationSettings(this->m_UpstreamPt1, this->m_UpstreamPt2, this->m_DownstreamPt1, this->m_DownstreamPt2);    
    }    
    
            
    Builder_<true, f1set, f2set, f3set> withUpstreamPt1(OffsetMultiplier input) const     
    {    
        static_assert(! f0set, "Cannot set field 'UpstreamPt1', it is already set");    
        return Builder_<true, f1set, f2set, f3set>(input, this->m_UpstreamPt2, this->m_DownstreamPt1, this->m_DownstreamPt2);    
    }    
    
            
    Builder_<f0set, true, f2set, f3set> withUpstreamPt2(OffsetMultiplier input) const     
    {    
        static_assert(! f1set, "Cannot set field 'UpstreamPt2', it is already set");    
        return Builder_<f0set, true, f2set, f3set>(this->m_UpstreamPt1, input, this->m_DownstreamPt1, this->m_DownstreamPt2);    
    }    
    
            
    Builder_<f0set, f1set, true, f3set> withDownstreamPt1(OffsetMultiplier input) const     
    {    
        static_assert(! f2set, "Cannot set field 'DownstreamPt1', it is already set");    
        return Builder_<f0set, f1set, true, f3set>(this->m_UpstreamPt1, this->m_UpstreamPt2, input, this->m_DownstreamPt2);    
    }    
    
            
    Builder_<f0set, f1set, f2set, true> withDownstreamPt2(OffsetMultiplier input) const     
    {    
        static_assert(! f3set, "Cannot set field 'DownstreamPt2', it is already set");    
        return Builder_<f0set, f1set, f2set, true>(this->m_UpstreamPt1, this->m_UpstreamPt2, this->m_DownstreamPt1, input);    
    }    
    
            
};

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false, false, false, false>;

private:
    OffsetMultiplier m_UpstreamPt1;
    OffsetMultiplier m_UpstreamPt2;
    OffsetMultiplier m_DownstreamPt1;
    OffsetMultiplier m_DownstreamPt2;

    uint8_t id = 11;

    CalibrationSettings(OffsetMultiplier UpstreamPt1In, OffsetMultiplier UpstreamPt2In, OffsetMultiplier DownstreamPt1In, OffsetMultiplier DownstreamPt2In)
        : m_UpstreamPt1(UpstreamPt1In), m_UpstreamPt2(UpstreamPt2In), m_DownstreamPt1(DownstreamPt1In), m_DownstreamPt2(DownstreamPt2In)
    {}
};

